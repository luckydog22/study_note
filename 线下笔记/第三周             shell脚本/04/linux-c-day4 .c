

一、 gcc (gnu 组织重要的编译工具)

1. gcc 完成编译的四步过程： 预处理、编译、汇编、链接 
(1) 预处理：     gcc -E a.c -o a.i 
a. 将头文件的内容拷贝到源文件中。 
b. 如果有宏定义，将宏值替换掉宏名。
c. 如果有注释，将注释去掉。 

(2) 编译：  gcc -S a.c -o a.s 

(3) 汇编：  gcc -c a.c -o a.o           

(4) 链接：  gcc a.c  


2. 错误和警告
-Wall     // 意义是： 打印出所有警告 
-w        // 屏蔽掉所有警告（不建议使用）

警告 warning ： 两类：   warn类/ 非warn类 警告
错误 error   ： Segmentation fault(core dump)  段错误。  一定是地址问题。去找指针是否为野指针、数组下标是否越界等。


3. time 命令 和优化选项

time 命令： 用来显示程序运行的总时间、处于用户态的运行时间、处于内核态的运行时间等。
real	0m0.001s
user	0m0.001s
sys		0m0.000s

用法： time ./a.out     // 运行程序时，在前面写 time 即可。 

优化选项： -O      -O1  -O2  -O3 //数字越大，代表优化的级别越高    
gcc -O1 a.c -o a1 
gcc -O2 a.c -o a2 
gcc -O3 a.c -o a3 


4. 整体编译 

现有多个文件，需要编译生成一个可执行文件： 
//////// main.c //////
extern void add();
extern void sub();
extern void mul();
extern void div();
int main()
{
	add();
	sub();
	mul();
	div();
}
//////// a.c ////////
#include <stdio.h>
void add()
{
	printf("add\n");
}
//////// b.c ////////
#include <stdio.h>
void sub()
{
	printf("sub\n");
	printf("sub\n");
}
//////// c.c ////////
#include <stdio.h>
void mul()
{
	printf("mul\n");
}
//////// d.c ////////
#include <stdio.h>
void div()
{
	printf("div\n");
}

编译： gcc main.c a.c b.c c.c d.c -o main 
执行： ./main 
结果： 
add 
sub 
sub 
mul 
div 



二、 函数库的制作和使用  
过程：
1. 准备编写一个功能函数：
/////// hello.c ////
#include <stdio.h>
void hello(char *s)
{
	printf("HELLO %s\n",s);
}
/////// hello.h ////
#ifndef MY_H 
#define MY_H 
extern void hello(char *s);     // 声明功能函数。 
#endif 


2. 将功能函数制作成函数库。 （静态库或者动态库都行，生成其中一个即可）
~$ gcc -c hello.c -o hello.o     //需要这样一个中间过程，就是将 .c 源文件 生成 .o 文件。    .o 文件是生成函数库的前期准备文件。 

~$ gcc -fPIC -shared hello.o -o libmyhello.so    // 生成动态库的命令。     -fPIC  -shared  是动态库的两个特性 
~$ ar cr libmyhello.a hello.o    // 此命令可以生成静态库。     静态库与动态库的命名规则： 前缀： lib    后缀： 动态库：.so  静态库：.a 


3. 当我们的代码中有对该函数的需求，只需要链接该函数的库文件即可。 
////////// a.c ////
#include "hello.h"
int main()
{
	hello("string~");      // 代码中，调用该功能函数。 
}
编译与执行过程： 
~$ gcc a.c -lmyhello -L.            // -l 代表链接第三方库      -L 指定库的路径   . 代表当前路径 
~$ sudo mv libmyhello.so /usr/lib   // （链接动态库时才需要的语句）要将函数库文件移动到标准路径下，进行动态链接时，才能找到该库文件。这也说明一个问题：程序在执行时，才链接动态库。
~$ ./a.out                          // 执行程序即可。 


4. 静态库与动态库的特点 
a. 动态库也叫共享库。 
b. 当动态库和静态库同时出现时，优先使用动态库 。 
c. 使用区别： 使用动态库时，是在程序运行时进行的链接。 使用静态库时，是在编译阶段就完成了链接过程。




三、 make （工程管理工具）

make     : make 工程管理工具。 也可以理解为 make 是一条命令
makefile : 是文本文件。其内容描述了 make 的编译规则。

1. 一个文件的编译
示例： 
vi makefile 
##################
hello:a.c                // 目标名称：依赖文件
	gcc a.c -o hello     // 具体的编译规则
#####

添加功能： 
#################
hello:we.c            
	gcc we.c -o hello
clean:                   // 目标名称 ： 清除功能。 
	rm hello             // 具体执行的命令  
rebuild: clean hello     
#####

在命令行执行 make 即可。  
如果文件已经更新到最新，而没有做改动。则再次make 时，文件不会被重新编译。 
make 会根据文件的最后修改时间（文件时间戳），判定是否有文件需要重新编译。 


2. 多个文件（一个工程）的编译 
####################
main:main.c a.c b.c c.c d.c 
	gcc main.c a.c b.c c.c d.c -o main 
clean:
	rm main 
rebuild: clean main 
#####

问题：如果工程量比较大时，编译很消耗时间。此时如果编译出错，程序修改后，需要全部重新编译，很消耗时间。
如何改进措施，使编译效率提高？
解决：可以分而治之。每个文件对应生成自己的 .o 文件。最后进行统一链接即可。这样做的好处是：
哪个文件进行了修改，则重新编译。没做改动的文件，无需重新编译。 
vi makefile 
##################
main:main.o a.o b.o c.o d.o 
	gcc main.o a.o b.o c.o d.o -o main
.o:.c 
	gcc -c *.c 	
clean:
	rm *.o
	rm main 
rebuild: clean main 
######
编译及执行过程： 
kayla@ubuntu:~/calc$ make         #第一次编译
gcc     -c -o main.o main.c
gcc     -c -o a.o a.c
gcc     -c -o b.o b.c
gcc     -c -o c.o c.c
gcc     -c -o d.o d.c
gcc  main.o a.o b.o c.o d.o -o hello
kayla@ubuntu:~/calc$ make              # 第二次编译。表示目标文件已是最新，无需重新编译。
make: 'hello' is up to date.
kayla@ubuntu:~/calc$ vi b.c         # 修改其中一个文件
kayla@ubuntu:~/calc$ make           # 修改过的文件重新编译，其他文件无需重新编译。 
gcc     -c -o b.o b.c
gcc  main.o a.o b.o c.o d.o -o hello     # 重新链接，生成可执行文件。 


3. 变量的使用：
1）系统预设变量： 
$@ : 完整的目标名称 
$< : 第一个依赖文件 
$^ : 依赖文件

2）自定义变量：         将常常需要变化的量，用变量去表达
vi makefile 
########### makefile 修改如下：
EXEC=hello
OBJS=main.o a.o b.o c.o d.o  
CC=gcc 

$(EXEC):$(OBJS) 
	$(CC) $^ -o $@
.o:.c 
	$(CC) -c $<	
clean:
	rm $(OBJS)
	rm $(EXEC)
rebuild: clean $(EXEC)
############




四、 gdb   (gnu debuger)

1.适用场合： gcc 编译文件没有出错，但是不出现正确结果的程序，可以使用 gdb 调试。

2.使用： 
~$ gcc -g -o a a.c     // 添加调试信息到可执行文件中。 
~$ gdb a               // 生成的这个可执行文件，会比不添加调试信息的执行文件要大些，因为多了调试信息。 

3.演示过程
~$ gdb a.out 
GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...done.
(gdb) q 

gdb 的调试命令： 
l       list 列出代码详情。默认列出 10 行。可重复使用。  
b  5    breakpoint  设置断点。  5 代表第五行 
info b  查看断点信息    
clear 6 删除断点。  6 代表代码所在位置的行号 
d   1   delete 删除断点。 1 代表断点编号。
r       run  运行程序  
n       next 单步运行  
p i     print 打印变量的值。 i 代表变量名   
c       continue  继续运行  
q       quit  退出 gdb 模式  


// 练习： 《实验手册》 实验四






// 作业： 预习： 数组指针、二级指针、


