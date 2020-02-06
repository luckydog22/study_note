1.块设备(硬盘)  字符设备（鼠标键盘）
俩图一句话
2.shell是一个命令行解释器
bin 存放可执行文件的位置
boot 存放引导文件
etc 配置文件存放路径
mnt 挂载路径
proc 进程信息存放路径
dev  设备文件存放路径
home 用户工作目录
lib 库文件存放路径
root 超级用户工作目录
sbin 指令存放路径
usr .h存放位置

shell命令
1.ls l列出目录下文件
2.
通过颜色区分文件类型：
白色：普通文件
深蓝色：目录文件
绿色：可执行文件
3.ls -l 
文件详细信息：
-rwxrwxr-x 1 linux linux 7278 Nov 24 02:57 a.out
drwxr-xr-x 2 linux linux 4096 Nov 12 19:23 Desktop
(1)属性 文件所有者  文件所属组  大小 日期和时间  文件名
(2)属性俩组：第一组：一个字符  —普通文件  d目录文件
			 第二组：r可读  w可写  x可执行  
					三个部分：
					文件所有者对文件的使用权限
					文件所属组对文件的使用权限
					其他用户对文件的使用权限
4.cd进入目录
路径：
绝对路径：以根目录为起点的路径，绝对路径
相对路径：相对于当前的路径
cd ../Document
24.c   Desktop    Downloads  Pictures  Templates
a.out  Documents  Music      Public    Videos

linux@ubuntu:~$ cd /home/linux/Desktop
linux@ubuntu:~/Desktop$  cd ../Music
相对路径，走的话，必须返回要走的同级文件下，才可以

5.cd~用户工作路径
cd-上一次进入路径
.当前路径
..上一级路径

6.touch 创建普通文件
mkdir 创建目录文件（文件夹）
(1)删除目录 rm -r   
(2)删除目录rm eee -r

7.mv a.c public/  
(1)把某个文件移到某个文件夹下
(2)mv 重命名功能  若是移动的路径不存在，则改名为路径名

8.cp拷贝文件
cp 原名字 新名字
cp -r 原名字 新名字（目录文件）

9.pwd 当前所在位置绝对路径

10.计算机提示
用户名 @ 计算机名字:当前路径 $
linux  @   ubuntu  : ~$ 
exit 退回原用户
~代表工作路径

11.linux下  一切都是文件
12.写w权限 给不了用户
chmod +w x.c  w w 空  //修改文件属性
使用二进制，rwx给就是1 不给是0  转成八进制

13.用户管理
(1)分类：
超级用户： root. 只有一个，一切权限
普通用户：linux 。可有多个。 拥有的权限有限。要想使用一些命令例如安装，关机，需到root 出借权限
切换用户：su + 用户名
第一次使用得： sudo passwd root 然后设置密码
退回上一次的用户 exit  退回的时候 原路退回 例如Linux desk 退回
也可以su 用户名--
(2)创建用户
sudo adduser alice
(3)删除用户
sudo userdel -r alice   

14.vi
找文件：
located 文件名字    找到文件位置
20G跳到 第20行
:vsp 分屏模式  切换屏幕 ctrl +  ww

15.低行模式：
替换：
range s/string1/string/gc
% 全篇的意思  $文末的意思
查找：
/向下找   (n 查找下一个)
？向上找  (n 查找上一个)
