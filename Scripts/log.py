import os
import csv
import re
from datetime import datetime
from collections import defaultdict

# --- 1. 路径自动定位 ---
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

ACCEPTED_DIR = os.path.join(BASE_DIR, 'Accepted')
ATTEMPTED_DIR = os.path.join(BASE_DIR, 'Attempted')
HISTORY_CSV = os.path.join(BASE_DIR, 'training_history.csv')
README_FILE = os.path.join(BASE_DIR, 'README.md')

# --- 2. 配置参数 ---
TOP_N = 5

def get_oj_url(cpp_path):
    """从同目录下的 .cph 文件夹提取网址"""
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

def persist_to_csv(daily_ac, platforms):
    """将统计数据持久化到 CSV 供 heatmap.py 绘图"""
    headers = ['Date'] + platforms + ['Total']
    rows = []
    for d in sorted(daily_ac.keys()):
        row = {'Date': d}
        total = 0
        for p in platforms:
            val = daily_ac[d].get(p, 0)
            row[p] = val
            total += val
        row['Total'] = total
        rows.append(row)

    with open(HISTORY_CSV, 'w', newline='', encoding='utf-8-sig') as f:
        writer = csv.DictWriter(f, fieldnames=headers)
        writer.writeheader()
        writer.writerows(rows)

def get_stats():
    daily_ac = defaultdict(lambda: defaultdict(int))
    all_platforms = set()
    if os.path.exists(ACCEPTED_DIR):
        for p in os.listdir(ACCEPTED_DIR):
            p_path = os.path.join(ACCEPTED_DIR, p)
            if os.path.isdir(p_path):
                all_platforms.add(p)
                for d in os.listdir(p_path):
                    d_path = os.path.join(p_path, d)
                    if os.path.isdir(d_path):
                        count = len([f for f in os.listdir(d_path) if f.endswith('.cpp')])
                        daily_ac[d][p] += count
    return daily_ac, sorted(list(all_platforms))

def get_top_n(folder, reverse_sort=True):
    """扫描目录，获取 Top N 题目并提取平台名称"""
    problems = []
    if not os.path.exists(folder): return []
    for root, _, files in os.walk(folder):
        for f in files:
            if f.endswith('.cpp'):
                path = os.path.join(root, f)
                url = get_oj_url(path)
                if url:
                    # 获取平台名称
                    rel_root = os.path.relpath(root, folder)
                    platform = rel_root.split(os.sep)[0] if rel_root != "." else "Other"
                    
                    mtime = os.path.getmtime(path)
                    problems.append({
                        'name': f.replace('.cpp', ''),
                        'url': url,
                        'platform': platform,
                        'time': mtime
                    })
    problems.sort(key=lambda x: x['time'], reverse=reverse_sort)
    return problems[:TOP_N]

def update_readme():
    """生成看板 HTML 并更新 README"""
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    daily_ac, platforms = get_stats()
    
    recent_ac = get_top_n(ACCEPTED_DIR, reverse_sort=True)
    oldest_pending = get_top_n(ATTEMPTED_DIR, reverse_sort=False)

    # 看板 HTML
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
                {"".join([f"<tr><td align='center'><code>{p['platform']}</code></td><td><a href='{p['url']}'>{p['name']}</a></td><td align='right'>{datetime.fromtimestamp(p['time']).strftime('%m-%d')}</td></tr>" for p in oldest_pending]) if oldest_pending else "<tr><td colspan='3' align='center'>暂无积压题目，补题效率满分！！</td></tr>"}
                </tbody>
            </table>
        </td>
    </tr>
</table>
"""

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

    if daily_ac:
        content.append("| 日期 | " + " | ".join(platforms) + " | **Total** |\n")
        content.append("| :--- | " + " | ".join([":---:"] * len(platforms)) + " | :---: |\n")
        for d in sorted(daily_ac.keys(), reverse=True):
            row = [str(daily_ac[d][p]) if daily_ac[d][p] > 0 else "-" for p in platforms]
            content.append(f"| {d} | " + " | ".join(row) + f" | **{sum(daily_ac[d].values())}** |\n")

    with open(README_FILE, 'w', encoding='utf-8') as f:
        f.writelines(content)
    
    persist_to_csv(daily_ac, platforms)

if __name__ == "__main__":
    update_readme()
    print(f"✅ README 与 CSV 数据已同步！")