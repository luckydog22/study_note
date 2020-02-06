
Linux 及 c高级 -- 数据结构 -- IO -- 进程线程 -- 网络编程 -- c++ qt opencv -- 硬件 - 项目 


本周6天课程安排：  
1-2 ： linux 命令  
3   ： linux 下的工具： 编译器：gcc     调试器：gdb    工程管理工具：make 
4   ： shell 脚本  
5-6 ： c 高级




一、linux 基础简介

1. linux 发行版本
redhat     .rpm  
ubuntu     .deb 
android    .apk 


2. linux 内核版本    版本号 2.4.18   
2   主版本号（有重大更新时才更新）
4   次版本号（偶数代表稳定版本  、奇数代表测试版本）
18  末版本号（有更新就更新版本号）


3. linux 体系结构   
用户空间： 程序、命令、shell脚本  
内核空间： 进程管理、IO、内存管理 等等


4. 什么是shell
作用是： 用来保护 linux 内核、负责完成用户与内核空间的交互
本质：   命令行解释器 


5. 目录结构 （树形结构）
目录的起点： 根目录  /
根目录下的文件：
bin          存放二进制可执行文件
etc          存放配置文件的路径
mnt          挂载路径 mount 
proc         操作系统的所有进程信息，都存放在此文件夹下  process
boot         引导系统等内容存放的位置 
dev          设备文件信息，都存放在此  device
home         家目录/用户工作目录   普通用户的工作目录，都在这个路径下  /home/linux 
root         管理员（超级用户）的工作路径
sbin         存放指令文件的位置 

一些约定俗称的路径符号： 
/    根目录  
.    当前目录 
..   上一级目录
-    上一次进入的目录 
~    当前用户的工作路径

6. linux 下，一切皆文件



二、 shell 命令 

1. ls   列出目录下的文件  
1） 可以通过颜色区分文件类型： 
白色：   普通文件 
深蓝色： 目录文件 
绿色：   可执行文件 

2） ls -l     查看文件详情
  属性      文件所有者 文件所属组 大小  日期和时间  文件名 
-rw-rw-r-- 1   linux      linux      0 Jun 21  2014 test.c
drwxr-xr-x 2   linux      linux   4096 Sep 22  2012 Videos

属性：二组。第一组：一个字符  
-  普通文件 
d  目录文件 

第二组： r可读  w可写   x可执行  
三个部分：  
第一个rwx :文件所有者对文件的使用权限。 
第二个rwx :文件所属组对文件的使用权限。 
第三个rwx :其他用户的使用权限。 

3）  ls -a   查看目录下的所有文件，包括隐藏文件     
隐藏文件： 以'.'做为名字起始字符的文件 


2. cd 进入目录 
路径： 
绝对路径：以根目录为起点的路径，叫绝对路径。 
相对路径：相对于当前位置的路径，叫相对路径。 

一些约定的路径：
/  根目录  
~  用户工作目录  
-  上一次进入的路径 
.  当前路径 
.. 上一级路径


3. touch  创建普通文件  


4. mkdir 创建目录文件  


5. rm   删除文件  
rm 
rm -r  


6. mv 功能有二：  
1） 移动      mv + 文件 + 要移动到的位置（已存在的位置）      
2） 重命名：  mv + 原文件名 + 新文件名（没有存在过的名字）


7. cp  拷贝文件   
cp  原名 + 新名 
cp -r 原名 + 新名

示例： 
cp a.c Public            拷贝a.c 文件到 Public 目录下。 
cp a.c Public/x.c        拷贝a.c 文件到 Public 目录下，并起个新名字叫 x.c 。
cp -r Public Videos      拷贝目录文件 Public 到 Videos 路径下。 


8. pwd  查看自己所在位置的绝对路径 


9. chmod   修改文件的属性   
两种方式：  
chmod -r x.c      // 直接加减读写权限。 
chmod +w x.c 
chmod 664 x.c     // 使用数字代表当前位的权限是开还是关。 
chmod 777 x.c 


10. 计算机提示
用户名 @ 计算机名 ：当前路径  $ 
linux  @  ubuntu  :    ~      $ 
root   @  ubuntu  :/home/linux# 


11. 用户管理 
1） 分类：
超级用户： root . 只有一个。 拥有一切权限。  
普通用户： linux。可以有多个。 拥有的权限有限。普通用户要想完成安装、关机等功能，需要去 root 借权限才能执行。  

切换用户：su + 用户名
su root    // 第一次使用root 用户时，需要设置通行码，命令为：sudo passwd root 

退回原用户： exit 
普通用户临时借用管理权限： sudo  


2） 用户的创建与删除
知识储备：
/etc/passwd     该文件保存了各用户的基本信息。 打开： vi /etc/passwd 
/etc/shadow     该文件保存了各用户的加密信息。 打开时，需要管理权限： sudo  vi   /etc/shadow 
/home/alice     该路径是用户工作路径。  /home 为用户工作路径 

a.创建用户命令  sudo adduser alice 

//演示创建过程：
linux@ubuntu:~$ sudo adduser alice
Adding user `alice' ...
Adding new group `alice' (1001) ...
Adding new user `alice' (1001) with group `alice' ...
Creating home directory `/home/alice' ...
Copying files from `/etc/skel' ...
Enter new UNIX password: 
Retype new UNIX password: 
passwd: password updated successfully
Changing the user information for alice
Enter the new value, or press ENTER for the default
	Full Name []: re
	Room Number []: 710
	Work Phone []: 110
	Home Phone []: 119
	Other []: 234
Is the information correct? [Y/n] y

//添加完毕后，可以查看该用户的基本信息：  
vi /etc/passwd 
sudo vi /etc/shadow 
ls /home 


b.删除用户命令  sudo userdel -r alice 


12. vim 编辑器   
三种模式： 命令行模式、插入模式、底行模式      

1）进入插入模式的方式： 
相同是：以下字母都是从命令行模式进入插入模式。不同点详见下文：
i    :光标位置不变  
I    ：光标移动到当前行首个不是空的位置。   
o    : 进入插入模式的同时，会在光标所在位置的下一行新建一行，并且光标移动到新建行。 
O    : ....                                  上  。。。 
a    : 光标向后移动一个字符的位置。 
A    ：光标移动到行尾。
s/S  : 删除一个字符/删除一行 不推荐使用。 

2）命令行模式： 
yy     复制一行
p      粘贴
dd     剪切一行
dw     剪切一个单词 
v……y   块复制
u      撤销 
ZZ     保存并退出 
20G    光标跳到第20行 
-      光标向上移动一行  
+      光标向下移动一行   
30+    向下移动30行  
$G     光标跳到文件末尾 
x      删除光标后的一个字符  
X      删除光标前的一个字符

// 熟悉快捷键 

3）底行模式： 
:q     退出  
:wq    保存并退出  
:x     保存并退出  
:q!    强制退出（不保存）
:vsp   分屏模式           切换屏幕： Ctrl + ww

查找： /  ?
/  向下查找   （n 查找下一个，会向下找 ）
?  向上查找   （n 查找下一个，会向上找 ） 

使用方式：  /printf 

替换： 
格式： :range  s/string1/string2/gc  
range    替换的范围   
s        表替换   
string1  表示要被替换掉的关键字 
string2  表示用此关键字来替换  
gc       可选项，可选可不选  g :代表要替换找到的所有的关键字。 c 代表替换前询问 

示例：  
:%     s/print/hello/gc         // %    代表：替换范围是全文 
:1,20  s/print/hello/gc         // 1,20 代表：替换范围是 1~20行  
:20,$  s/print/hello/gc         // 20,$ 代表：替换范围是20行到文件末尾。


13. 关机 
sudo poweroff        关机  
sudo reboot          重启
sudo shutdown -h now     立即关机     // halt - 停止    reboot - 重启 
sudo shutdown -h 30      30分钟后关机
sudo shutdown -h 17:30   17:30 关机
sudo shutdown -r now     立即重启  
sudo shutdown -r 30      30分钟后重启  


14. 预习《操作系统》-进程管理-文件管理-网络管理





