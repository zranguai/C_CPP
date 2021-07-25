# 01-C语言基础
# day01
### C语言32关键字:
```
Auto(自动--->后面定义局部变量会用到他)  break  cas(switch case会用到的分支)  char  const(表示只读)
Continue default(switch里面用到)  do(配合while环)  double(代表双精度浮点数)  else
Enum(枚举类型)  extern(表示声明)  float(浮点数型)  for  goto
If  int  long  register(修饰变量存到寄存器里) return
Short(短整型)  signed(表示有符号)  sizeof(用来求某数据类型的大小)  static  struct(结构体)
Switch  typedef(给数据类型起别名)  unsigned  unio(共用体数据类型)  void(空类型)
Volatile(数据限定符-->防止编译器对编译程序进行优化) while
```
### 9种控制语句
```
If() ~else~
For()~
While()~
Do~while()
Continue
Break
Switch
Goto
return
```
### 34种运算符
```
算术运算符: + - * / % ++ --
关系运算符: < <= == > >=  !=
逻辑运算符: ! && ||
位运算符: <<  >>  ~  |  &
赋值运算符  =
条件运算符： ？：
逗号运算符:    ,
指针运算符:  *  &(取地址符)
求字节数：sizeof
强制类型转换:  (类型)
分量运算符:  ->
下标运算符: []
其他： （）
```
### 编译过程

gcc  helloworld.c  -o myhello.exe           -o：取别名

window下面的库都是以.DLL结尾的

停止的位置是尚未执行的函数
### VS常用快捷键
```
Ctrl +k, Ctrl + f                   自动格式化代码
Ctrl   + K, Ctrl + c                注释代码
Ctrl + k, Ctrl + u                  取消注释代码
F9                                  设置断点
F5                                  调试运行
Ctrl + F5                           不调试运行
Ctrl  + Shift  + b                  编译，不运行
F10                                 next调试
F11                                 step调式
```
## day01-Code
+ helloworld.c
```c
/*
#include <stdio.h>		// #:关键标识符，表示引入头文件； include：引入头文件关键字
						// stdio.h: 系统标准输入、输出库对应的头文件。 给printf函数服务。
						//<>: 使用系统库函数。  "": 用户自定义库函数。
int main(void)			//int: 函数返回值是整型数据。  mian：函数名。程序唯一的入口。必须有，且只有一次。 void：函数调用无需传参。
{						// 函数体 起始位置

	printf("hello world!\n");	// 将 “hellow world”写到屏幕上。 \n: 回车换行
	system("pause");			// 调用 syatem 函数， 实现暂停功能。 

	return 0;			// 返回当前函数调用 --- 退出程序。  0 要跟 main函数的返回值一一对应。
}// 函数体 结束位置
*/

#include <stdio.h>
#include <Windows.h>

int main01(void)			//int: 函数返回值是整型数据。  mian：函数名。程序唯一的入口。必须有，且只有一次。 void：函数调用无需传参。
{						// 函数体 起始位置
	printf("-----------hello world!\n");	// 将 “hellow world”写到屏幕上。 \n: 回车换行
	Sleep(2000);
	system("cls");			// 调用 syatem 函数， 实现清屏功能。 

	return 0;			// 返回当前函数调用 --- 退出程序。  0 要跟 main函数的返回值一一对应。
}
```
+ 加法运算.c
```c
#include <stdio.h>


int main(void)
{

	int a = 3;		// 定义 整型变量 a， 赋初值 3

	int b = 5;		// 定义 整型变量 b， 赋初值 5
	int c;			// 定义 整型变量 c， 无初值
	
	c = a + b;		// a + b ,将结果 赋值 给 c

	printf("hello world\n");

	// %d:格式匹配符，匹配整型数据

	printf("%d\n", c /*注释*/ );	


	printf("c = %d\n", c);

	printf("%d + %d = %d\n", a, b, c);

	printf("%d + %d = &d\n", a, b, a+b);

	return 0;
}
```
## 官方笔记：
```text
helloworld程序：


解决提示窗一闪而过：

	1. 通过 system()函数解决：

		在 return 0；之前 添加 system("pause"); 函数调用。

	2. 借助VS工具解决：
		
		在项目上 ---》右键 ---》 属性 ---》 配置属性 ---》 连接器 ---》 系统  ---》 子系统 

		---》 在下拉框中选择“控制台 (/SUBSYSTEM:CONSOLE)”

两种编写 helloworld 的方式：

	1. 借助VS编辑工具编写。
	
		创建项目 --》 创建 helloworld.c 源文件 --》 写 helloworld程序 --》Ctrl + F5 执行。 

	2. 借助记事本、gcc编译工具编写。

		gcc编译工具的环境变量配置：

			在QT的安装目录中找 gcc.exe 目录位置。例如： C:\Qt\Qt5.5.0\Tools\mingw492_32\bin

			我的电脑 --》属性 --》 高级系统设置 --》 环境变量 --》系统环境变量 --》 path --》 将gcc.exe 目录位置写入到 path的值中。

		使用记事本创建 helloworld.c 文件 ——》 在记事本中写 helloworld 程序 

		--》 使用gcc编译工具 ，在记事本写的 helloworld.c 所在目录中，执行 gcc helloworld.c -o myhello.exe  

		--》 在终端（黑窗口）中，运行 ： myhello.exe

单行注释：//	
	
多行注释：/* 注释内容 */ 

	不允许嵌套使用。 多行中可嵌套单行。

system 函数：

	执行系统命令。如： pause、cmd、calc、mspaint、notepad.....

	system("cmd");  system("calc");

	清屏命令：cls; system("cls");


gcc编译4步骤：【重点】

	1. 预处理	-E	xxx.i	预处理文件

		gcc -E xxx.c -o xxx.i

		1) 头文件展开。 --- 不检查语法错误。 可以展开任意文件。

		2）宏定义替换。 --- 将宏名替换为宏值。

		3）替换注释。	--- 变成空行

		4）展开条件编译 --- 根据条件来展开指令。

	2. 编译		-S	xxx.s	汇编文件

		gcc -S hello.i -o hello.s

		1）逐行检查语法错误。【重点】	--- 整个编译4步骤中最耗时的过程。

		2）将C程序翻译成 汇编指令，得到.s 汇编文件。

	3. 汇编		-c	xxx.o	目标文件

		gcc -c hello.s -o hello.o

		1）翻译：将汇编指令翻译成对应的 二进制编码。


	4. 链接		无	xxx.exe	可执行文件。

		gcc  hello.o -o hello.exe

		1）数据段合并

		2）数据地址回填

		3）库引入

调试程序：

	添加行号：

		工具--》选项 --》文本编辑器--》C/C++ --》行号 选中。

	1. 设置断点。F5启动调试

	2. 停止的位置，是尚未执行的指令。

	3. 逐语句执行一下条 （F11）：进入函数内部，逐条执行跟踪。

	3. 逐过程执行一下条 （F10）：不进入函数内部，逐条执行程序。

	4. 添加监视：

		调试 --》窗口 --》监视：输入监视变量名。自动监视变量值的变化。
```
# day02
## 官方笔记
```text
常量：不会变化的数据。不能被修改。

	1. “hello”、'A'、-10、3.1415926（浮点常量）	

	2. #define PI 3.1415	【强调】：没有分号结束标记。 【推荐】 定义宏： 定义语法： #define 宏名 宏值

	3. const int a = 10;	定义语法：const 类型名 变量名 = 变量值。

		const关键字： 被该关键字修饰的变量，表示为只读变量。


变量：会变化的数据。能被修改。

	定义语法：类型名 变量名 = 变量值。（一般方法）

	变量三要素：类型名、变量名、变量值。	int r = 3;	float s = PI*r*r;(变量值是一个表达式)

	变量的定义：	int a = 40;

	变量的声明：	1) int a;	 没有变量值的变量定义 叫做声明。

			2）extern int a; 添加了关键字 extern。

	1. 变量定义会开辟内存空间。变量声明不会开辟内存空间。

	2. 变量要想使用必须有定义。

		当编译器编译程序时，在变量使用之前，必须要看到变量定义。如果没有看到变量定义，编译器会自动找寻一个变量声明提升成为定义。
	
		如果该变量的声明前有 extern 关键字，无法提升。--->也就是说他仅仅用于声明


	【建议】：定义变量时。尽量不要重名。

标识符：

	变量和常量的统称。

	命名规则：	1. 通常常量使用大写、变量使用小写。大小写严格区分。

			2. 只能使用字母、数组、下划线（_）命名标识符。且，数字不能开头。 a-z/A-Z/0-9/_

				int a5ir = 10; ok

				int _34F = 6; ok

				float s2_i85c = 5.4;  ok

				int 98ti_54 = 4;  error.

			3. 禁止使用关键字和系统函数作为标识符名称。  main/system/printf/sleep....

sizeof关键字：

	不是函数。用来求一个变量、类型的大小。 返回一个 无符号整数。 使用 %u 接收返回值。

	方法1： sizeof（类型名）	-- sizeof(int)

	方法2： sizeof(变量名)		--- int a = 20； sizeof(a)

	【了解】： sizeof 变量名/类型名		举例1： sizeof int

						举例2： sizeof a

有符号整型：

	signed： 有符号 （超级不常用， 通常省略）：		int a = 10; a = -7;	

	int类型：	%d		4 字节			

		int 名 = 值;

	short类型：	%hd		2 字节

		short 名 = 值;		short s1 = 3;

	long类型：	%ld		4 字节		(windows: 32/64: 4字节； Linux：32位:4字节， 64位:8字节)	

		long 名 = 值;		long len = 6;

	long long 类型：%lld		8 字节

		long long 名= 值;	long long llen = 70;


无符号整型：

	unsigned： 无符号 		只表示数据量，而没有方向（没有正负）	

	unsigned int类型：	%u		4 字节

		unsigned int 名 = 值;	
		
		unsigned int a = 40;		

	unsigned short类型：	%hu		2 字节

		unsigned short 名 = 值;		

		unsigned short s1 = 3;

	unsigned long类型：	%lu		4 字节 (windows: 32/64: 4字节； Linux：32位:4字节， 64位:8字节)

		unsigned long 名 = 值;		

		unsigned long len = 6;

	unsigned long long 类型：%llu		8 字节

		unsigned long long 名 = 值;	

		unsigned long long llen = 70;

	
char字符类型：1字节

	存储一个字符。本质是ASCII码。 ‘A’、‘a’、‘%’、‘#’、‘0’

	格式匹配符： %c

	‘A’：65

	‘a’：97

	‘0’：48

	‘\n’:10

	‘\0’: 0

	
转义字符：

	‘\’	将普通字符转为 特殊意。 将特殊字符转为本身意。

	'\n' 和 ‘\0’


实型（浮点数、小数）：

	float：	单精度浮点型。		4字节

		float v1 = 4.345;

		%f格式匹配符。 默认保留 6 位小数。

	double：双精度浮点型。		8字节		【默认】

		double v2 = 5.678;

	unsigned float v1 = 4.345;	无符号的 float 数据

	unsigned double v2 = 5.678;	无符号的 float 数据

	printf("n = %08.3f\n", n);

		输出的含义为：显示8位数（包含小数点）， 不足8位用0填充。并且保留3位小数。对第4位做四舍五入。


进制和转换：

	十进制转2进制。	--- 除2反向取余法。 【重点】

	十进制转8进制。	--- 除8反向取余法。

	十进制转16进制。--- 除16反向取余法。

		int a = 56;	-- 111000

		int b = 173;    -- 10101101

	2进制转10进制。

		2^10 = 1024

		2^9 = 512

		2^8 = 256

		2^7 = 128

		2^6 = 64

		2^5 = 32

		2^4 = 16

		2^3 = 8

		2^2 = 4

8进制：

	8进制转10进制。	

		定义8进制数语法：	

			056： 零开头，每位数0~7之间。	---- 46

			0124： 				---- 84

	8进制转2进制。

		按421码将每个八进制位展开。

			056：5--》 101。 6--》 110  。

				101110

			05326：5 --》 101。 3--》 011。 2--》 010。 6--》 110

	2进制转8进制：

		1 010 111 010 110：	012726

		自右向左，每3位一组，按421码转换。高位不足三位补0
	
16进制：

	语法： 以0x开头，每位 取 0-9/A-F/a-f

			A -- 10

			B -- 11

			C -- 12

			D -- 13

			E -- 14

			F -- 15
	16 -- 10:

		0x1A:  16+10 = 26

		0x13F：15+3x16+256 
	
	16 -- 2:

		0x1A:	00011010

		0x13F：	000100111111

	2 -- 16:

		0001 0011 1111:		13F

		自右向左，每4位一组，按8421码转换。高位不足三位补0

总结：

	int m = 0x15F4;

	int n = 345;

	int var = 010011; // 不允许。 不能给变量直接复制 二进制数据。

	输出格式：

		%d %u %o %x %hd %hu %ld %lu %lld %llu %c %f %lf

		%d %u %x %c %s 

存储知识：

	1 bit位  就是一个 二进制位

	一个字节 1B = 8bit位。 

	1KB = 1024B
		
	1MB = 1024KB

	1GB = 1024MB

	1TB = 1024GB


源码反码补码：【了解】

	源码：
		43 -> 	00101011
		-43 -->  10101011

	反码：		
		43 -> 	00101011
		-43 --> 10101011
			  11010100
	
	补码：(现今计算机采用的存储形式)

		43 -> 	00101011	： 正数不变
		-43 --> 11010101	： 负数，最高位表符号位， 其余取反+1
	
43-27 ==》 43 + -27

		
	人为规定： 10000000 --》 -128
	  
-------------------------------------------------

	char 类型：1字节 8个bit位。 数值位有7个。   

		有符号: -2^7 --- 2^7-1  == -2^(8-1) -- 2(8-1) -1  

			--》 -128 ~ 127

		无符号： 0 ~ 2^8 -1 

			--》 0~255

		不要超出该数据类型的存储范围。


	short类型：2字节  16bit

		有符号: -2^15 --- 2^15-1  == -2^(16-1) -- 2(16-1) -1  

			--》 -32768 ~ 32767

		无符号： 0 ~ 2^8 -1 

			--》 0~65535		
	

	int 类型：4字节			-2^(32-1) -- 2^(32-1)-1

		有符号：

			--》 -2147483648 ~ 2147483647	

		无符号：		0~2^32 -1 

			--》 0~4294967295

	long类型：4字节

		有符号：

			--》 -2147483648 ~ 2147483647	

		无符号：		0~2^32 -1 

			--》 0~4294967295	

	longlong 类型：8字节


		有符号：
			--》 -2^(63) ~ 2^(63)-1	

		无符号：		

                        --》 0~2^63-1
```
## Code
+ 01常量
```c
#include <stdio.h>

#define PI 3.1415			// 常量

int main01(void)
{
	// 圆的面积  s = PI x 半径的平方
	// 圆的周长  l = 2 * PI * r	
	//int r = 3;				// 变量
	const int r = 3;		// 只读变量

	float s = PI * r * r;
	float l = 2 * PI * r;

	//printf("圆的周长为：%f\n", l);  //18.849001
	//printf("圆的面积为：%f\n", s);  //28.273500

	printf("圆的周长为：%.2f\n", l);	// 指定小数点后保留2位, 对第3位做，4舍五入
	printf("圆的面积为：%.2f\n", s);	// 指定小数点后保留2位

	return 0;
}
```
+ 02变量.c
```c
#include <stdio.h>

int main02(void)
{
	 int a;   // 显示的做变量a的声明

	a = 56;			// 变量使用、变量赋值。

	return 0;
}
```
+ 03-sizeof数据类型大小.c
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1024		// 定义常量

int main0301(void)
{
	int a = 10;		// 定义变量： 三要素

	short b = 20;

	long c = 30;
	long long d = 40;

	printf("================a===%d\n", sizeof(a));
	printf("================b===%d\n", sizeof(b));
	printf("================c===%d\n", sizeof(c));
	printf("================d===%d\n", sizeof(d));

	printf("int 大小为：%d\n", sizeof(int));
	printf("short 大小为：%d\n", sizeof(short));
	printf("long 大小为：%d\n", sizeof(long));
	printf("long long 大小为：%d\n", sizeof(long long));

	system("pause");

	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 3;
	short b = 4;
	long c = 5;			// 5L  5l
	long long d = 6;  // 5LL  5ll

	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(short) = %d\n", sizeof(short));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(long long) = %d\n", sizeof(long long));

	printf("--------------------------------------\n");

	unsigned int aun = 3;		// 3u
	unsigned short bun = 4;		// 3u
	unsigned long cun = 5;		// 3lu
	unsigned long long dun = 6;	// 3llu

	printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int)); // aun
	printf("sizeof(unsigned short) = %d\n", sizeof(unsigned short));
	printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long) = %d\n", sizeof(unsigned long long));
}
```
+ 04-无符号整型.c
```c
int main0401(void)
{
	size_t var = 10;
	printf("var = %u\n", var);

	unsigned int a = 10u;  // 简写成 unsigned int a = 10;
	unsigned short b = 20u;// 简写成 unsigned short b = 20;
	unsigned long c = 30Lu; 
	unsigned long long d = 40LLu;

	printf("unsigned int 型数据值：%u\n", a);
	printf("unsigned short 型数据值：%hu\n", b);
	printf("unsigned long 型数据值：%lu\n", c);
	printf("unsigned long long 型数据值：%llu\n", d);

	system("pause");

	return EXIT_SUCCESS;
}
```
+ 05-字符类型.c
```c
int main0501(void)
{
	char ch = 'A';  // 65

	//printf("1 ch = %c\n", ch);
	printf("1 ch = %d\n", ch);

	ch = 'm'; //

	//printf("2 ch = %c\n", ch);
	printf("2 ch = %d\n", ch);

	//ch = 97;
	ch = 'a';	// 97

	//printf("3 ch = %c\n", ch);
	printf("3 ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// A -- 65 a -- 97 
int main0502(void)
{
	char ch = 'M';
	char var = '5';

	printf("ch = %c\n", ch + 32);
	printf("var = %c\n", var+4);

	printf("'\\n\'的值为=%d\n", '\n');

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 06-实型.c
```c
int main0601(void)
{
	float m = 3.145;
	double n = 4.566545;

	printf("m = %08.2f\n", m);
	printf("n = %08.3lf\n", n);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 07-进制和转换.c
```c
int main0701(void)
{
	int a = 0x2C;  // 等价 0x2c 

	printf("10进制显示 a = %d\n", a);
	printf("8进制显示 a = %o\n", a);
	printf("16进制显示 a = %x\n", a);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 08-数据溢出.c
```c
int main(void)
{

	char ch = 127+1;		// -128 -- 127

	printf("ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}
```
# day03
### Vs code配置c/c++
```text
插件:
	C/C++
	
	
/// 相关下载 （for windows） ///
mingw64下载 官方：https://sourceforge.net/projects/mingw-w64/
mingw64下载 网盘： https://pan.baidu.com/s/1_gdaid7yvGTqN2xikoEUmQ 提取码: ne84
VS Code下载: https://code.visualstudio.com
CMake下载：https://cmake.org/download/

（Mac和Linux请用系统的包管理器自己装这些工具

/// 相关文档 ///
vscode c/c++ 相关文档：https://code.visualstudio.com/docs/languages/cpp
cmake-tools 文档：https://vector-of-bool.github.io/docs/vscode-cmake-tools/index.html
clang-format 文档：https://clang.llvm.org/docs/ClangFormatStyleOptions.html

 ------------------------------ 2020.3.3 ------------------------------
（本视频具有时效性，不保证在后续版本依然可用，一切以官方最新文档为准）



C++书籍
看书顺序由浅到深
第一本  Essential C++   (由c过度到c++）
第二本  C++ Primer第四版 (内容很全，但是不深）
第三本  Effeetive C++
第四本  More Effeetive C++
第五本  C++  标准程序库
第六本  深入探索C++对象模型 
```
### c语言概述
```text
c语言最重要的就是指针和内存管理

书籍推荐:
	1. 《C Primer Plus》
	进阶:
	 2.《C和指针》
	3. 《C专家编程》
	
基础4大件:
学习编程的基础四大件
数据结构和算法 学完之后要刷leetcode（剑指offer）

计算机网络 tcp/ip 协议栈《tcp/ip详解》

操作系统 进程和线程 并发 和锁 内存分布调度等等 《深入理解操作系统》

设计模式 单例 工厂 代理 策略模式 模版方法《大话设计模式》


实践
Linux操作系统掌握 shell编程 脚本等等
《鸟哥的Linux私房菜》《Linux就该这么学》
编译/调试工具 Linux平台上 gcc 以及makefile（《跟我一起写makefile》陈皓）要会写 gdb调试工具(《debugging with gdb》中文版)

Linux系统编程  ！
多线程编程 网络编程
《unix环境高级编程》(必看)《Linux高性能服务器编程》《posix多线程程序设计》
```
## 官方笔记
```text
extern：
	表示声明。 没有内存空间。 不能提升。

const：
	限定一个变量为只读变量。

volatile：

	防止编译器优化代码。

	volatile int flg = 0; 

register：

	定义一个寄存器变量。没有内存地址。

	register int a = 10;	

字符串：

	C语言中，用双引号引着的一串字符，称之为字符串。一定有一个结束标记'\0'

	char ch = ‘A’;  一个字节

	"abc"  --> 'a''b''c''\0'

	‘a’ 不等价 “a”（'a''\0'）

printf函数：

	%s：打印字符串， 挨着从字符串的第一个字符开始打印，打印到'\0'结束。

	%d：打印整数

	%c：打印字符

	%x：打印16进制数

	%u：打印无符号

	%m.n: 打印实型时用到，一共有 m 位(整数、小数、小数点)，n位小数。

	%0m.nf: 其中 f：表示打印实型，一共有 m 位(整数、小数、小数点)，n位小数。 0：表示不足 m 位时，用0凑够m位。

	%%： 显示一个%。 转义字符'\' 对 % 转义无效。

	%Ns：显示N个字符的字符串。不足N用空格向左填充。

	%0Ns：显示N个字符的字符串。不足N用0向左填充。

	%-Ns：显示N个字符的字符串。不足N用空格向右填充。

putchar函数：

	输出一个 字符 到屏幕。

	直接使用 ASCII 码。

	不能输出字符串。

	‘abc’既不是一个有效字符，也不是一个有效字符串。

	常用putchar('\n');来打印换行。

	printf("\n");

scanf函数：

	从键盘接收用户输入。

	1. 接收 整数 %d

		int a, b, c;  创建变量空间， 等待接收用户输入。

		scanf("%d %d %d", &a, &b, &c);

	2. 接收 字符 %c

		char a, b, c;
	
		scanf("%c %c %c", &a, &b, &c);
	
	3. 接收 字符串 %s

		char str[10];	// 定义一个数组，用来接收用户输入的 字符串。

		scanf("%s", str);	// 变量名要取地址传递给 scanf， 数组名本身表示地址，不用 & 符。

	接收字符串：

		1） scanf 具有安全隐患。如果存储空间不足，数据能存储到内存中，但不被保护。【空间不足不要使用】

		2） scanf 函数接收字符串时， 碰到 空格 和 换行 会自动终止。不能使用 scanf 的 %s 接收带有空格的字符串。

		
	将 #define _CRT_SECURE_NO_WARNINGS  添加到程序 第一行。 解决scanf 4996错误   ---》(4996问题是使用vs会出现的问题，在linux环境下没有这个问题)


getchar()函数：

	从键盘获取用户输入的 一个字符。

	返回该获取的字符的 ASCII 码。


算数运算符：

	先 * / % 后 + -

	除法运算后，得到的结果赋值给整型变量时，取整数部分。

	除0 ：错误操作。不允许。

	对0取余：错误操作。不允许。

	不允许对小数取余。余数不能是 小数。 35 % 3.4;

	对负数取余，结果为余数的绝对值。10 % -3;  --》 1

++ 和 --：

	前缀自增、自减：

		先自增/自减， 在取值。

		int a = 10;

		++a;		// a = a+1;

	后缀自增、自减:

		int a  = 10;

		a++;		// a = a+1;

		先取值， 再自增/自减。

赋值运算：

	int a = 5;

	a += 10;  // a = a+10;

	a -= 30;  // a = a-30;

	a %= 5;	  // a = a % 5;

比较运算符：

	== 判等。

	!= 不等于.

	< 小于

	<= 小于等于	

	> 大于

	>= 大于等于


	13 < var < 16; ==> var > 13 && var < 16;

逻辑运算符：

	0为假，非0为真。（1）

	逻辑非：!

		非真为假， 非假为真。

	逻辑与： &&（并且）

		同真为真，其余为假。

	逻辑或：|| （或）

		有真为真。同假为假。
	
运算符优先级：

	[]() > ++ -- (后缀高于前缀) (强转) sizeof > 算数运算（先乘除取余，后加减）> 

	比较运算 > 逻辑运算 > 三目运算（条件运算）> 赋值运算 > 逗号运算	


三目运算符： ? :

	表达式1 ？ 表达式2 : 表达式3

	表达式1 是一个判别表达式。 如果为真。整个三目运算，取值表达式2。

				    如果为假。整个三目运算，取值表达式3。

	默认结合性。自右向左。

类型转换：

	隐式类型转换：

		由编译器自动完成。

		由赋值产生的类型转换。 小--》大 没问题。 大 --》 小 有可能发生数据丢失。

		int r = 3;

		float s = 3.14 * r * r;

		321:	256 128 64 32 16 8 4 2 1
			1   0   1  0  0  0 0 0 1 

		char ch  = 0   1  0  0  0 0 0 1 	

	强制类型转换：

		语法：	（目标类型）带转换变量

			（目标类型）带转换表达式

		大多数用于函数调用期间，实参给形参传值。


if分支语句：匹配一个范围.属于模糊匹配.

	if (判别表达式1)
	{
		
		判别表达式为真，执行代码。
	}
	else if(判别表达式2)
	{
		判别表达式1为假，并且判别表达式2，执行代码。

	}
	else if(判别表达式3)
	{
		判别表达式1为假，判别表达式2为假，判别表达式3， 执行代码。
	}
	。。。
	else
	{
		以上所有判断表达式都为假， 执行代码。
	}

练习：三只小猪称体重：

		
	屏幕输入三只小猪的重量。借助if分支语句，找出最重的小猪重量。


switch 分支：精确匹配.

	switch(判别表达式)
	{
		
		case 1：
			执行语句1；
			break;			// 防止case穿透

		case 2:
			执行语句2;
			break;

		case 3:
			执行语句3;
			break;
		...

		case N:
			执行语句N;
			break;

		default:
			其他情况的统一处理;
			break;
	}

	case 穿透：

		在一个case分支中如果,没有break;那么它会向下继续执行下一个case分支.

		
while循环:

	while(条件判别表达式)
	{

		循环体.
	}

练习：敲7：1--100数数， 逢7和7的倍数，敲桌子。

	7的倍数：	num % 7 == 0

	个位含7：	num % 10 == 7

	十位含7：	num / 10 == 7


do while 循环:

	无论如何先执行循环体一次。然后在判断是否继续循环。

	do {

		循环体

	} while (条件判别表达式);

	
练习：求水仙花数。 一个三位数。各个位上的数字的立方和等于本数字。  	234   861

	100 -- 999

	int num  = 100;

	个位数： int a = num % 10;   		a*a*a;

	十位数： int b = num / 10 % 10; 

	百位数： int c = num / 100;
```
## Code
+ 01-字符串输出.c
```c
int main0101(void)
{
	char ch = 'a';

	printf("ch = %c\n", ch);

	char str[20] = "hello world";

	printf("str = %s\n", str);

	system("pause");
	return EXIT_SUCCESS;
}

int main0102(void)
{
	char str[] = "hello world";

	printf("str = |%-15s|\n", str);

	system("pause");
	return EXIT_SUCCESS;
}

int main0103(void)
{
	putchar(97);  // 'a' == 97
	putchar('b');
	putchar('c');
	putchar('d');

	putchar('abcZ');

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 02-格式化输入.c
```c
// 获取用户输入 整数
int main0201(void)
{
	int a;

	scanf("%d", &a);		// &：表示取出变量a的地址。描述a的空间

	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0202(void)
{
	char ch1, ch2, ch3;	//	连续定义同类型多个变量。

	scanf("%c%c%c", &ch1, &ch2, &ch3);	// &：表示取出变量ch的地址。描述a的空间

	printf("ch1 = %c\n", ch1);
	printf("ch2 = %c\n", ch2);
	printf("ch3 = %c\n", ch3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0203(void)
{
	int a1, a2, a3;	//	连续定义同类型多个变量。

	scanf("%d %d %d", &a1, &a2, &a3);	// &：表示取出变量ch的地址。描述a的空间

	printf("a1 = %d\n", a1);
	printf("a2 = %d\n", a2);
	printf("a3 = %d\n", a3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0204(void)
{
	char a[5];			// 大小为5字节的数组

	scanf("%s", a);		// 接收用户键盘输入，写入数组a中

	printf("a = %s\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0205(void)
{
	char a[50];			// 大小为50字节的数组

	scanf("%s", a);		// 接收用户键盘输入，写入数组a中

	printf("a = %s\n", a);

	system("pause");

	return EXIT_SUCCESS;
}

int main0206(void)
{
	char ch;

	ch = getchar();		// 接收用户输入，返回接收到的ASCII码

	printf("ch = %c\n", ch);

	putchar(ch);
	putchar('\n');

	system("pause");

	return EXIT_SUCCESS;
}
```
+ 03-算数运算符.c
```c
int main0301(void)
{
	int a = 10;
	int b = 20;

	int c = a * b;

	int d = 34 / 10;  // 0.5

	//int m = 98 / 0;

	//printf("m = %d\n", m);

	system("pause");
	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 10;
	int b = 50;

	printf("a = %d\n", a++);  // 先取值给%d, 在自增

	printf("----a = %d",a);



	printf("b = %d\n", ++b);  // 先自增,再取值。 

	printf("----b = %d\n", b);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 04-逻辑运算.c
```c
int main0401(void)
{
	int a = 34;
	int b = 0;

	char str[10] = "hello";

	++str[0];

	printf("a = %d\n", !a);
	printf("b = %d\n", !b);

	printf("======%d\n", a && !b);

	printf("------%d\n", !a || b);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 05-三目运算.c
```c
// 三目运算
int main0501(void)
{
	int a = 40;
	int b = 4;

	int m = a < b ? 69 : a<b?3:5;  // 嵌套的 三目运算

	printf("m = %d\n", m);

	printf("%d\n", a>b ? 69 : 100);

	system("pause");
	return EXIT_SUCCESS;
}

// 逗号运算符
int main0502(void)
{
	int a = 10, b = 20, c = 30;

	int x = (a = 1,  c = 5, b = 2);		// 逗号运算符。

	printf("x = %d\n", x);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 06-隐式类型转换和强制类型转换.c
```c
// 隐式类型转换。
int main0601(void)
{
	int a = 321;		

	char ch = a;

	printf("ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// 强制类型转换
int main0602(int var)
{
	//int *p = (int *)malloc(100);

	float price = 3.6;
	int weight = 4;

	//double sum = (int)price * weight;

	double sum = (int)(price * weight);

	printf("价格：%lf\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 07-if分支.c
```c
int main0701(void)
{
	int a;
	scanf("%d", &a);

	if (a > 0)
	{
		printf("a > 0\n");
	}
	else
	{
		printf("a <= 0\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}

//成绩
int main0702(void)
{
	int score;		// 100--90 优 90 -- 70 良好 70 -- 60 及格  < 60 差劲

	printf("请输入学生成绩：");
	scanf("%d", &score);

	if (score>=90 && score <=100)
	{
		printf("优秀\n");
	} 
	else if(score < 90 && score >=70)
	{
		printf("良好\n");
	}
	else if (score < 70 && score >= 60)
	{
		printf("及格\n");
	}
	else
	{
		printf("不及格\n");
	}



	system("pause");
	return EXIT_SUCCESS;
}

// 三只小猪秤体重
int main0703(void)
{
	int pig1, pig2, pig3;

	// if (pig1 > pig2 && pig1 > pig3)
	// pig1 > pig2 ? pig1 : pig2;

	printf("请输入三只小猪的体重:");
	scanf("%d %d %d", &pig1, &pig2, &pig3);

	if (pig1 > pig2)		// 满足，说明pig1最重
	{
		if (pig1 > pig3)
		{
			printf("第一只小猪最重，体重为：%d\n", pig1);
		}
		else
		{
			printf("第3只小猪最重，体重为：%d\n", pig3);
		}
	}   
	else
	{
		if (pig2 > pig3)
		{
			printf("第2只小猪最重，体重为：%d\n", pig2);
		}
		else
		{
			printf("第3只小猪最重，体重为：%d\n", pig3);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 08-switch分支.c
```c
int main0801(void)
{
	int score;
	scanf("%d", &score);

	switch (score/10)
	{
	case 10:		//	 100 -- 90 优秀
	case 9:	    
		printf("优秀\n");
		break;
	case 8:			//   70 -- 90 良好
	case 7:
		printf("良好\n");
		//break;
	case 6:		   // 70 - 60 及格
		printf("及格\n");
		//break;
	default:
		printf("不及格\n");
		break;		
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 09-while循环.c
```c
// 敲 7 
int main0901(void)
{
	int num = 1;

	while (num <= 100)
	{
		if ((num % 7 == 0) || (num % 10 == 7) || (num / 10 == 7))		// 个位、10位、7的倍数
		{
			printf("敲桌子\n");
		}
		else
		{
			printf("%d\n", num);
		}
		num++;  // 递增
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 10-dowhile.c
```c
// while 的基础用法
int main1001(void)
{
	int a = 1;
	do
	{
		a++;
		printf("a = %d\n", a);
	} while (a < 10);

	system("pause");
	return EXIT_SUCCESS;
}

// 水仙花数：一个三位数。各个位上的数字的立方和等于本数字。 
int main1002(void)
{
	int a, b, c;
	int num = 100;

	do {
		a = num % 10;		// 个位
		b = num / 10 % 10;	// 十位
		c = num / 100;		// 百位

		if (a*a*a + b*b*b + c*c*c == num)
		{
			printf("%d\n", num);
		}
		num++;

	} while (num < 1000);

	system("pause");
	return EXIT_SUCCESS;
}
```
# day04
## 官方笔记
```text
for循环：

	for (表达式1; 表达式2 ; 表达式3)	
	{
		循环体。
	}

	表达式1 --》 表达式2 （判别表达式） --》 为真 --》 循环体。--》 表达式3 --》 表达式2 （判别表达式） --》 为真 --》 循环体 --》 表达式3

	--》 表达式2 （判别表达式）。。。。

	1--100的和： 5050

	1+2+3+4+5+6...+100

	int sum = 0;
	int i = 0;	

	for (; ; )
	{
		sum = sum + i;
		i++
	}

循环因子：
	
	定义在for之外，for循环结束，也能使用。

	定义在for之内，for循环结束，不能使用。


for的3个表达式，均可变换、省略。但，2个分号不能省！

	for (i = 1, a = 3;i < 10, a < 20; i++, a+=5)
	{
		printf("i = %d\n", i);
		printf("a = %d\n", a);
		a += 5;
	}

	for(;;) == while(1)  无限循环
  

练习：猜数字游戏：

	1. 生成一个随机数。 

		1）添加一个随机数种子。srand(time(NULL));

		2) 添加头文件 <stdlib.h> <time.h>

		3) 生成随机数 int n = rand() % 100;  0-99

	2. 循环输入数据猜。

		int num;

		while（1）		// 死循环  for(;;)
		{
			接收用户输入 scanf("%d", &num);

			比较用户的数 和 随机生成数 大小。

			if (n > num)

			else
				break;
		}

	3. 跳出循环

		break;
			
break:

	作用1： 跳出一重循环。 for、while、do while

	作用2： 防止case穿透。 switch 	


嵌套循环：

	外层循环执行一次，内层循环执行一周。

	for（i = 0; i < 24; i++）
	{
		for(j = 0; j< 60; j++)
		{

			for（k = 0； k< 60; i++）
			{			
			}
		}
	}

练习：	模拟电子表打印：

	10:23:45
	10:23:46
	。。。
	10:24:00

	// 小时
	for (i = 0; i < 24; i++)
	{
		// 分钟
		for (j = 0; j < 60; j++)
		{
			// 秒
			for (k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(960);					// #include <Windows.h>
				system("cls");  // 清屏
			}
		}
	}

练习：	打印9x9乘法表：
	
1x1 = 1
1x2 = 2 	2x2 = 4
1x3 = 3 	2x3 = 6 	3x3 = 9
1x4 = 4
。。。
1x9 = 9	。。。。。。。。。。。。。。。。。。。。9x9 = 81

	外层循环执第i行， 内层执行i列。

	for(i=1; i<=9; i++)  	// 行
	{
		for(j = 1; j <= i; j++)  //列
		{
			printf("%dx%d=%d\t", j, i, j*i);
		}
		printf("\n");  putchar('\n');
	}

思考题：

	如何打印如下99乘法表呢？

1x9= 9 2x9=18 3x9=27 4x9=36 5x9=45 6x9=54 7x9=63 8x9=72 9x9=81
1x8= 8 2x8=16 3x8=24 4x8=32 5x8=40 6x8=48 7x8=56 8x8=64
1x7= 7 2x7=14 3x7=21 4x7=28 5x7=35 6x7=42 7x7=49
1x6= 6 2x6=12 3x6=18 4x6=24 5x6=30 6x6=36
1x5= 5 2x5=10 3x5=15 4x5=20 5x5=25
1x4= 4 2x4= 8 3x4=12 4x4=16
1x3= 3 2x3= 6 3x3= 9
1x2= 2 2x2= 4
1x1= 1

	for (i = 9; i >= 1; i--)		// 行
	{
		for(j = 1; j <= i; j++)		// 列
		{
			printf("%dx%d=%d\t", j, i, j*i);

		}
		putchar('\n');
	}

跳转语句：

break:【重点】

	作用1： 跳出一重循环。 for、while、do while

	作用2： 防止case 穿透。 switch 	

continue：【重点】

	
	作用：结束【本次】循环， continue关键字，之后的循环体，这本次循环中，不执行。


goto：	【了解】

	1. 设定一个标签

	2. 使用“goto 标签名” 跳转到标签的位置。（只在函数内部生效）

--------------------------------------------------------------------------------

数组：
	相同数据类型的有序连续存储。

	int arr[10] = {1, 2, 23, 4, 5, 6 , 10, 7, 8, 9};

	各个元素的内存地址 连续。

	数组名为地址。是数组首元素的地址。 arr == &arr[0];

	printf("数组大小：%u\n", sizeof(arr));

	printf("数组元素的大小：%u\n", sizeof(arr[0]));

	printf("数组元素个数：%d\n", sizeof(arr)/ sizeof(arr[0]));

	数据的第一个元素下标： 0

	数据的最后一个元素下标： sizeof(arr)/ sizeof(arr[0]) - 1

数组初始化：

	int arr[12] = { 1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 , 6, 8 }; 【重点】

	int arr[10] = { 1, 2 ,4, 6, 76, 8, 9 };  剩余未初始化的元素，默认 0 值。 【重点】

	int arr[10] = { 0 }; 初始化一个全为 0 的数组。【重点】

	int arr[] = {1, 2, 4, 6, 8}; 	编译器自动求取元素个数  【重点】

	int arr[] = {0};  只有一个元素，值为0

	int arr[10]; 
	arr[0] = 5;
	arr[1] = 6;
	arr[2] = 7;	其余元素未被初始化，默认值 随机数。


练习：	数组元素逆序：

	int arr[] = {1, 6, 8, 0, 4, 3, 9, 2};  // {2, 9, 3, 4, 0, 8, 6, 1}
	int len = sizeof(arr) / sizeof(arr[0]); //数组元素个数

	int i = 0;				// i表示数组的首元素下标
	int j = len - 1;		// 表示数组的最后一个元素下标
	int xixi = 0;		// 临时变量 

	// 交换 数组元素，做逆序
	while (i < j)
	{
		xixi = arr[i];		// 三杯水法变量交换
		arr[i] = arr[j];
		arr[j] = xixi;
		i++;
		j--;
	}


练习：	冒泡排序：

	int xjp[10] = {12, 32, 14, 62, 27, 8, 89};  --> 8 12 14 27 32 62 89

	for (size_t i = 0; i < n-1; i++)		// 外层控制行
	{
		for (size_t j = 0; j < n - 1 - i; j++)	// 内层控制列
		{
			if (xjp[j] > xjp[j + 1])		// 满足条件 三杯水交换
			{
				temp = xjp[j];
				xjp[j] = xjp[j + 1];
				xjp[j + 1] = temp;
			}
		}
	}
```
## Code
+ 01-for循环
```c
/ 基础for循环
int main0101(void)
{
	int i = 0;		// 循环因子
	int sum = 0;

	for (i = 1; i <= 100; i++)
	{
		sum = sum + i;  //sum += i;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式1
int main0102(void)
{
	int i = 1;		// 循环因子
	int sum = 0;

	for (; i <= 100; i++)
	{
		sum = sum + i;  //sum += i;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式3
int main0103(void)
{
	int i = 1;		// 循环因子
	int sum = 0;

	for (; i <= 100; )
	{
		sum = sum + i;  //sum += i;
		i++;
	}

	printf("sum = %d\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}

// 省略表达式123
int main0104(void)
{
	int i = 0;		// 循环因子

	//for (;1;)		// 死循环。while(k=1)
	for (;;)
	{
		printf("i = %d\n", i);
		i++;
	}

	system("pause");
	return EXIT_SUCCESS;
}

// 表达式有多个
int main0105(void)
{
	int i = 0;
	int a = 0;

	for (i = 1, a = 3;a < 20; i++)
	{
		printf("i = %d\n", i);
		printf("a = %d\n", a);
		a += 5;
	}
	system("pause");
	return EXIT_SUCCESS;
}
```
+ 02-猜数字游戏.c
```c
int main0201(void)
{
	srand(time(NULL));	//种随机数种子。

	int n = 0;
	int num = rand() % 100;  // 生成随机数

	for (;;)  // while(1)
	{
		printf("请输入猜测的数字：");
		scanf("%d", &n);
		if (n < num)
		{						// for、while、if 如果执行语句只有一条。 { } 可以省略
			printf("猜小了\n");
		}
		else if (n > num)	
			printf("猜大了\n");	
		else
		{
			printf("猜中！！！\n");
			break;			// 跳出
		}
	}
	printf("本尊是：%d\n", num);

	system("pause");

	return 0;
}
```
+ 03-模拟电子表.c
```c
int main0301(void)
{
	int i, j, k;

	// 小时
	for (i = 0; i < 24; i++)
	{
		// 分钟
		for (j = 0; j < 60; j++)
		{
			// 秒
			for (k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(960);
				system("cls");  // 清屏
			}
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 04-打印99乘法表.c
```c
/ 正序99乘法表
int main0401(void)
{
	for (size_t i = 1; i <=9; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			printf("%dx%d=%d\t", j, i, j*i);
		}
		printf("\n");
	}
	system("pause");
	return EXIT_SUCCESS;
}

// 倒序 99 乘法表
int main0402(void)
{
	int i, j;

	for (i = 9; i >= 1; i--)		// 行
	{
		for (j = 1; j <= i; j++)		// 列
		{
			printf("%dx%d=%d\t", j, i, j*i);
		}
		putchar('\n');
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 05-continue.c
```c
int main0501(void)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 3)
		{
			continue; 
		}
		printf("i = %d\n", i);
		printf("============1=========\n");
		printf("============2=========\n");
		printf("=============3========\n");
		printf("============4=========\n");
		printf("=============5========\n");

	}

	system("pause");
	return EXIT_SUCCESS;
}


int main0502(void)
{
	int num = 5;

	//while (num--)  // 当num自减为 0 时循环终止。  等价于 while (num-- != 0)

	while (num-- != 0) // 当num自减为 0 时循环终止。
	{ 
		printf("num = %d\n", num);
		if (num == 3)
		{
			continue;
		}
		printf("============1=========\n");
		printf("============2=========\n");
		printf("=============3========\n");
		printf("============4=========\n");
		printf("=============5========\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 06-goto.c
```c
int main0601(void)
{
	printf("============1==========\n");
	printf("============2==========\n");
	goto LABLE;

	printf("============3==========\n");
	printf("============4==========\n");
	printf("============5==========\n");
	printf("============6==========\n");
	printf("============7==========\n");

LABLE:
	printf("============8==========\n");
	printf("============9==========\n");
	printf("============10==========\n");

	system("pause");
	return EXIT_SUCCESS;
}

int main0602(void)
{
	int i = 0;

	for ( i = 0; i < 10; i++)
	{
		if (i == 5)
			goto ABX234;

		printf("i = %d\n", i);
	}

	for (int j = 0; j < 20; j++)
	{
ABX234:
		printf("j = %d\n", j);
	}

	system("pause");
	return 0;
}
```
+ 07-数组.c
```c
int main0701(void)
{
	int a = 5, b = 29, c = 10;

	int arr[10] = {1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 };  //int a = 109;

	printf("&arr[0] = %p\n", &arr[0]);  // 取数组首元素的地址

	printf("arr = %p\n", arr);		// 数组名

	system("pause");
	return EXIT_SUCCESS;
}

int main0702(void)
{
	int a = 5, b = 29, c = 10;

	int arr[12] = { 1, 2 ,4, 6, 76, 8, 90 ,4, 3, 6 , 6, 8};  //int a = 109;

	printf("数组大小：%u\n", sizeof(arr));

	printf("数组元素的大小：%u\n", sizeof(arr[0]));

	printf("数组元素个数：%d\n", sizeof(arr)/ sizeof(arr[0]));

	system("pause");
	return EXIT_SUCCESS;
}

// 数组初始化
int main0703(void)
{
	int arr[10];  //int a = 109;
	arr[0] = 5;
	arr[1] = 6;
	arr[2] = 7;
		
	int n = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 08-数组逆序.c
```c
// 数组元素逆序
int main0801(void)
{
	int arr[] = {1, 6, 8, 0, 4, 3, 9, 2};  // {2, 9, 3, 4, 0, 8, 6, 1}
	int len = sizeof(arr) / sizeof(arr[0]); //数组元素个数

	int i = 0;				// i表示数组的首元素下标
	int j = len - 1;		// 表示数组的最后一个元素下标
	int xixi = 0;		// 临时变量 

	// 交换 数组元素，做逆序
	while (i < j)
	{
		xixi = arr[i];		// 三杯水法变量交换
		arr[i] = arr[j];
		arr[j] = xixi;
		i++;
		j--;
	}
	// 打印交互后的 数组
	for (size_t n = 0; n < len; n++)
	{
		printf("%d ", arr[n]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
````
+ 09-冒泡排序.c
```c
int main0901(void)
{
	int xjp[] = { 12, 32, 14, 62, 27, 8, 89 };

	int n = sizeof(xjp) / sizeof(xjp[0]);	// 数组元素个数

	int temp = 0;		// 临时变量

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	// 完成乱序数组的冒泡排序。
	for (size_t i = 0; i < n-1; i++)		// 外层控制行
	{ 
		for (size_t j = 0; j < n - 1 - i; j++)	// 内层控制列
		{
			if (xjp[j] > xjp[j + 1])		// 满足条件 三杯水交换
			{
				temp = xjp[j];
				xjp[j] = xjp[j + 1];
				xjp[j + 1] = temp;
			}
		}
	}

	// 打印排序后的数组，确定正确性。
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
```
# Day05
## 官方笔记
```text
二维数组：

	int arr[10] = {1,2,3,5,6,7};

	{1,2,3,5,6,7};
	{1,2,3,5,6,7};
	{1,2,3,5,6,7};
	{1,2,3,5,6,7};

	定义语法：

	int arr[2][3] = 
		{
		{2, 5, 8},
		{7, 9 10}
		};

	int arr[3][5] = {{2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78}};

	打印：
		for(i = 0; i < 3; i++)		// 行
		{
			for(j = 0; j <5; j++)   // 列
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}		

大小：

	数组大小: sizeof(arr);

	一行大小: sizeof(arr[0])： 二维数组的一行，就是一个一维数组。

	一个元素大小:sizeof(arr[0][0])		单位：字节

	行数：row = sizeof(arr)/ sizeof(arr[0])

	列数：col = sizeof(arr[0])/ sizeof(arr[0][0])

地址合一：

	printf("%p\n", arr); == printf("%p\n", &arr[0][0]); == printf("%p\n", arr[0]);

	数组的首地址 == 数组的首元素地址 == 数组的首行地址。


二维数组的初始化：

	1）常规初始化：

		int arr[3][5] = {{2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78}};

	2) 不完全初始化：

		int arr[3][5] = {{2, 3}, {2, 67, 4, }, {1, 4, 16, 78}};  未被初始化的数值为 0 

		int arr[3][5] = {0};	初始化一个 初值全为0的二维数组

		int arr[3][5] = {2, 3, 2, 67, 4, 1, 4, 16, 78};   【少见】 系统自动分配行列。

	3）不完全指定行列初始化：

		int arr[][] = {1, 3, 4, 6, 7};  二维数组定义必须指定列值。

	  	int arr[][2] = { 1, 3, 4, 6, 7 };  可以不指定行值。


练习：求出5名学生3门功课的总成绩。（一个学生的总成绩。一门功课的总成绩）

	int scores[5][3];

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);

	// 获取 5 名学生、3门功课成绩
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			scanf("%d", &scores[i][j]);
		}
	}
	// 求一个学生的总成绩
	for (size_t i = 0; i < row; i++) // 每个学
	{
		int sum = 0;
		for (size_t j = 0; j < col; j++)// 每个学生的成绩
		{
			sum += scores[i][j];
		}
		printf("第%d个学生的总成绩为：%d\n", i+1, sum);
	}
	//求一门功课的总成绩
	for (size_t i = 0; i < col; i++)  // 第几门功课
	{
		int sum = 0;
		for (size_t j = 0; j < row; j++)  // 每门功课的第几个学生
		{
			sum += scores[j][i];
		}
		printf("第%d门功课的总成绩为：%d\n", i + 1, sum);
	}

快捷导入代码：

	VS --》 工具--》 代码片段管理器 --》 Visual C++


多维数组：【了解】

	三维数组：[层][行][列]

	数组类型 数组名[层][行][列];

	int arr[3][3][4];

	{ {12, 3, 4, 5}
	  {12, 3, 4, 5} },

	{ {12, 3, 4, 5}
	  {12, 3, 4, 5} },

	{ {12, 3, 4, 5}
	  {12, 3, 4, 5} },

	for(i = 0; i < 3; i++)  层

		for (j = 0; j < 3; j++)  行

			for (k = 0; k<4; k++)  列

				printf("%d ", arr[i][j][k]);

	4维、5维、6维。。。N维。


int arr[10];

short arr[20];

long long arr[20];


字符数组 和 字符串区别：

	字符数组： 
		char str[5] = {'h', 'e', 'l', 'l', 'o'};	

	字符串：
		char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

		char str[6] = "hello";

		printf("%s");	使用printf打印字符串的时候，必须碰到 \0 结束。
		

练习：键盘输入字符串，存至str[]中，统计每个字母出现的次数。

	for (size_t i = 0; i < 10; i++)
	{
		scanf("%c", &str[i]);
	}

	int count[26] = {0};  // 代表26个英文字母出现的次数。 

	for (size_t i = 0; i < 11; i++)
	{
		int index = str[i] - 'a';	// 用户输入的字符在 count数组中的下标值。
		count[index]++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c字符在字符串中出现 %d 次\n", i+'a', count[i]);
		}
	}

字符串获取 scanf：

	注意：	1）用于存储字符串的空间必须足够大，防止溢出。 char str[5];

		2) 获取字符串，%s， 遇到空格 和 \n 终止。

	借助“正则表达式”, 获取带有空格的字符串：scanf("%[^\n]", str);


字符串操作函数：

	gets： 从键盘获取一个字符串， 返回字符串的首地址。 可以获取带有 空格的字符串。 【不安全】

		char *gets(char *s);

			参数：用来存储字符串的空间地址。

			返回值：返回实际获取到的字符串首地址。
	

	fgets: 从stdin获取一个字符串， 预留 \0 的存储空间。空间足够读 \n, 空间不足舍弃 \n  【安全】

		char *fgets(char *s, int size, FILE *stream);

			参1：用来存储字符串的空间地址。

			参2：描述空间的大小。

			参3：读取字符串的位置。	键盘 --》 标准输入：stdin

			返回值：返回实际获取到的字符串首地址。


	puts：将一个字符串写出到屏幕. printf("%s", "hello"); / printf("hello\n"); / puts("hello");   输出字符串后会自动添加 \n 换行符。

		int puts(const char *s);	

			参1：待写出到屏幕的字符串。

			返回值： 成功：非负数 0。 失败： -1.		


	fputs：将一个字符串写出到stdout.输出字符串后， 不添加 \n 换行符。

		int fputs(const char * str, FILE * stream);	

			参1：待写出到屏幕的字符串。		屏幕 --》标准输出： stdout

			参数：写出位置 stdout

			返回值： 成功：0。 失败： -1.


	strlen: 碰到 \0 结束。

		size_t strlen(const char *s);

			参1： 待求长度的字符串

			返回：有效的字符个数。

字符串追加：

	char str1[] = "hello";
	char str2[] = "world";

	char str3[100] = {0};

	int i = 0;		// 循环 str1
	while (str1[i] != '\0')
	{
		str3[i] = str1[i];  // 循环着将str1中的每一个元素，交给str3
		i++;
	}					// str3=[h e l l o]
	//printf("%d\n", i);  --> 5

	int j = 0;		// 循环 str2
	while (str2[j]) // 等价于 while(str2[j] !='\0') 等价于 while (str2[j] != 0)
	{
		str3[i+j] = str2[j];
		j++;
	}					// str3=[h e l l o w o r l d]

	// 手动添加 \0 字符串结束标记
	str3[i + j] = '\0';
	

---------------------------------------

函数的作用：

	1. 提高代码的复用率

	2. 提高程序模块化组织性。


函数分类：

	系统库函数： 标准C库。 libc

		1. 引入头文件 --- 声明函数
		
		2. 根据函数原型调用。

	用户自定义:

		除了需要提供函数原型之外，还需要提供函数实现。

随机数：

	1. 播种随机数种子： srand(time(NULL));

	2. 引入头文件 #include <stdlib.h>  <time.h>

	3. 生成随机数： rand() % 100;

	
函数定义：

	包含 函数原型（返回值类型、函数名、形参列表） 和 函数体（大括号一对， 具体代码实现）

	形参列表： 形式参数列表。一定包 类型名 形参名。

	int add（int a, int b, int c）
	{
		return a+b+c;
	}

	int test(char ch, short b, int arr[], int m)
	
函数调用：

	包含 函数名(实参列表);  

	int ret = add(10, 4, 28);
		
	实参(实际参数)： 在调用是，传参必须严格按照形参填充。（参数的个数、类型、顺序）  没有类型描述符

	int arr[] = {1, 3, 6};
	

函数声明：

	包含 函数原型（返回值类型、函数名、形参列表） + “;”

	要求 在函数调用之前，编译必须见过函数定义。否则，需要函数声明。

	int add（int a, int b, int c）；


	隐式声明：【不要依赖】

		默认编译器做隐式声明函数时，返回都为 int ，根据调用语句不全函数名和形参列表。


	#include <xxx.h> --> 包含函数的声明


exit函数： #include <stdlib.h>

	return关键字：

		返回当前函数调用，将返回值返回给调用者。

	exit()函数：

		退出当前程序。

多文件编程：

	将多个含有不同函数功能 .c 文件模块，编译到一起，生成一个 .exe文件。


	<>包裹的头文件为系统库头文件。

	""包裹的头文件为用户自定义头文件。

	
	防止头文件重复包含：头文件守卫。

		1） #pragma once		--- windows中

		2） #ifndef __HEAD_H__		<--- head.h

		    #define __HEAD_H__

			.... 头文件内容

		    #endif
```
## Code
+ 01-二维数组.c
```c
int main0101(void)
{
	int arr[3][4] = {	{2, 7, 8, 5}, 
						{75, 8, 9, 8}, 
						{26, 37, 99, 9} };
	for (size_t i = 0; i < 3; i++)		//行
	{
		for (size_t j = 0; j < 4; j++)  //列
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("数组的大小为：%u\n", sizeof(arr));
	printf("数组行的大小：%u\n", sizeof(arr[0]));
	printf("数组一个元素的大小：%u\n", sizeof(arr[0][0]));

	printf("行数=总大小/一行大小：%d\n", sizeof(arr)/ sizeof(arr[0]));
	printf("列数=行大小/一个元素大小：%d\n", sizeof(arr[0])/ sizeof(arr[0][0]));

	printf("arr= %p\n", arr);
	printf("&arr[0] = %p\n", &arr[0][0]);
	printf("arr[0] = %p\n", arr[0]);

	system("pause");
	return EXIT_SUCCESS;
}


// 二维数组的初始化
int main0102(void)
{
	int arr[][2] = { 1, 3, 4, 6, 7 };

	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	for (size_t i = 0; i < row; i++)		//行
	{
		for (size_t j = 0; j < col; j++)  //列
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("数组的大小为：%u\n", sizeof(arr));
	printf("数组行的大小：%u\n", sizeof(arr[0]));
	printf("数组一个元素的大小：%u\n", sizeof(arr[0][0]));

	printf("行数=总大小/一行大小：%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("列数=行大小/一个元素大小：%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));

	printf("arr= %p\n", arr);
	printf("&arr[0] = %p\n", &arr[0][0]);
	printf("arr[0] = %p\n", arr[0]);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 02-二维数组练习
```c
int main0201(void)
{
/*
56 78 92
45 67 93
29 83 88
93 56 89
72 83 81
*/
	int scores[5][3] = {1, 2, 4, 5, 6, 7, 8, 9};

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);

	// 获取 5 名学生、3门功课成绩
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			scanf("%c", &scores[i][j]);
		}
	}
	// 求一个学生的总成绩
	for (size_t i = 0; i < row; i++) // 每个学生
	{
		int sum = 0;
		for (size_t j = 0; j < col; j++)// 每个学生的成绩
		{
			sum += scores[i][j];
		}
		printf("第%d个学生的总成绩为：%d\n", i+1, sum);
	}
	//求一门功课的总成绩
	for (size_t i = 0; i < col; i++)  // 第几门功课
	{
		int sum = 0;
		for (size_t j = 0; j < row; j++)  // 每门功课的第几个学生
		{
			sum += scores[j][i];
		}
		printf("第%d门功课的总成绩为：%d\n", i + 1, sum);
	}


	system("pause");
	return EXIT_SUCCESS;
}
```
+ 03-多维数组.c
```c
int main0301(void)
{
	int a[3][4][2] = 
	{ 
		{
			{1, 2},
			{2, 3},
			{4, 5},
			{5, 6}
		},
		{
			{45, 67},
			{78, 90},
			{12, 6},
			{45, 9}
		},
		{
			{ 45, 67 },
			{ 78, 90 },
			{ 12, 6 },
			{ 45, 9 }
		}
	};

	//int arr[2][3][5] = {1, 2, 4, 5, 6, 7, 8 , 9, 0, 0, 7, 9, 8};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 04-字符数组和字符串.c
```c
int main0401(void)
{
	char str[6] = { 'h', 'e', 'l', 'l', 'o', '\0'};

	char str2[] = "world";  //  == {'w', 'o', 'r', 'l', 'd', '\0'}

	printf("%s\n", str2);

	system("pause");
	return EXIT_SUCCESS;
}

// 统计字符串中每个字符出现的次数
int main0402(void)
{
	char str[11] = {0};		// helloworld -->  26个英文字母 a-z  a:97 d:100

	// scanf("%s", str);
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%c", &str[i]);
	}

	int count[26] = {0};  // 代表26个英文字母出现的次数。 

	for (size_t i = 0; i < 11; i++)
	{
		int index = str[i] - 'a';	// 用户输入的字符在 count数组中的下标值。
		count[index]++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c字符在字符串中出现 %d 次\n", i+'a', count[i]);
		}
	}
	
	system("pause");
	return EXIT_SUCCESS;
}
```
+ 05-scanf获取字符串.c
```c
int main0501(void)
{
	char str[100];

	//scanf("%s", str);
	scanf("%[^\n]s", str);

	printf("%s\n", str);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 06-字符串操作函数.c
```c
//gets
int main0601(void)
{
	char str[10];

	printf("获取的字符串为：%s", gets(str));

	system("pause");
	return EXIT_SUCCESS;
}

//fgets
int main0602(void)
{
	char str[10];

	printf("获取的字符串为：%s", fgets(str, sizeof(str), stdin));

	system("pause");
	return EXIT_SUCCESS;
}

//puts
int main0603(void)
{
	char str[] = "hello world\n";

	int ret = puts(str);	// puts("hello world");

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

//fputs
int main0604(void)
{
	char str[] = "hello world\n";

	//int ret = fputs(str, stdout);	// 

	int ret = fputs("hello world\n", stdout);

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

// strlen() 函数 ： 获取字符串的 有效长度： 不包含\0
int main0605(void)
{
	char str[] = "hello\0world";

	printf("sizeof(str) = %u\n", sizeof(str));

	printf("strlen(str) = %u\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}

// 实现strlen函数
int main0606(void)
{
	char str[] = "hello world";

	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("%d\n", i);

	// 等价于 printf("%d\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}

// 进阶版
int main0607(void)
{
	char str[] = "hello\0world";

	int i = 0;
	while (str[i++]);

	printf("%d\n", i-1);
	// 等价于 printf("%d\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 07-字符串拼接.c
```c
int main0702(void)
{
	char str1[] = "hello";  // [ h e l l o \0 ]
	char str2[] = "world";

	char str3[100];

	int i = 0;		// 循环 str1
	while (str1[i] != '\0')   // '\0' != '\0'
	{
		str3[i] = str1[i];  // 循环着将str1中的每一个元素，交给str3
		i++;
	}					// str3=[h e l l o]
	//printf("%d\n", i);  --> 5

	int j = 0;		// 循环 str2
	while (str2[j]) // 等价于 while(str2[j] !='\0') 等价于 while(str2[j] != 0)
	{
		str3[i+j] = str2[j];
		j++;
	}					// str3=[h e l l o w o r l d]

	// 手动添加 \0 字符串结束标记
	str3[i + j] = '\0';

	printf("str3 = %s\n", str3);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 08-函数.c
```c
void bubble_sort(int arr[]);  // 函数声明
void print_arr(int arr[]);

int main0801(void)
{
	printf("add = %d\n", add(2, 6));

	int arr[] = {54, 5, 16, 34 , 6, 9, 34, 1, 7, 93};

	bubble_sort(arr);

	print_arr(arr);

	system("pause");

	return EXIT_SUCCESS;   // 底层 调用 _exit(); 做退出
}

void print_arr(int arr[])
{
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

void bubble_sort(int arr[])
{
	int i, j, temp;

	for (i = 0; i < 10 - 1; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int add(int a, int b)
{
	return a + b;
}
```
+ 09-exit函数.c
```c
int func(int a, char ch);

int main(void)
{
	int ret = func(10, 'a');

	printf("ret = %d\n", ret);

	system("pause");
	//return EXIT_SUCCESS;
	exit(EXIT_SUCCESS);
}

int func(int a, char ch)
{
	printf("a = %d\n", a);

	printf("ch = %c\n", ch);

	//return 10;
	exit(10);
}
```
# Day06
## 笔记
```text
指针和内存单元

	指针： 地址。

	内存单元： 计算机中内存最小的存储单位。——内存单元。大小一个字节。 每一个内存单元都有一个唯一的编号（数）。

		   称这个内存单元的编号为 “地址”。

	指针变量：存地址的变量。

指针定义和使用：

	int a = 10;

	int *p = &a;			int* p;--- windows;	int *p ---Linux       int * p ;

	int a, *p, *q, b;

	*p = 250;			指针的 解引用。 间接引用。

	*p ： 将p变量的内容取出，当成地址看待，找到该地址对应的内存空间。

		如果做左值： 存数据到空间中。

		如果做右值： 取出空间中的内容。


	任意“指针”类型大小：

		指针的大小与类型 无关。 只与当前使用的平台架构有关。   32位：4字节。	 64位： 8字节。
	
野指针：
	1) 没有一个有效的地址空间的指针。

		int *p;

		*p = 1000;

	2）p变量有一个值，但该值不是可访问的内存区域。
		
		int *p = 10;

		*p = 2000;

	【杜绝野指针】

空指针：
	int *p = NULL;     #define NULL ((void *)0)

	*p 时 p所对应的存储空间一定是一个 无效的访问区域。


万能指针/泛型指针（void *）：

	可以接收任意一种变量地址。但是，在使用【必须】借助“强转”具体化数据类型。

		char ch = 'R';

		void *p;  // 万能指针、泛型指针
		
		p = &ch;

		printf("%c\n", *(char *)p);

const关键字：
	
    修饰变量：

	const int a = 20;

	int *p = &a;

	*p = 650;

	printf("%d\n", a);


    修饰指针：

	const int *p;

		可以修改 p

		不可以修改 *p。

	int const *p;

		同上。

	int * const p;

		可以修改 *p

		不可以修改 p。

	const int *const p;

		不可以修改 p。

		不可以修改 *p。

	总结：const 向右修饰，被修饰的部分即为只读。


	常用：在函数形参内，用来限制指针所对应的内存空间为只读。


指针和数组： 

	数组名：  
		【数组名是地址常量】 --- 不可以被赋值。	 ++ / -- / += / -= / %= / /=  (带有副作用的运算符)

		指针是变量。可以用数组名给指针赋值。 ++ -- 

	取数组元素：

		int arr[] = {1,3, 5, 7, 8};

		int *p = arr;  

		arr[i] == *(arr+0) == p[0] == *(p+0)

	指针和数组区别：

		1. 指针是变量。数组名为常量。

		2. sizeof(指针) ===》 4字节 / 8字节

		   sizeof(数组) ===》 数组的实际字节数。

	指针++ 操作数组：

		int arr[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
		int *p = arr;		

		for (size_t i = 0; i < n; i++)
		{
			printf("%d ", *p);
			p++;  // p = p+1;   一次加过一个int大小。 一个元素。
		}

		p的值会随着循环不断变化。打印结束后，p指向一块无效地址空间(野指针)。

指针加减运算：

	数据类型对指针的作用：
		
		1）间接引用：

			决定了从指针存储的地址开始，向后读取的字节数。  （与指针本身存储空间无关。）

		2）加减运算：

			决定了指针进行 +1/-1 操作向后加过的 字节数。

	指针 * / % ： error!!!

	指针 +- 整数：

		1) 普通指针变量 +- 整数

			char *p; 打印 p 、 p+1  偏过 1 字节。

			short*p; 打印 p 、 p+1  偏过 2 字节。

			int  *p; 打印 p 、 p+1  偏过 4 字节。		
	
		2）在数组中 +- 整数

			short arr[] = {1, 3, 5, 8};

			int *p = arr;

			p+3;			// 向右(后)偏过 3 个元素

			p-2;			// 向前(左)偏过 2 个元素

		3）&数组名 + 1

			加过一个 数组的大小（数组元素个数 x sizeof（数组元素类型））

	指针 +- 指针：

		指针 + 指针： error！！！

		指针 - 指针：

			1） 普通变量来说， 语法允许。无实际意义。【了解】

			2） 数组来说：偏移过的元素个数。


指针实现 strlen 函数：

	char str[] = "hello";

	char *p = str;

	while (*p != '\0')
	{
		p++;
	}

	p-str; 即为 数组有效元素的个数。


指针比较运算：

	1） 普通变量来说， 语法允许。无实际意义。

	2） 数组来说：	地址之间可以进行比较大小。

			可以得到，元素存储的先后顺序。

	3） int *p;

	    p = NULL;		// 这两行等价于： int *p = NULL;

	    if (p != NULL)

		printf(" p is not NULL");

	    else 
		printf(" p is NULL");

指针数组：

	一个存储地址的数组。数组内部所有元素都是地址。

	1) 
		int a = 10;
		int b = 20;
		int c = 30;

		int *arr[] = {&a, &b, &c}; // 数组元素为 整型变量 地址
	2) 

		int a[] = { 10 };
		int b[] = { 20 };
		int c[] = { 30 };

		int *arr[] = { a, b, c }; // 数组元素为 数组 地址。	

	指针数组本质，是一个二级指针。

	二维数组， 也是一个二级指针。


多级指针：

	int a = 0;

	int *p = &a;  				一级指针是 变量的地址。

	int **pp = &p;				二级指针是 一级指针的地址。

	int ***ppp = &pp;			三级指针是 二级指针的地址。	

	int ****pppp = &ppp;			四级指针是 三级指针的地址。	【了解】
	......


	多级指针，不能  跳跃定义！

	
	对应关系：

	ppp == &pp;			三级指针

	*ppp == pp == &p; 			二级指针

	**ppp == *pp == p == &a				一级指针

	***ppp == **pp == *p == a				普通整型变量



	*p ： 将p变量的内容取出，当成地址看待，找到该地址对应的内存空间。

		如果做左值： 存数据到空间中。

		如果做右值： 取出空间中的内容。


===================================================================================================================================



指针和函数：

	传值和传址：


	指针做函数参数：

	数组做函数参数：

	指针做函数返回值：

	数组做函数返回值：


练习：比较两个字符串：

	比较 str1 和 str2， 如果相同返回0， 不同则依次比较ASCII码，str1 > str2 返回1，否则返回-1

练习：字符串拷贝：


练习：在字符串中查找字符出现的位置：
```
## Code
+ 01-指针基础.c
```c
int main0101(void)
{
	int a = 10;

	int *p = &a;

	//*p = 2000;
	a = 350;

	//printf("a = %d\n", a);
	printf("*p = %d\n", *p);
	
	printf("sizeof(int *) = %u\n", sizeof(int *));
	printf("sizeof(short *) = %u\n", sizeof(short *));
	printf("sizeof(char *) = %u\n", sizeof(char *));
	printf("sizeof(long *) = %u\n", sizeof(long *));
	printf("sizeof(double *) = %u\n", sizeof(double *));

	printf("sizeof(void *) = %u\n", sizeof(void *));



	system("pause");
	return EXIT_SUCCESS;
}
```
+ 02-野指针和空指针.c
```c
// 野指针1
int main0201(void)
{
	/*
	int *p;

	*p = 2000;

	printf("*p = %d\n", *p);
	*/
	system("pause");
	return EXIT_SUCCESS;
}

// 野指针2
int main0202(void)
{
	int m;
	//int *p = 1000;   // 0-255 确定留给操作系统
	int *p = 0x0bfcde0000;

	p = &m;

	*p = 2000;

	printf("*p = %d\n", *p);

	system("pause");
	return EXIT_SUCCESS;
}

// 空指针
int main0203(void)
{
	int *p = NULL;   // NULL == 0

	// .....
	// lllll

	// .....

	if (p != NULL)
	{
		*p = 300;
		printf("*p = %d\n", *p);
	}

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 03-泛型指针.c
```c
int main0301(void)
{
		int a = 345;

		char ch = 'R';

		void *p;  // 万能指针、泛型指针
		//p = &a;
		p = &ch;

	printf("%c\n", *(char *)p);


	system("pause");
	return EXIT_SUCCESS;
}
```
+ 04-const.c
```c
/ 修饰变量
int main0401(void)
{
	const int a = 20;

	int *p = &a;

	*p = 650;

	printf("%d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

// const int *p;
int main0402(void)
{
	int a = 10;
	int b = 30;
	const int *p = &a;

	//*p = 500;
	p = &b;

	system("pause");
	return EXIT_SUCCESS;
}

//  int const *p;
int main0403(void)
{
	int a = 10;
	int b = 30;
	int const *p = &a;

	//*p = 300;
	p = &b;

	system("pause");
	return EXIT_SUCCESS;
}


//  int * const p;
int main0405(void)
{
	int a = 10;
	int b = 30;
	int * const p = &a;

	*p = 300;
	//p = &b;

	printf("a = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

// const int * const p;
int main0406(void)
{
	int a = 10;
	int b = 30;
	const int * const p = &a;

	//*p = 300;
	//p = &b;

	printf("a = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 05-指针和数组.c
```c
// 操作数组元素的 4 种方法
int main0501(void)
{
	int a[] = {1, 2, 4, 5, 6, 7, 8, 9, 0};

	int n = sizeof(a) / sizeof(a[0]);

	int *p = a;

	printf("sizeof(a) = %u\n", sizeof(a));
	printf("sizeof(p) = %u\n", sizeof(p));

	for (size_t i = 0; i < n; i++)
	{
		//printf("%d "), a[i];
		//printf("%d ", *(a+i));  // a[i] == *(a+i)
		//printf("%d ", p[i]);
		printf("%d ", *(p+i));  // p[i] = *(p+i)
	}
	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}

// 使用指针++操作数组元素
int main0502(void)
{
	int arr[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr;
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("first p = %p\n", p);

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;  // p = p+1;   一次加过一个int大小。 一个元素。
	}
	putchar('\n');

	printf("last p = %p\n", p);

	system("pause");
	return EXIT_SUCCESS;
}

// 综合练习
int main0503(void)
{
	int arr[10];
	int n = sizeof(arr) / sizeof(arr[0]);
	int *p = arr;

	for (size_t i = 0; i < n; i++)
	{
		*(p + i) = 10 + i;  //*(p + i) == arr[i]
	}						// p 指向数组的首地址。

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;
	}						// p指针指向一块无效的内存区域，p为 野指针。
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 06-指针的算数运算.c
```c
// 指针在数组中 +- 整数
int main0601(void)
{
	int a[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
	//int *p = a; // a == &a[0];

	int *p = &a[5];

	printf("p-2 = %p\n", p - 2);

	printf("&a[3] = %p\n", &a[3]);

	system("pause");
	return EXIT_SUCCESS;
}

// &数组名 +1
int main0602(void)
{
	short a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	printf("a = %p\n", a);
	printf("&a[0] = %p\n", &a[0]);

	printf("a+1 = %p\n", a+1);

	printf("&a   = %p\n", &a);
	printf("&a+1 = %p\n", &a + 1);

	system("pause");
	return EXIT_SUCCESS;
}

// 指针加减指针
int main0603(void)
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = a;

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", *p);
		p++;
	}
	printf("p - a = %d\n", p - a);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 07-strlen实现.c
```c
int mystrlen(char arr[]);

int main0701(void)
{
	char abc[] = "hello world";

	int ret = mystrlen2(abc);  // 实际参数 abc

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

// 借助数组 实现 
int mystrlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// 借助指针++ 实现 
int mystrlen2(char str[])
{
	char *p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p-str;  // 返回数组元素的个数。
}
```
+ 08-指针的比较运算.c
```c
int main0801(void)
{
	int a[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };

	int *p = &a[0];

	if (p > a)
		printf("成立\n");

	else if (p < a)
		printf("不成立\n");

	else
		printf("== \n");



	system("pause");
	return EXIT_SUCCESS;
}
```
+ 09-指针数组.c
```c
// 指针数组1
int main0901(void)
{
	int a = 10;
	int b = 20;
	int c = 30;

	int *p1 = &a;
	int *p2 = &b;
	int *p3 = &c;

	int *arr[] = {p1, p2, p3};  // 整型指针数组arr， 存的都是整型地址。

	printf("*(arr[0]) = %d\n", *(*(arr + 0)));  //arr[0] ==  *(arr+0)

	printf("*(arr[0]) = %d\n", **arr);

	system("pause");
	return EXIT_SUCCESS;
}
// 指针数组2
int main0902(void)
{
	int a[] = { 10 };
	int b[] = { 20 };
	int c[] = { 30 };

	int *arr[] = { a, b, c };  // 整型指针数组arr， 存的都是整型地址。

	printf("*(arr[0]) = %d\n", *(*(arr + 0)));  //arr[0] ==  *(arr+0)

	printf("*(arr[0]) = %d\n", **arr);

	system("pause");
	return EXIT_SUCCESS;
}
```
+ 10-多级指针.c
```c
int main1001(void)
{
	int a = 10;
	int *p = &a;
	int **pp = &p;
	// int **pp = &(&a); 不允许！！
	int ***ppp = &pp;

	printf("***ppp = %d\n", ***ppp);
	printf("**pp = %d\n", **pp);
	printf("*p = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}
```

