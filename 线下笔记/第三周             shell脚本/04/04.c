1. .h声明函数  .o链接
编译    链接完成 静态
执行阶段链接完成 动态
2.俩个同时出现 优先使用 动态库
程序执行默认去标准路径去找，静态库，编译时，自动到标准路径下去

预处理 ，编译，汇编，
gcc -E,-S，-c 
     .i,.s,.o  
gcc a.c 直接到链接阶段
动态
.c 
1. 准备编写一个功能函数：
/////// hello.c ////
#include <stdio.h>
void hello(char *s)
{
	printf("HELLO %s\n",s);
}
2..h
/////// hello.h ////
#ifndef MY_H 
#define MY_H 
extern void hello(char *s);     // 声明功能函数。 
#endif 
3..c-->.o
~$ gcc -c hello.c -o hello.o
4..o-->libhello.so
(1).动态库 ~$ gcc -fPIC -shared hello.o -o libmyhello.so 
so移动到标准路径下 /usr/lib
~$ sudo mv libmyhello.so /usr/lib
a.out

(2).静态库~$ ar cr libmyhello.a hello.o  
a.out

一个目录下只能有一个makefile
make 默认执行 第一条
makefile 编译
shell 批处理指令

$< 源文件     第一个依赖文件
^$ 过程文件   依赖文件
$@           目标文件
目标 文件 执行过程

一个l十行 第一个l要找到main
n 运行到下一行行头



gcc编译流程分析：
    1.预处理，生成预编译文件（.文件）：
        Gcc –E hello.c –o hello.i
    2.编译，生成汇编代码（.s文件）：
        Gcc –S hello.i –o hello.s
    3.汇编，生成目标文件（.o文件）：
        Gcc –c hello.s –o hello.o
    4.链接，生成可执行文件：目标文件与库链接为可执行程序或库文件。
        Gcc hello.o –o hello







问题：如果工程量比较大时，编译很消耗时间。此时如果编译出错，程序修改后，需要全部重新编译，很消耗时间。
如何改进措施，使编译效率提高？
解决：可以分而治之。每个文件对应生成自己的 .o 文件。最后进行统一链接即可。这样做的好处是：
哪个文件进行了修改，则重新编译。没做改动的文件，无需重新编译。 






















