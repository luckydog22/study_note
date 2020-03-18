

一、 进程管理
进程： 程序的一次执行过程。包括创建、调度、消亡。           
程序： 是静态的概念，是c代码。 

ps aux     查看进程信息 
ps -ef     查看进程信息（可以查看父进程id）  
pstree     查看进程树 
top        查看进程动态信息
kill       杀死进程。  使用方式 kill + pid .  kill -9 pid . 

pid : process id 进程号。 进程号属于系统资源，每个进程在创建时，系统都会分配一个进程号给当前进程。进程号唯一标识一个进程。 
	  init 进程。是pid为1的进程。是操作系统启动后的第一个进程。 pid 不能被 kill .如果有进程使用kill 结束不掉，可以使用 kill -9 

概念： 父进程、子进程、孤儿进程、僵尸进程

jobs          查看暂停的进程   
ctrl + z      暂停进程 
ctrl + c      终止进程
ctrl + \      终止进程  
ctrl alt + t  打开新的终端窗口
alt + Tab     切换终端窗口
fg 1          将标号为1的暂停进程，调到前台运行。 
bg 2          将标号为2的进程，扔到后台（不占用终端）运行。 



二、 文件管理 
1. 查看文件内容    
cat     示例： cat a.c 
		特点： 直接将文件的内容输入到终端显示。

more    示例： more a.c 
		特点： 会输出满屏信息，但只输出一屏，如果想向下查看，按空格或回车。浏览到文件末尾自动结束当前状态，或者按q结束。 

less    示例： less a.c 
		特点： 进入到查看模式，可以上下查看。 按q退出。
		
head    示例： head a.c 
		特点： 默认查看文件前十行。如果想指定行数，添加选项参数即可。 

tail    示例： tail a.c 
		特点： 默认查看文件尾十行。 


2. 查找文件  
find    格式： find + 路径 + 选项 + 要查找的文件名
		特点： 在磁盘中查找，全盘查找，速度慢。 因为选项参数比较多，所以功能强大。 
		示例： find /usr -name stdio.h 

which   示例： which ls 
		特点： 在环境变量指定的路径下查找可执行文件。            
	
locate  示例： locate 
		特点： 搜寻速度快。原因在于：locate 会到指定的数据库中查找是否存在这样一个文件，而不是去磁盘查找。
		使用注意事项： 先更新，再查找 。 更新命令：sudo updatedb .  查找：locate a.c 
		
grep    功能：查找关键字 
		使用：grep + 关键字 + 范围  
		示例：grep print *.c 


3. 链接命令   ln     - 硬链接、软连接   
文件一般都会分为两个部分： 数据域、索引域          

硬链接：     命令： ln  x.c  x.bak  
过程演示：
kayla@ubuntu:~$ ls -l x.c
-rw-r--r-- 1 kayla kayla 220 Nov 25 02:12 x.c    // 查看文件详情。 文件的索引数为1. 
kayla@ubuntu:~$ ln x.c x.bak     //生成硬链接文件
kayla@ubuntu:~$ ls -l x.*   
-rw-r--r-- 2 kayla kayla 220 Nov 25 02:12 x.bak     // 查看详情。文件的索引数变为2. 
-rw-r--r-- 2 kayla kayla 220 Nov 25 02:12 x.c
kayla@ubuntu:~$ vi x.bak     // 修改其中一个文件
kayla@ubuntu:~$ ls -l x.*
-rw-r--r-- 2 kayla kayla 136 Nov 25 22:51 x.bak    // 文件的大小和修改时间都改变了。 
-rw-r--r-- 2 kayla kayla 136 Nov 25 22:51 x.c
kayla@ubuntu:~$ rm x.c
kayla@ubuntu:~$ ls -l x.*
-rw-r--r-- 1 kayla kayla 136 Nov 25 22:51 x.bak    // 删除其中一个索引，文件的数据域并不会丢失。 索引数为0，数据才真正删除。 
kayla@ubuntu:~$ mv x.bak x.c

总结： 硬链接类似于window下的备份文件，实时备份文件。如果要删除文件的数据，需要使索引数变为0.
	也就是将文件数据域的两个索引域都删除才行。如果只删除一个，文件并不丢失。 


软链接：   
命令： ln -s x.c x.lnk  
过程演示： 
kayla@ubuntu:~$ ln -s x.c x.lnk    // 创建软链接文件
kayla@ubuntu:~$ ls -l x.*
-rw-r--r-- 1 kayla kayla 136 Nov 25 22:51 x.c         // 索引数始终为 1. 
lrwxrwxrwx 1 kayla kayla   3 Nov 25 23:02 x.lnk -> x.c

总结：软链接文件相当于 windows 下的快捷方式。如果想删除文件，只需删除源文件即可。链接文件自动失效。 


4. 压缩文件   tar 
命令 ： 压缩  ： tar cvf z Public.tar.gz Public/ 
		解压缩： tar xvfz Public.tar.gz 
释义 ：
tar    压缩命令   
c      创建压缩 
v      查看文件所有信息，相当于遍历
f      将所有信息压缩
z      gzip 格式   
j      bzip2 格式  
x      解压缩


5. 重定向  >     

分类方式一：  重定向（ > ）与追加重定向（ >> ）
重定向符号( > ) ： 将输出的内容重新指定一个输出位置。 比如将ls 的内容重定向到文件中： ls > file.txt   特点：file.txt 中原内容清空之后，放入新内容。
追加重定向( >> )： 将新内容追加写入文件中。文件中的原内容不丢失。  

分类方式二：  正确信息重定向（ 1> ）、错误信息重定向（ 2> ）  
举例：  ls  1> file.txt 
	gcc a.c 2> file.txt 

四种方式：  1>     2>    1>>   2>> 


6. 管道符     功能：前一个命令的输出，作为第二个命令的输入。 

示例与练习： 
查找文件中的关键字               ： cat /usr/include/stdio.h | grep print 
查找进程中是否存在a.out 进程     ： ps aux | grep a.out 
查找 / 目录下是否有 etc 这个文件 ： ls / | grep etc 



三、 网络管理

1. 查看网络配置信息   ifconfig/ipconfig
eth0:      第一块物理网卡。  
inet 192.168.164.134          ipv4 地址
netmask 255.255.255.0         子网掩码 
broadcast 192.168.164.255     广播地址 
inet6 fe80::9111:dbe0:8777:49c9    ipv6地址

lo:       本地环回
inet 127.0.0.1       环回地址 

修改ip 命令：  sudo ifconfig eth0 192.168.1.123 


2. ping      查看与对方主机是否连通 


3. ip 与 子网掩码  
ip 地址 ： 是由两部分构成： 网络地址 + 主机地址 
子网掩码： 如果使用 子网掩码和ip进行按位与操作，可以屏蔽掉主机地址，得到网络地址


4. 安装问题
(1) ubuntu software center     这里可以下载安装应用       
(2) 下载安装包，然后使用命令安装
安装： sudo dpkg -i *.deb 
卸载： sudo dpkg -r *.deb 

(3) 直接进行网络安装   
安装命令： sudo apt-get install sl 
卸载命令： sudo apt-get remove sl 



预习： shell 脚本





