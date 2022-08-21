对拍程序.bat的代码：

@echo off
:loop
data.exe  //产生测试数据
sp.exe //验证程序 
qsort.exe  //测试程序
fc right.out test.out  //比较验证程序与测试程序的结果
if not errorlevel 1 goto loop  //如果结果一致转到loop
pause  //否则暂停
goto loop
