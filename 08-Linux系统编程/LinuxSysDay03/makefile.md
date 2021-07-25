# makefile
+ 规则:
```
目标: 依赖
(tab)命令
```
## 第一个版本:
```makefile
main: main.c fun1.c fun2.c sum.c
	gcc -o main main.c fun1.c fun2.c sum.c
```
## 第二个版本:
```text
检查规则:
	要想生成目标文件, 先要检查依赖条件是否都存在:
		若都存在, 则比较目标时间和依赖的时间, 如果依赖的时候比目标的时间新,
		则重新生成目标; 否则不重新生成
		若不存在, 则往下找有没有生成依赖的规则, 有则生成, 如果没有则报错.
```
+ 例子
```makefile
main:main.o fun1.o fun2.o sum.o
	gcc -o main main.o fun1.o fun2.o sum.o

main.o:main.c
	gcc -o main.o -c main.c -I./

fun1.o:fun1.c
	gcc -o fun1.o -c fun1.c

fun2.o:fun2.c
	gcc -o fun2.o -c fun2.c

sum.o:sum.c
	gcc -o sum.o -c sum.c
```
## 第三个版本:
### 普通变量
```text
*	变量定义直接用 =
*	使用变量值用 $(变量名)
如:下面是变量的定义和使用
foo = abc			// 定义变量并赋值
bar = $(foo)		// 使用变量, $(变量名)
定义了两个变量: foo、bar, 其中bar的值是foo变量值的引用。
除了使用用户自定义变量, makefile中也提供了一些变量（变量名大写）供用户直接使用, 我们可以直接对其进行赋值：
CC = gcc #arm-linux-gcc
CPPFLAGS : C预处理的选项 -I
CFLAGS:   C编译器的选项 -Wall -g -c
LDFLAGS :  链接器选项 -L  -l
```
### 自动变量
```text
*	$@: 表示规则中的目标
*	$<: 表示规则中的第一个条件
*	$^: 表示规则中的所有条件, 组成一个列表, 以空格隔开, 如果这个列表中有重复的项则消除重复项

特别注意：自动变量只能在规则的命令中使用.
```
### 模式规则
```text
至少在规则的目标定义中要包含’%’, ‘%’表示一个或多个, 在依赖条件中同样可以使用’%’, 依赖条件中的’%’的取值取决于其目标:
比如: main.o:main.c  fun1.o: fun1.c  fun2.o:fun2.c, 说的简单点就是: xxx.o:xxx.c
```
```text
变量: 
    自定义变量: var = hello, $(var)
    自带变量: CC CPPFLAGS CFLAGS LDFLAGS
    自动变量: $@ $< $^
模式规则:
    %.o:%.c------> 前后的%必须是相同 
```
+ 例子：
```makefile
target=main
object=main.o fun1.o fun2.o sum.o
CC=gcc
CPPFLAGS=-I./

$(target):$(object)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $< $(CPPFLAGS) 

#main.o:main.c
#	gcc -o main.o -c main.c -I./
#
#fun1.o:fun1.c
#	gcc -o fun1.o -c fun1.c
#
#fun2.o:fun2.c
#	gcc -o fun2.o -c fun2.c
#
#sum.o:sum.c
#	gcc -o sum.o -c sum.c
```
## 第四个版本:
```text
1.wildcard – 查找指定目录下的指定类型的文件
src=$(wildcard *.c)  //找到当前目录下所有后缀为.c的文件,赋值给src
2.patsubst – 匹配替换
obj=$(patsubst %.c,%.o, $(src)) //把src变量里所有后缀为.c的文件替换成.o

如: 当前目录下有a.c b.c c.c
    src=$(wildcard *.c) -----> src=a.c b.c c.c
    obj=$(patsubst %.c,%.o, $(src)) -----> obj=a.o b.o c.o
```
+ 例子
```makefile
src=$(wildcard ./*.c)
object=$(patsubst %.c, %.o, $(src))  # 将.c文件替换成.o文件

# object=main.o fun1.o fun2.o sum.o

target=main
CC=gcc
CPPFLAGS=-I./

$(target):$(object)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $< $(CPPFLAGS)

#main.o:main.c
#	gcc -o main.o -c main.c -I./
#
#fun1.o:fun1.c
#	gcc -o fun1.o -c fun1.c
#
#fun2.o:fun2.c
#	gcc -o fun2.o -c fun2.c
#
#sum.o:sum.c
#	gcc -o sum.o -c sum.c 
```
## 第五个版本:
```text
增加清理功能.
	终极目标: makefile文件中第一次出现的目标叫做终极目标
	.PHONY:clean
	clean:
		rm -f ....
		
	使用-f可以指定makefile文件, 如: make -f mainmak

    总结:
        如果不需要取别名
        可以先make clean
        然后make生成可执行文件
```
+ 例子
```makefile
src=$(wildcard ./*.c)
object=$(patsubst %.c, %.o, $(src))

# object=main.o fun1.o fun2.o sum.o

target=main
CC=gcc
CPPFLAGS=-I./

$(target):$(object)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $< $(CPPFLAGS) 

.PHONY:clean
clean:
	-rm -f $(target) $(object)

#main.o:main.c
#	gcc -o main.o -c main.c -I./
#
#fun1.o:fun1.c
#	gcc -o fun1.o -c fun1.c
#
#fun2.o:fun2.c
#	gcc -o fun2.o -c fun2.c
#
#sum.o:sum.c
#	gcc -o sum.o -c sum.c 
```

