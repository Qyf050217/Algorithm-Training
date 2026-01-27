import os
import json
import csv
from datetime import datetime
from collections import defaultdict

# 获取当前脚本的绝对路径，并定位到它的上一级（即项目根目录）
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# 以后所有的路径都基于 BASE_DIR
ACCEPTED_DIR = os.path.join(BASE_DIR, 'Accepted')
ATTEMPTED_DIR = os.path.join(BASE_DIR, 'Attempted')
CSV_PATH = os.path.join(BASE_DIR, 'training_history.csv')
IMG_PATH = os.path.join(BASE_DIR, 'ac_heatmap.png')

# 配置
ACCEPTED_DIR = 'Accepted'
ATTEMPTED_DIR = 'Attempted'
HISTORY_CSV = 'training_history.csv'
README_FILE = 'README.md'

def get_stats():
    """扫描目录获取 Accepted 历史和 Attempted 积压"""
    daily_ac = defaultdict(lambda: defaultdict(int))
    backlog = defaultdict(int)
    all_platforms = set()

    # 1. 统计 Accepted (Accepted/平台/日期)
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

    # 2. 统计 Attempted (Attempted/平台)
    if os.path.exists(ATTEMPTED_DIR):
        for p in os.listdir(ATTEMPTED_DIR):
            p_path = os.path.join(ATTEMPTED_DIR, p)
            if os.path.isdir(p_path):
                all_platforms.add(p)
                count = len([f for f in os.listdir(p_path) if f.endswith('.cpp')])
                backlog[p] = count

    return daily_ac, backlog, sorted(list(all_platforms))

def persist_to_csv(daily_ac, platforms):
    """将数据持久化到 CSV 文件"""
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

def update_readme(daily_ac, backlog, platforms):
    """更新 README.md，包含热力图引用和统计表"""
    now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    
    content = [
        "# 🏆 Algorithm Training Log\n",
        f"> 🎯 **Goal:** ACM Silver Medal | *Last updated: {now}*\n\n",
        "## 📈 训练热力图 (Heatmap)\n",
        "![Algorithm Training Heatmap](ac_heatmap.png)\n\n", # 引用热力图图片
        "--- \n\n",
        "## ⏳ 当前待补题库 (Backlog)\n\n"
    ]

    # 生成 Backlog 表格
    if any(backlog.values()):
        content.append("| " + " | ".join(platforms) + " | **Total** |\n")
        content.append("| " + " | ".join([":---:"] * (len(platforms) + 1)) + " |\n")
        row = [str(backlog[p]) if backlog[p] > 0 else "-" for p in platforms]
        content.append("| " + " | ".join(row) + f" | **{sum(backlog.values())}** |\n\n")
    else:
        content.append("✅ 暂无积压题目，补题效率满分！\n\n")

    # 生成 AC 历史表格
    content.append("## 📊 每日过题记录 (AC History)\n\n")
    if daily_ac:
        content.append("| 日期 | " + " | ".join(platforms) + " | **Total** |\n")
        content.append("| :--- | " + " | ".join([":---:"] * (len(platforms) + 1)) + " |\n")
        for d in sorted(daily_ac.keys(), reverse=True):
            row = [str(daily_ac[d][p]) if daily_ac[d][p] > 0 else "-" for p in platforms]
            total = sum(daily_ac[d].values())
            content.append(f"| {d} | " + " | ".join(row) + f" | **{total}** |\n")

    with open(README_FILE, 'w', encoding='utf-8') as f:
        f.writelines(content)

if __name__ == "__main__":
    d_ac, b_log, p_list = get_stats()
    persist_to_csv(d_ac, p_list)
    update_readme(d_ac, b_log, p_list)
    print("✅ 日志与持久化数据已更新！")