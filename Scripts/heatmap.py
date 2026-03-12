import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from datetime import datetime, timedelta
from matplotlib.colors import ListedColormap
import os

# 获取当前脚本的绝对路径，并定位到它的上一级（即项目根目录）
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# 以后所有的路径都基于 BASE_DIR
ACCEPTED_DIR = os.path.join(BASE_DIR, 'Accepted')
ATTEMPTED_DIR = os.path.join(BASE_DIR, 'Attempted')
CSV_PATH = os.path.join(BASE_DIR, 'training_history.csv')
IMG_PATH = os.path.join(BASE_DIR, 'ac_heatmap.png')

# ANSI 颜色配置
GREEN, YELLOW, BLUE, RED, RESET = "\033[92m", "\033[93m", "\033[94m", "\033[91m", "\033[0m"

def plot_daily_achievement_heatmap():
    print(f"{BLUE}📊 正在调取最新的训练数据...{RESET}")
    csv_path = CSV_PATH # 使用定义的全局变量
    
    if not os.path.exists(csv_path):
        print(f"{RED}❌ 错误：未发现持久化文件。请先运行 generate_log.py 同步今日数据。{RESET}")
        return

    try:
        # 1. 加载并规范化数据
        df_history = pd.read_csv(csv_path, encoding='utf-8-sig')
        df_history['Date'] = pd.to_datetime(df_history['Date']).dt.normalize()
        daily_stats = df_history.groupby('Date')['Total'].sum().to_dict()

        # 2. 获取今日成就数据 [cite: 2026-01-27]
        today = pd.Timestamp.now().normalize()
        today_ac = int(daily_stats.get(today, 0))
        
        # --- 交互反馈逻辑：聚焦今日 ---
        print("-" * 40)
        print(f"📅 今日日期: {BLUE}{today.strftime('%Y-%m-%d')}{RESET}")
        print(f"🔥 今日 AC 总数: {GREEN}{today_ac}{RESET} 题")
        
        if today_ac == 0:
            print(f"{YELLOW}💡 提示：今天还没有 AC 记录，快去写题吧！{RESET}")
        elif today_ac < 2:
            print(f"{BLUE}💪 评价：保持手感，目前的进度大约完成了今日目标的 {today_ac/4*100:.1f}%。{RESET}")
        elif today_ac < 4:
            print(f"{YELLOW}🚀 评价：渐入佳境！再过 {4-today_ac} 题就能达成“深绿”成就！{RESET}")
        else:
            print(f"{GREEN}👑 评价：今日目标圆满达成！{RESET}")
        print("-" * 40)

        # 3. 构造 365 天热力图矩阵
        start_date = today - pd.Timedelta(days=364)
        all_days = pd.date_range(start=start_date, end=today, freq='D')
        
        df = pd.DataFrame(index=all_days)
        df['count'] = df.index.map(daily_stats).fillna(0)
        df['weekday'] = df.index.weekday
        df['rel_week'] = ((df.index - start_date).days + start_date.weekday()) // 7
        
        matrix = df.pivot_table(index='weekday', columns='rel_week', values='count', aggfunc='sum')

        # 4. 绘图：精确复刻 CF 经典配色
        plt.figure(figsize=(15, 3))
        
        ax = plt.gca()
        ax.set_facecolor('#ebedf0') # 经典浅灰底色
        
        # 👉 定义 CF 经典的 5 阶极客绿色盘
        cf_colors = ['#ebedf0', '#c6e48b', '#7bc96f', '#239a3b', '#196127']
        cf_cmap = ListedColormap(cf_colors)

        # 核心修改点：使用我们自定义的精准色盘
        sns.heatmap(matrix, 
                    cmap=cf_cmap,        
                    vmin=0, vmax=4,      
                    linewidths=1.5, linecolor='#ffffff', 
                    cbar=False,          # 去掉右侧图例，视觉更干净
                    square=True,
                    xticklabels=False, 
                    yticklabels=['Mon', '', 'Wed', '', 'Fri', '', 'Sun'])
        
        plt.title('Algorithm Training Activity (Recent 365 Days)', fontsize=12, pad=10)
        plt.tight_layout()
        
        plt.savefig(IMG_PATH, dpi=200) # 保存至根目录
        print(f"{GREEN}✅ 热力图已同步更新：ac_heatmap.png{RESET}\n")

    except Exception as e:
        print(f"{RED}❌ 运行异常: {e}{RESET}")

if __name__ == "__main__":
    plot_daily_achievement_heatmap()