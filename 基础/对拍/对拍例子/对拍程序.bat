���ĳ���.bat�Ĵ��룺

@echo off
:loop
data.exe  //������������
sp.exe //��֤���� 
qsort.exe  //���Գ���
fc right.out test.out  //�Ƚ���֤��������Գ���Ľ��
if not errorlevel 1 goto loop  //������һ��ת��loop
pause  //������ͣ
goto loop
