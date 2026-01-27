@echo off
:: 强制 CMD 使用 UTF-8 编码，解决中文乱码
chcp 65001 >nul

title 算法仓库自动整理工具
cd /d "%~dp0"

echo 🔍 正在本地整理代码状态...
:: 告诉 Python 也强制使用 UTF-8 输出
set PYTHONUTF8=1
python organize.py

echo.
echo ☁️ 第二步：准备同步至 GitHub...

:: 执行 Git 流程
git add .
:: 使用当前时间作为 Commit 信息
git commit -m "Auto sync: %date% %time%"
git push

echo.
echo ✅ 全部流程已完成！

echo.
echo ✨ 任务处理完毕！
pause