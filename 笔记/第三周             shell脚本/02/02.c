一.进程管理
进程：
程序：
pid：类似于数据库主键

ps aux	查看进程信息
ps -ef	 查看父进程id
pstree   查看进程树
top    	 查看进程的动态信息
kill pid 杀死某个进程
kill -9  若kill删不掉，则用这个
kill -l  杀死详情

父进程，子进程，孤儿进程，僵尸进程

父进程给子进程收尸

fg 1：占用终端，前台执行
bg 1：放到后台
jobs:查看暂停进程
control z暂停进程
control c终止进程
control /

control alt t打开新的终端
二.文件管理
1.查看文件内容
cat  a.c	终端显示	
more a.c 	不能回看  回车下一行  空格下一屏
less 			
head
tail
2.查找文件
find
which
locate
grep