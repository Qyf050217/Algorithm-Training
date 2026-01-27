import os
import json
import shutil
import hashlib
import re
from datetime import datetime

# 获取当前脚本的绝对路径，并定位到它的上一级（即项目根目录）
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# 以后所有的路径都基于 BASE_DIR
ACCEPTED_DIR = os.path.join(BASE_DIR, 'Accepted')
ATTEMPTED_DIR = os.path.join(BASE_DIR, 'Attempted')
CSV_PATH = os.path.join(BASE_DIR, 'training_history.csv')
IMG_PATH = os.path.join(BASE_DIR, 'ac_heatmap.png')

# ANSI 颜色
RED, GREEN, YELLOW, BLUE, RESET = "\033[91m", "\033[92m", "\033[93m", "\033[94m", "\033[0m"

# 平台映射
PLATFORM_MAP = {
    'codeforces.com': 'Codeforces',
    'nowcoder.com': 'Nowcoder',
    'luogu.com.cn': 'Luogu',
    'atcoder.jp': 'AtCoder',
    'qoj.ac': 'QOJ',
    'ucup.ac': 'UCUP',
    'vjudge.net': 'Vjudge',
    'hdu.edu.cn': 'HDOJ'
}

def get_cph_hash(abs_path):
    path = abs_path.replace('/', '\\')
    if len(path) > 1 and path[1] == ':':
        path = path[0].lower() + path[1:]
    return hashlib.md5(path.encode('utf-8')).hexdigest()

def process_ac_content(filepath):
    """
    容错检查：第一行 + 倒数三行
    忽略大小写和空格匹配 // AC
    """
    status = "Attempted"
    ac_pattern = re.compile(r'//\s*A\s*C', re.IGNORECASE)
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
        if not lines: return status

        target_idx = -1
        # 1. 检查第一行
        if ac_pattern.search(lines[0]):
            target_idx = 0
        else:
            # 2. 检查倒数三行
            n = len(lines)
            for i in range(1, min(4, n + 1)):
                if ac_pattern.search(lines[n-i]):
                    target_idx = n-i
                    break

        if target_idx != -1:
            status = "AC"
            lines.pop(target_idx)
            with open(filepath, 'w', encoding='utf-8') as f:
                f.writelines(lines)
            print(f"🧹 已清理 {os.path.basename(filepath)} 的 AC 标记")
    except Exception as e:
        print(f"{RED}❌ [Error] 读写文件失败: {e}{RESET}")
    return status

def force_cleanup_probs(directory, cpp_name):
    """
    全量清理：删除目录下所有与该 cpp 相关的 .prob 文件
    """
    cph_dir = os.path.join(directory, '.cph')
    if not os.path.exists(cph_dir): return
    
    prefix = f".{cpp_name}"
    for f in os.listdir(cph_dir):
        if f.startswith(prefix) and f.endswith('.prob'):
            try:
                os.remove(os.path.join(cph_dir, f))
            except: pass

def safe_move_cph(src_cpp, dest_dir, prob_data):
    """迁移并重新生成数据"""
    try:
        if not os.path.exists(dest_dir): os.makedirs(dest_dir)
        dest_cph = os.path.join(dest_dir, '.cph')
        if not os.path.exists(dest_cph): os.makedirs(dest_cph)

        file_name = os.path.basename(src_cpp)
        # 先清理掉旧位置的所有 prob 碎屑（在移动 CPP 之前）
        force_cleanup_probs(os.path.dirname(src_cpp), file_name)

        new_cpp_abs = os.path.abspath(os.path.join(dest_dir, file_name))
        new_hash = get_cph_hash(new_cpp_abs)
        
        prob_data['srcPath'] = new_cpp_abs.replace('/', '\\')
        if "http" not in prob_data.get('url', ''): 
            prob_data['url'] = prob_data['srcPath']
        
        # 写入新 prob
        new_prob_path = os.path.join(dest_cph, f".{file_name}_{new_hash}.prob")
        with open(new_prob_path, 'w', encoding='utf-8') as f:
            json.dump(prob_data, f, ensure_ascii=False)
        
        # 移动 CPP
        shutil.move(src_cpp, os.path.join(dest_dir, file_name))
    except Exception as e:
        print(f"{RED}❌ [Error] 迁移过程出错: {e}{RESET}")
        return False

    return True

def get_platform_name(data):
    url = data.get('url', '')
    if not url or "http" not in url: return "Local"
    for domain, folder in PLATFORM_MAP.items():
        if domain in url: return folder
    return "HDOJ" if data.get('group') == "HDOJ" else "Others"

def organize():
    today = datetime.now().strftime('%Y-%m-%d')
    stats = {"total": 0, "ac": 0, "attempted": 0}
    tasks = [] 

    # 1. 扫描根目录 (当前目录为 '.')
    if os.path.exists('.cph'):
        for item in os.listdir('.'):
            if os.path.isfile(item) and item.endswith('.cpp') and item != os.path.basename(__file__):
                prob = next((f for f in os.listdir('.cph') if f.startswith(f".{item}") and f.endswith('.prob')), None)
                if prob: tasks.append((os.path.abspath(item), os.path.join('.cph', prob), "root"))

    # 2. 扫描 Attempted/平台/
    att_base = 'Attempted'
    if os.path.exists(att_base):
        for p_dir in os.listdir(att_base):
            p_path = os.path.join(att_base, p_dir)
            if os.path.isdir(p_path):
                c_sub = os.path.join(p_path, '.cph')
                if os.path.exists(c_sub):
                    for item in os.listdir(p_path):
                        if item.endswith('.cpp'):
                            prob = next((f for f in os.listdir(c_sub) if f.startswith(f".{item}") and f.endswith('.prob')), None)
                            if prob: tasks.append((os.path.abspath(os.path.join(p_path, item)), os.path.join(c_sub, prob), "attempted"))

    # 3. 执行任务
    for cpp_path, prob_path, source in tasks:
        file_name = os.path.basename(cpp_path)
        status = process_ac_content(cpp_path)
        
        with open(prob_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        platform = get_platform_name(data)

        if status == "AC":
            target = os.path.join("Accepted", platform, today)
            if safe_move_cph(cpp_path, target, data):
                print(f"✅ {YELLOW}[Accepted]{RESET} 🏆 {file_name}")
                stats["ac"] += 1; stats["total"] += 1
        elif source == "root":
            target = os.path.join(att_base, platform)
            if safe_move_cph(cpp_path, target, data):
                print(f"✅ {BLUE}[Attempted]{RESET} ⏳ {file_name}")
                stats["attempted"] += 1; stats["total"] += 1

    # 4. 递归清理空目录
    for base in ["Accepted", "Attempted"]:
        if os.path.exists(base):
            for root, dirs, files in os.walk(base, topdown=False):
                for d in dirs:
                    d_path = os.path.join(root, d)
                    if not os.listdir(d_path):
                        try: os.rmdir(d_path)
                        except: pass

    print("\n" + "·" * 40 + f"\n🚀 总结：已 AC {stats['ac']} 题 | ⏳ 新尝试 {stats['attempted']} 题\n" + "·" * 40)

if __name__ == "__main__":
    organize()