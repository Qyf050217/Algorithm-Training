import os
import json
import shutil
import re
import hashlib
from datetime import datetime

# 1. 完善的平台映射 (包含 UCUP)
PLATFORM_MAP = {
    'codeforces.com': 'Codeforces',
    'nowcoder.com': 'Nowcoder',
    'luogu.com.cn': 'Luogu',
    'atcoder.jp': 'AtCoder',
    'qoj.ac': 'QOJ',
    'vjudge.net': 'Vjudge',
    'hdu.edu.cn': 'HDOJ',
    'ucup.ac': 'UCUP'  # 已增加 UCUP 映射
}

def get_cph_hash(abs_path):
    """模拟 cph 插件在 Windows 下的路径哈希"""
    path = abs_path.replace('/', '\\')
    if len(path) > 1 and path[1] == ':':
        path = path[0].lower() + path[1:]
    return hashlib.md5(path.encode('utf-8')).hexdigest()

def root_only_sync():
    root_cph = '.cph'
    if not os.path.exists(root_cph):
        print("❌ 错误：根目录下未发现 .cph 文件夹。")
        return

    workspace_root = os.getcwd()
    today = datetime.now().strftime('%Y-%m-%d')
    moved_count = 0

    # 获取根目录下所有的项
    items = os.listdir('.')

    for item in items:
        # 核心改动：仅处理根目录下的【文件】，且后缀为 .cpp
        # 这样即便你有一个名为 '2026-01-27' 的文件夹，它也会被 os.path.isfile 过滤掉
        if os.path.isfile(item) and item.endswith('.cpp'):
            file_name = item
            
            # 仅在根目录的 .cph 中寻找数据
            target_prefix = f".{file_name}"
            old_prob_name = next((f for f in os.listdir(root_cph) if f.startswith(target_prefix) and f.endswith('.prob')), None)
            
            if not old_prob_name:
                continue # 如果根目录没找到对应的 prob，说明可能已经处理过或不是 cph 题目
            
            try:
                with open(os.path.join(root_cph, old_prob_name), 'r', encoding='utf-8') as f:
                    prob_data = json.load(f)
                
                # 判定分类
                url = prob_data.get('url', '')
                platform = "Local"
                for domain, folder in PLATFORM_MAP.items():
                    if domain in url:
                        platform = folder
                        break
                if platform == "Local" and prob_data.get('group') == "HDOJ":
                    platform = "HDOJ"
                
                target_dir = os.path.join(platform, today)
                local_cph_dir = os.path.join(target_dir, '.cph')
                
                if not os.path.exists(local_cph_dir):
                    os.makedirs(local_cph_dir)

                # 计算新路径和哈希
                new_cpp_abs_path = os.path.join(workspace_root, target_dir, file_name)
                new_hash = get_cph_hash(new_cpp_abs_path)
                
                # 更新内部路径
                prob_data['srcPath'] = new_cpp_abs_path.replace('/', '\\')
                if "local" in str(prob_data.get('group', '')).lower() or "http" not in url:
                    prob_data['url'] = prob_data['srcPath']

                # 重构文件名
                new_prob_name = f".{file_name}_{new_hash}.prob"
                new_prob_path = os.path.join(local_cph_dir, new_prob_name)

                # 执行移动
                shutil.move(file_name, os.path.join(target_dir, file_name))
                with open(new_prob_path, 'w', encoding='utf-8') as f:
                    json.dump(prob_data, f, ensure_ascii=False)
                
                # 删除旧 prob
                os.remove(os.path.join(root_cph, old_prob_name))
                print(f"✅ 根目录整理完成: {file_name} -> {target_dir}")
                moved_count += 1

            except Exception as e:
                print(f"❌ 迁移 {file_name} 失败: {e}")

    if moved_count == 0:
        print("💡 根目录目前没有需要整理的新题目。")
    else:
        print(f"\n✨ 整理完成，共迁移 {moved_count} 个文件。子文件夹已安全跳过。")

if __name__ == "__main__":
    root_only_sync()