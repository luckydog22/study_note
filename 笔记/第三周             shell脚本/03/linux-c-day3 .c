
shell 脚本

什么是 shell ?       脚本解释器
什么是 shell 脚本 ？ 命令的有序集合。


编程语言分类： 
解释性语言： 无需编译，执行即可。
shell  
python 
html5 （标签语言）

编译型语言： 先编译，在没有错误之后，才能正确运行。
c 
c++ 
java 

相比较而言，编译型语言更适合进行逻辑处理。 



一、 认识 shell 脚本  

1. 开头 
#!/bin/bash         # 告诉系统，当前脚本由哪个程序运行。 
#!/bin/sh 

2. 示例： 
##############
#! /bin/bash 
#! /bin/sh 
clear
ls
mkdir AAA
ls
date
#############

3. 脚本的执行
方式一： 添加执行权限
		 使用示例： chmod +x x.sh      执行：./x.sh 

方式二： 使用 bash 
		 使用示例： bash x.sh (无需事先添加执行权限)

4. 注释： 以 '#' 开头的句子表示注释

# 练习： 创建一个目录文件 work ，然后，在此目录下创建一个文件 file.txt .
############
#!/bin/bash 
#!/bin/sh 
mkdir work 
cd work 
touch file.txt 
############

5. 变量 
(1) 为了方便识别变量，变量名通常用大写字符
(2) 不能以数字开头，开头必须是字母或者下划线
(3) 不能使用标点符号 

6. 位置参数 与 预设变量、环境变量
1)位置参数： 
$1
$2
...
$6
意义：位置参数可以用 $N 得到。可以将命令行传递进来的参数，进行输出 或者 为代码使用 

2)预设变量：  是shell 一开始时就定义了的变量。 
$#  : 统计参数个数 
$*  : 用来记录所有的位置参数
$@  : 命令行所有的参数  
$?  : 上一句命令的退出状态。如果正常退出，返回0， 如果非正常，则非0。

示例： 
##############
echo "$0"
echo "$1"
echo "$2"
echo "$3"
echo "$#"
echo "$*"

#练习： 请编写shell脚本创建目录文件，文件的名字由位置参数决定。创建完目录之后，在目录中再创建一个普通文件即可。 
###########
#!/bin/bash 
#!/bin/sh 
mkdir $1 
cd $1
touch $2
############
运行： bash RRR create.cpp 

3) 环境变量 
PATH / HOME / HISTSIZE / PS1


7. 功能语句 
输出： echo 
输入： read 

使用示例：
################
read -p "Input STRINGS: " NAME1 NAME2
echo "$NAME1    $NAME2"
###############

# 练习： 创建一个目录文件，然后，在此目录下创建一个普通文件。 文件名字由输入决定。
################
#!/bin/bash 
#!/bin/sh 
read -p "Input dir-name: " DIR
mkdir $DIR
cd $DIR
read -p "Input file-name: " FILE
touch $FILE
###############

8. ""  与 ''
示例： 
##############
NUM=99
echo "$NUM"        #不完全输出。如果想输出变量的值，可以使用此引号。
echo '$NUM'        #完全输出。 即引号引入的内容，直接输出
##############

#问： echo "'$NUM'"  与  echo '"$NUM"' 分别输出的是？         '99'   "$NUM"



二、 shell 的计算  

1) `` :反引号  
使用示例： 
############
OUTPUT=`ls`            #提取 ls 命令的结果，放入变量中。
echo "$OUTPUT"
#############

2) expr  运算语句
示例：
#############
NUM=22
NUM2=33
ADD=`expr $NUM + $NUM2`
echo "$ADD"
#############

#练习： 分别简单检测各运算： （加、减、乘(\*)、除、模除）
使用输入： 
################
#! /bin/bash 
#! /bin/sh
read -p "input num1 ,num2 : " NUM1 NUM2
echo `expr $NUM1 % $NUM2`
##########

使用位置参数：
###############
#! /bin/bash 
#! /bin/sh
echo `expr $1 % $2`
############



三、 shell 的 test 测试语句 及 if 
1. if 的格式： 
if [ 条件 ]
then 
	语句。 
elif [ 条件 ]
then 
	语句2. 
else 
	语句3. 
fi

2. test 测试的对象：3类    字符串 数值 文件类型
1）字符串 
'string1' = 'string2'     判定两个字符串相等？
'string1' != 'string2'    不等？
-z $STRING               判断是否为空字符串？
-n $STRING               是否不为空？

示例： 
###########
#! /bin/bash 
#! /bin/sh 
read -p "Input string: " STRING1 STRING2
if [ $STRING1 = $STRING2 ]
then 
	echo 'yes'
else 
	echo 'no'
fi
###########

#练习： 请输入你的名字，判定是否是“xiaoming”同学。
##################
#! /bin/bash 
#! /bin/sh 
read -p "Input your name: " NAME 
if [ $NAME = 'xiaoming' ]
then
	echo "hello xiaoming~"
else 
	echo "sorry. Goodbye~"
fi
#################


2）数值 
NUM1 -eq NUM2       判断是否相等。 
	 -ne            判断是否不等。 
	 -gt            大于 
	 -ge            大于等于 
	 -lt            小于 
	 -le            小于等于 

示例： 
###############
read NUM
if [ $NUM -gt 0 ]
then 
	echo '>'
else 
	echo '<'
fi
###############

#练习： 输入两个数，判定大小。 
#! /bin/bash
#! /bin/sh 
read NUM1 NUM2 
if [ $NUM1 -eq $NUM2 ]
then
	echo 's1 = s2'
elif [ $NUM1 -gt $NUM2 ]
then
	echo 's1 > s2'
else 
	echo 's1 < s2'
fi

#练习： 输入一个数值，判定此数值是否是偶数。 
#! /bin/bash 
#! /bin.sh
read NUM 
if [ `expr $NUM % 2` -eq 0 ]
then
	echo 'yes'
fi


3）文件类型 
测试语句： 
-f filename      判断文件是否为普通文件  
-d filename      判断文件是否为目录文件
-e filename      判断文件是否存在 
-l filename      判断文件是否为连接文件
-w filename      判断是否有写权限
-x filename      判断是否有执行权限 

示例： 
############# 
#! /bin/bash 
#! /bin.sh
if [ -d $1 ]
then
	echo 'dir'
fi

#练习： 请输入文件名称，判定此文件是否拥有执行权限。 
#! /bin/bash 
#! /bin/sh 
if [ -x $1 ]
then 
	echo 'exec'
else 
	echo 'permission denied'
fi 


#练习： 创建一个目录文件，进入目录后，再创建个普通文件。 
添加条件： 1. 判断该目录文件是否存在：如果存在，就不创建。如果不存在，创建。
		   2. 判断目录是否可执行。 
.		   3. 判断普通文件是否存在。
##################
#! /bin/bash 
#! /bin/sh 
read -p "Input dir-name: " DIR
if [ -d $DIR ]
then 
	echo 'dir exist~'
else 
	mkdir $DIR
fi

if [ -x $DIR ]
then
	cd $DIR  
	read -p "Input file-name: " FILE 
	if [ -f $FILE ]
	then 
		echo 'file exist'
	else 
		touch $FILE 
	fi
else 
	echo 'Permission denied'
fi



四、 shell 中的 case  
格式：  
case $(变量) in        #讨论变量的值，将所有情形列出： 
	a)
		语句。 
		;;          # 相当于 c 语言中的 break.  用来结束当前的一种情况。
	b)              # 变量的其中一个值。  每个出场的值，都用右半括号括起来
		语句。  
		;; 
	*)              #  * 代表除了上述情形之外的所有情形，都在此处理。 
		;; 
esac                # case 的结束语。 

示例： 
################
#! /bin/bash 
#! /bin/sh 
read WEEK 
case $WEEK in 
	3)
		echo "happy-day"
		;;
	6)
		echo "Very happy-day"
		;;
	*)
		echo "work-day"
esac

# 练习： 编写脚本，实现按键 asdw 控制上下左右 
#! /bin/bash 
#! /bin/sh 
read DIRECTION
case $DIRECTION in 
	a)
		echo "Left"
		;;
	s)
		echo "Down"
		;;
	d)
		echo "Right"
		;;
	w)
		echo "Up"
		;;
	*)
		;;
esac

# 练习： 编写脚本，实现简单的计算功能。     示例： bash a.sh 3 + 4
#! /bin/bash 
#! /bin/sh 
case $2 in 
	+)
		echo `expr $1 + $3`
		;;
	-)
		echo `expr $1 - $3`
		;;
	\*)
		echo `expr $1 \* $3`
		;;
	/)
		echo `expr $1 / $3`
		;;
	%)
		echo `expr $1 % $3`
		;;
	*)
		;;
esac



五、 shell 中的 for 循环  
格式： 
for 变量名 in $(单词表)
do 
	循环体。（重复执行的部分）
done 

示例： 
################
NAMELIST="zhao qian sun li zhou wu zheng "
for NAME in $NAMELIST
do
	echo "$NAME"
done 
##########

#练习： 请输出 根目录下的所有文件名称  
#################
#!/bin/bash 
#!/bin/sh
LIST=`ls /`
for NAME in $LIST 
do 
	echo "$NAME"
done 
##########

#练习： 请使用循环实现，将一个路径下的所有文件，复制到另一个路径下。（不使用 cp -r ）
#################
#! /bin/bash 
#! /bin/sh 
LIST=`ls $1`
for NAME in $LIST 
do 
	cp $1/$NAME $2/
done 
############



六、 shell 中 while 循环  
格式：   
while [ 条件 ]      #能否进入循环的条件。如果条件为真，则执行循环，直到条件为假时结束。 
do 
	循环体。（重复执行的部分）
done 

示例： 
###############
i=1
while [ $i -le 100 ]
do 
	echo "$i"
	i=`expr $i + 1`
done 
##########

#练习： 求 1~100 的和。 
################
#! /bin/bash 
#! /bin/sh 
i=1
sum=0
while [ $i -le 100 ]
do 
	sum=`expr $sum + $i`
	i=`expr $i + 1`
done 
echo $sum
##############

#练习： 使用 while 完成功能： 创建  temp1 ~ temp9 九个文件
##################
i=1
while [ $i -lt 10 ]
do 
	touch temp$i
	i=`expr $i + 1`
done 
#########


#综合练习: 编写一个弹出式菜单的shell程序并实现其简单的菜单功能
**************************************************
              *         MENU         *
              *  1.copy     2.rename *
              *  3.remove   4.exit   *
**************************************************
即用户按下数字1，复制
      输入数字2，改名
      输入数字3  删除
      输入数字4，退出  





