import os
import csv
import re
import json
from datetime import datetime
from collections import defaultdict

# --- 1. 路径自动定位 ---
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ACCEPTED_DIR = os.path.join(BASE_DIR, 'Accepted')
ATTEMPTED_DIR = os.path.join(BASE_DIR, 'Attempted')
LOGS_DIR = os.path.join(BASE_DIR, 'DailyLogs')
HISTORY_CSV = os.path.join(BASE_DIR, 'training_history.csv')
README_FILE = os.path.join(BASE_DIR, 'README.md')

if not os.path.exists(LOGS_DIR): os.makedirs(LOGS_DIR)

# --- 2. 配置参数 ---
TOP_N = 5

def get_oj_url(cpp_path):
    """适配 CPH 插件：从同目录下的 .cph 文件夹提取网址 [cite: 2026-01-30]"""
    cpp_filename = os.path.basename(cpp_path)
    cph_dir = os.path.join(os.path.dirname(cpp_path), '.cph')
    if os.path.exists(cph_dir) and os.path.isdir(cph_dir):
        for f in os.listdir(cph_dir):
            if f.endswith('.prob') and cpp_filename in f:
                try:
                    with open(os.path.join(cph_dir, f), 'r', encoding='utf-8') as f_in:
                        content = f_in.read()
                        url = re.search(r'https?://[^\s"\'\}]+', content)
                        if url: return url.group(0)
                except: continue
    return None

def scan_repository():
    """全量扫描仓库，返回结构化数据 [cite: 2026-01-30]"""
    daily_data = defaultdict(list)
    recent_ac_pool = []
    backlog_pool = []
    all_platforms = set()

    # 1. 扫描 Accepted (用于日志和历史统计)
    if os.path.exists(ACCEPTED_DIR):
        for root, _, files in os.walk(ACCEPTED_DIR):
            for f in files:
                if f.endswith('.cpp'):
                    path = os.path.join(root, f)
                    rel_parts = os.path.relpath(root, ACCEPTED_DIR).split(os.sep)
                    if len(rel_parts) >= 2:
                        platform, date_str = rel_parts[0], rel_parts[1]
                        all_platforms.add(platform)
                        url = get_oj_url(path)
                        mtime = os.path.getmtime(path)
                        
                        item = {
                            'name': f.replace('.cpp', ''), 'url': url, 'platform': platform,
                            'path': path, 'time': mtime, 'date': date_str
                        }
                        daily_data[date_str].append(item)
                        if url: recent_ac_pool.append(item)

    # 2. 扫描 Attempted (用于积压看板)
    if os.path.exists(ATTEMPTED_DIR):
        for root, _, files in os.walk(ATTEMPTED_DIR):
            for f in files:
                if f.endswith('.cpp'):
                    path = os.path.join(root, f)
                    rel_root = os.path.relpath(root, ATTEMPTED_DIR)
                    platform = rel_root.split(os.sep)[0] if rel_root != "." else "Other"
                    url = get_oj_url(path)
                    if url:
                        backlog_pool.append({
                            'name': f.replace('.cpp', ''), 'url': url, 'platform': platform,
                            'time': os.path.getmtime(path)
                        })

    return daily_data, recent_ac_pool, backlog_pool, sorted(list(all_platforms))

def generate_daily_logs(daily_data):
    """生成 DailyLogs 下的 MD 文件 [cite: 2026-01-30]"""
    for date_str, probs in daily_data.items():
        log_file = os.path.join(LOGS_DIR, f"{date_str}.md")
        content = [f"# 📝 训练总结: {date_str}\n\n", "| 平台 | 题目名称 | 源码跳转 |\n| :--- | :--- | :--- |\n"]
        for p in probs:
            rel_code_path = os.path.relpath(p['path'], LOGS_DIR)
            name_display = f"[{p['name']}]({p['url']})" if p['url'] else f"**{p['name']} (本地)**"
            content.append(f"| `{p['platform']}` | {name_display} | [查看代码]({rel_code_path}) |\n")
        with open(log_file, 'w', encoding='utf-8') as f:
            f.writelines(content)

def update_readme_and_csv(daily_data, recent_pool, backlog_pool, platforms):
    """更新 README 看板、带链接的历史表，并持久化 CSV [cite: 2026-01-30]"""
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    
    # 看板排序
    recent_ac = sorted(recent_pool, key=lambda x: x['time'], reverse=True)[:TOP_N]
    oldest_pending = sorted(backlog_pool, key=lambda x: x['time'], reverse=False)[:TOP_N]

    # 1. 构造 Dashboard HTML
    dashboard_html = f"""
<table width="100%">
    <tr>
        <td width="50%" valign="top">
            <h4 align="center">✅ 最近 AC ({len(recent_ac)})</h4>
            <table width="100%">
                <thead><tr><th align="center">平台</th><th align="left">题目</th><th align="right">日期</th></tr></thead>
                <tbody>
                {"".join([f"<tr><td align='center'><code>{p['platform']}</code></td><td><a href='{p['url']}'>{p['name']}</a></td><td align='right'>{datetime.fromtimestamp(p['time']).strftime('%m-%d')}</td></tr>" for p in recent_ac]) if recent_ac else "<tr><td colspan='3' align='center'>暂无记录</td></tr>"}
                </tbody>
            </table>
        </td>
        <td width="50%" valign="top">
            <h4 align="center">⌛ 积压最久 ({len(oldest_pending)})</h4>
            <table width="100%">
                <thead><tr><th align="center">平台</th><th align="left">题目</th><th align="right">日期</th></tr></thead>
                <tbody>
                {"".join([f"<tr><td align='center'><code>{p['platform']}</code></td><td><a href='{p['url']}'>{p['name']}</a></td><td align='right'>{datetime.fromtimestamp(p['time']).strftime('%m-%d')}</td></tr>" for p in oldest_pending]) if oldest_pending else "<tr><td colspan='3' align='center'>补题效率满分！</td></tr>"}
                </tbody>
            </table>
        </td>
    </tr>
</table>
"""

    # 2. 构造 README 内容
    content = [
        "# 🏆 Algorithm Training Log\n",
        f"> 🎯 **Goal:** ACM Silver Medal | *Last updated: {now}*\n\n",
        "## 📈 Heatmap\n",
        "![Algorithm Training Heatmap](ac_heatmap.png)\n\n",
        "--- \n\n",
        "## 🕒 Dashboard\n",
        dashboard_html + "\n",
        "--- \n\n",
        "## 📊 AC History\n\n"
    ]

    # 3. 构造 AC 历史表 (日期带链接) 并准备 CSV 记录
    if daily_data:
        content.append("| 日期 | " + " | ".join(platforms) + " | **Total** |\n")
        content.append("| :--- | " + " | ".join([":---:"] * len(platforms)) + " | :---: |\n")
        
        csv_rows = []
        for d in sorted(daily_data.keys(), reverse=True):
            counts = {p: len([x for x in daily_data[d] if x['platform'] == p]) for p in platforms}
            total = sum(counts.values())
            
            # README 行：日期指向 DailyLogs [cite: 2026-01-30]
            row_md = [str(counts[p]) if counts[p] > 0 else "-" for p in platforms]
            content.append(f"| [{d}](./DailyLogs/{d}.md) | " + " | ".join(row_md) + f" | **{total}** |\n")
            
            # CSV 行记录 (按正序保存)
            csv_rows.append({'Date': d, **counts, 'Total': total})

        # 4. 写入 README
        with open(README_FILE, 'w', encoding='utf-8') as f:
            f.writelines(content)

        # 5. 持久化 CSV (按日期正序写入)
        headers = ['Date'] + platforms + ['Total']
        with open(HISTORY_CSV, 'w', newline='', encoding='utf-8-sig') as f:
            writer = csv.DictWriter(f, fieldnames=headers)
            writer.writeheader()
            writer.writerows(sorted(csv_rows, key=lambda x: x['Date']))

if __name__ == "__main__":
    d_data, ac_pool, todo_pool, p_list = scan_repository()
    generate_daily_logs(d_data)
    update_readme_and_csv(d_data, ac_pool, todo_pool, p_list)
    print(f"✅ 整合同步完成：README 导航、每日总结及 CSV 数据已全部更新。")