@echo off
:: 1. 环境初始化
chcp 65001 >nul
title 🏆 ACM 训练仓库自动整理工具
cd /d "%~dp0"

:: 强制使用 UTF-8 编码输出
set PYTHONUTF8=1

:: 指定 Anaconda 环境路径
set PY="D:\develop\Python313\python.exe"
echo ============================================
echo      🚀 正在启动：算法仓库自动化流程
echo ============================================

:: 2. 执行 Python 脚本
echo 📂 [1/4] 正在扫描并整理题目位置...
%PY% Scripts\organize.py

echo.
echo 📊 [2/4] 正在更新训练日志与持久化数据...
%PY% Scripts\log.py

echo.
echo 🎨 [3/4] 正在生成今日成就热力图...
%PY% Scripts\heatmap.py

echo.
echo 🧹 [4/4] 正在清理冗余的二进制文件...
del /f /q *.exe 2>nul

echo.
echo ============================================
echo ✅ 全部流程已完成！
echo ============================================

:: 4. 收尾
echo 任务处理完毕，按任意键退出...
pause >nul