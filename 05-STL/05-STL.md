# Day01
## 笔记
```test
1	STL概论
	1.1	STL六大组件
		1.1.1	容器、算法、迭代器、仿函数、适配器、空间配置器
	1.2	STL优点
		1.2.1	内建在C++编译器中，不需要安装额外内容
		1.2.2	不需要了解具体实现内容，只要熟练运用即可
		1.2.3	高复用，可移植，高性能
	1.3	容器划分
		1.3.1	序列式容器 
		1.3.2	关联式容器   有个key起到索引作用
	1.4	算法
		1.4.1	质变算法
		1.4.2	非质变算法
2	STL初识
	2.1	vector容器  vector<int>v
	2.2	vector<int>::iterator  itBegin = v.begin(); //v.begin() 起始迭代器，指向容器中第一个数据
	2.3		vector<int>::iterator  itEnd = v.end(); //v.end()；结束迭代器，指向的是容器中最后一个元素的下一个位置
	2.4	利用算法遍历容器
		2.4.1	for_each(v.begin(),v.end() , myPrint )  头文件    algorithm
	2.5	容器中存放自定义数据类型
	2.6	容器中存放自定义数据类型指针
	2.7	容器嵌套容器
3	string
	3.1	构造、赋值
	3.2	[]、at 字符存取
		3.2.1	[] 和 at区别？ []访问越界 直接挂掉，at抛出out_of_range异常
	3.3	字符串拼接   +=            append
	3.4	查找    find   rfind(从右往左查找)
	3.5	替换    replace
	3.6	比较    compare
	3.7	子串    substr
	3.8	案例 
		3.8.1	求email中的用户名
		3.8.2	string str = "www.itcast.com.cn";
		3.8.3	将 www  itcast  com  cn 单词截取到 vector容器中
	3.9	插入 insert
	3.10	删除 erase
	3.11	string和const  char* 转换
		3.11.1	string 转 const char *     .c_str();
		3.11.2	const char * 转string    利用string 有参构造
		3.11.3	const char *可以隐式转换为 string 反之不可以
	3.12	小写转大写  toupper
	3.13	大写转小写  tolower
4	vector容器
	4.1	单端数组 
	4.2	动态数组，自动扩展内存，所谓动态扩展内存，并不是在原有空间后续进行扩展，而是找一个更大的内存空间，将原有数据拷贝到新空间下，并且释放原有空间
	4.3	接口
		4.3.1	构造、赋值
		4.3.2	交换 swap
		4.3.3	大小 size 
		4.3.4	是否为空  empty
		4.3.5	重置大小 resize
			4.3.5.1	如果重置的比原来大，有默认值填充新位置
			4.3.5.2	如果重置的比原来小，超出的部分删除掉
		4.3.6	front 返回容器中第一个元素
		4.3.7	back 返回容器中最后一个元素
	4.4	插入  insert  （迭代器）
	4.5	删除  erase   （迭代器）
	4.6	尾插  push_back
	4.7	尾删  pop_back
	4.8	清空  clear
	4.9	案例1 ：巧用swap收缩内存
	4.10	案例2: ： 巧用reserve 预留内存
	4.11	逆序遍历  reverse_iterator   非质变
	4.12	判断容器的迭代器是否支持随机访问
5	deque容器
	5.1	双端数组
	5.2	可以对头部进行插入和删除操作，内部有中控器控制数据
	5.3	接口
		5.3.1	构造、赋值
		5.3.2	交换  swap
		5.3.3	大小 size
		5.3.4	是否为空 empty
		5.3.5	重置大小  resize
		5.3.6	front 返回容器中第一个元素
		5.3.7	back 返回容器中最后一个元素
		5.3.8	插入  insert  （迭代器）
		5.3.9	删除  erase   （迭代器）
		5.3.10	头部插入  push_front
		5.3.11	头部删除  pop_front
		5.3.12	尾插  push_back
		5.3.13	尾删  pop_back
		5.3.14	清空  clear
	5.4	sort排序 sort(v.begin(),v.end(), 回调函数)
6
```
## Code
### 01STL初识.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>


void myPrint(int val)
{
	cout << val << endl;
}

void test02()
{
	vector<int>v;  // 创建一个vector容器，容器中存放的数据类型是int类型

	// 插入元素
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);

	// 遍历元素
	vector<int>::iterator itBegin = v.begin();  // 起始迭代器，指向容器中的第一个数据
	vector<int>::iterator itEnd = v.end();  // 结束迭代器，指向容器中最后一个元素的下一个位置

	
	// 第一种遍历
	while (itBegin != itEnd)  // 不要对itEnd解引用 itEnd指向空值
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	// 第二种遍历
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	// 第三种遍历
	for_each(itBegin, itEnd, myPrint);
}


// 自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test03()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	
	// 插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 遍历数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// *it --- Person
		cout << "姓名" << (*it).m_Name << "年龄" << it->m_Age << endl;
	}
	
}


//存放自定义数据类型指针
void test04()
{
	vector<Person*> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		// *it  ---- Person *
		cout << "姓名： " << (*it)->m_Name << " 年龄： " << (*it)->m_Age << endl;
	}
}

// 容器嵌套容器
void test05()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	// 小容器赋值
	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	// 大容器赋值
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	// 遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main()
{
	// test02();
	//test03();
	test04();
	//test05();
	system("pause");
	return EXIT_SUCCESS;
}
```
### 02string容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <vector>
/*
3.1.2.1 string 构造函数
string();	//创建一个空的字符串 例如: string str;
string(const string& str);	//使用一个string对象初始化另一个string对象
string(const char* s);	//使用字符串s初始化
string(int n, char c);	//使用n个字符c初始化

3.1.2.2 string基本赋值操作
string& operator=(const char* s);	//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);	   //把字符串s赋给当前的字符串
string& operator=(char c);	//字符赋值给当前的字符串

string& assign(const char *s);	//把字符串s赋给当前的字符串
string& assign(const char *s, int n);	//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);	//把字符串s赋给当前字符串
string& assign(int n, char c);	//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);	//将s从start开始n个字符赋值给字符串
*/

void test01()
{
	string str;
	string str2(str);

	string str3 = "abc";

	string str4(10, 'a');

	cout << "str3 = " << str3 << endl;

	cout << "str4 = " << str4 << endl;

}
//赋值
void test02()
{
	string  str;
	str = "abc";

	str.assign("abcde", 3);

	cout << str << endl;


	string str2;
	str2.assign(str);
	cout << str2 << endl;

	//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

	str2.assign(str, 0, 2);
	cout << str2 << endl;

}

/*
3.1.2.3 string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/

void test03()
{
	string str = "hello world";

	//for (int i = 0; i < str.size();i++)
	//{
	//	//cout << str[i] << endl;
	//	cout << str.at(i) << endl;
	//}

	//[]和at区别，[]访问越界 直接挂掉 ， at访问越界  抛出out_of_range异常

	try
	{
		//cout << str[100] << endl;
		cout << str.at(100) << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "异常捕获" << endl;
	}

}


/*
3.1.2.4 string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符

string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置

int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/

void test04()
{
	//拼接
	//string str1 = "我";
	//string str2 = "爱北京";

	//str1 += str2;
	//cout << str1 << endl;

	//str1.append("天安门");
	//cout << str1 << endl;

	//查找
	string str = "abcdefgde";

	int pos = str.find("de");
	//rfind 是从右往左查找
	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到了字符串，位置为： " << pos << endl;
	}

	//替换
	//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	str.replace(1, 3, "11111");
	//a11111efgde
	cout << str << endl;
}


/*
3.1.2.6 string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较

3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/

void test05()
{
	string str1 = "abcde";
	string str2 = "abcdef";

	if (str1.compare(str2) == 0)
	{
		cout << "str1 == str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}

void test06()
{
	//子串
	//string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

	//string str = "abcdef";

	//string subStr =	str.substr(0, 3);

	//cout << subStr << endl;


	string email = "zhangtao@sina.com";

	int pos = email.find("@"); // 8
	cout << pos << endl;
	string userName = email.substr(0, pos);

	cout << userName << endl;

}

//解析字符串
void test07()
{
	string str = "www.itcast.com.cn";

	vector<string> v; //将 www  itcast  com  cn 单词截取到 vector容器中

	int start = 0;
	int pos = -1;

	while (true)
	{
		//www.itcast.com.cn
		pos = str.find(".", start);

		if (pos == -1)
		{
			//将cn截取出来
			string tempStr = str.substr(start, str.size() - start);
			v.push_back(tempStr);
			break;
		}

		string tempStr = str.substr(start, pos - start);

		v.push_back(tempStr);

		start = pos + 1;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

/*
3.1.2.8 string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/
void test08()
{

	string str = "hello";

	str.insert(1, "111");

	//h111ello 
	cout << str << endl;

	//删除 
	str.erase(1, 3);

	cout << str << endl;
}

void doWork(string str)
{

}

void doWork2(const char* str)
{

}

//3.1.2.9 string和c-style字符串转换
void test09()
{
	const char* str = "abcd";

	//const char * 转为 string
	string s(str);

	//string 转为 const char *
	const char* str2 = s.c_str();

	//const char * 可以隐式类型转换为  string
	doWork(str2);
	//string 不可以隐式类型转换为  const char* 
	//doWork2(s);
}


void test10()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "pppppppppppppppppppppppp";

	//a = '1';
	//b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

}

/*
写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
*/
void test11()
{
	string str = "abcdEFg";

	for (int i = 0; i < str.size(); i++)
	{
		//str[i] = toupper(str[i]);

		str[i] = tolower(str[i]);

	}

	cout << str << endl;
}


int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test10();
	//test11();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 03vector容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <list>

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()容器的容量
	}
}

/*
3.2.4.1 vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
*/


void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test02()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int>v2(v1.begin(), v1.end());

	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());

	printVector(v3);


	vector<int>v4(10, 100);
	printVector(v4);

	cout << "v3和v4互换后：" << endl;
	v3.swap(v4);

	printVector(v3);
	printVector(v4);
}

/*
3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空

resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。

capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
reverse  翻转
3.2.4.4 vector数据存取操作

at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
*/

void test03()
{

	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空 ，大小为： " << v1.size() << endl;
	}

	v1.resize(10, 100); //第二个参数代表默认填充值

	printVector(v1);

	v1.resize(3);

	printVector(v1);

	cout << "v1的front = " << v1.front() << endl;
	cout << "v1的back  = " << v1.back() << endl;

}


/*
3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/

void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	v.insert(v.begin(), 100);

	printVector(v);

	v.push_back(1000);

	printVector(v);

	v.pop_back();

	printVector(v);


	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end()); 等价于  v.clear();
	v.clear();
	//v.erase(v.begin(), v.end());
	printVector(v);

}


//案例1  巧用swap收缩内存
void test05()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	v.resize(3);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	//巧用swap收缩内存
	vector<int>(v).swap(v);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;
}

//案例2  巧用 reserve 预留空间
void test06()
{
	// -- 防止他多次重复分配内存
	vector<int>v;
	v.reserve(100000);
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;

}

// 附加版
void test07()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//逆序遍历
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}

	//vector的迭代器是随机访问迭代器，支持跳跃访问

	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 3;


	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	list<int>::iterator itBegin2 = L.begin();
	//itBegin2 = itBegin2 + 1;//list容器的迭代器是不支持随机访问的

	cout << *itBegin << endl;


}


int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 04deque容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>
#include <algorithm>
/*
3.3.3.1 deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。

3.3.3.2 deque赋值操作
assign(beg, end);	//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);	//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq);    //重载等号操作符
swap(deq);	// 将deq与本身的元素互换

3.3.3.3 deque大小操作
deque.size();	//返回容器中元素的个数
deque.empty();	//判断容器是否为空
deque.resize(num);	//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem);	//重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/

void printDeque(const deque<int>& d)
{
	//iterator普通迭代器
	//reverse_iterator 反转迭代器
	//const_iterator  只读迭代器

	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 1000;
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);


	deque<int>d2;
	d2 = d;

	printDeque(d2);


	if (d2.empty())
	{
		cout << "d2为空" << endl;
	}
	else
	{
		cout << "d2不为空 size = " << d2.size() << endl;
	}
}


/*
3.3.3.4 deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

3.3.3.5 deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据
*/

void test02()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	//  300 200 100 10 20 30
	printDeque(d);

	d.pop_back(); //尾删
	d.pop_front(); //头删
	// 200 100 10 20
	printDeque(d);

	cout << "第一个元素为： " << d.front() << endl;  // 查看元素
	cout << "最后一个元素为：" << d.back() << endl;
}

/*
3.3.3.6 deque插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。(这里的pos是迭代器位置)
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

3.3.3.7 deque删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。  (这里的区间也是迭代器)
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
*/

void test03()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);

	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//插入 insert
	d.insert(++d.begin(), 2, 1000);
	//  300 1000 1000  200 100 10 20 30
	printDeque(d);

	//删除erase
	//d.erase(++d.begin());
	//d.erase(++d.begin());
	deque<int>::iterator it1 = d.begin();
	it1 = it1 + 1;

	deque<int>::iterator it2 = d.begin();
	it2 = it2 + 3;

	d.erase(it1, it2);
	printDeque(d);

	//清空
	d.clear();
	printDeque(d);
}


bool myCompare(int v1, int v2)
{
	return v1 < v2;
}

void test04()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//默认排序从小到大
	//sort(d.begin(), d.end());

	sort(d.begin(), d.end(), myCompare);

	printDeque(d);

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 05作业.cpp
```cpp
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//#include<deque>
//#include<algorithm>
/*
* 
3.3.3.8 案例（作业）
/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
*/


/*
class Student
{
public:
	Student(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void printPerson(deque<int> &d, int num)
{
	int score = 0;
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 1000;
		score += *it;
	}
	cout << "平均分" << score / num << endl;

}

void test01()
{
	vector<Student> v;
	deque<int> d;

	Student s1("aa", 0);
	Student s2("bb", 0);
	Student s3("cc", 0);
	Student s4("dd", 0);
	Student s5("ee", 0);
	// 放进vector
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	//  遍历vector
	int i = 56;
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		(*it).m_Score = i;
		d.push_back((*it).m_Score);
		i--;
	}
	sort(d.begin(), d.end());
	d.pop_front();
	d.pop_back();
	printPerson(d, d.size());
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
*/


// 修改版
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/


class Player
{
public:
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;  //姓名
	int m_Score; //平均分
};

// 创建选手
void createPlayer(vector<Player>& v)
{
	string nameSeed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	{
		string name = "选手";
		int score = 0;
		name += nameSeed[i];
		Player player(name, score);
		v.push_back(player);
	}
}

// 打分
void setScore(vector<Player>& v)
{
	
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (size_t i = 0; i < 10; i++)
		{
			it->m_Score = rand() % 41 + 60;
			d.push_back(it->m_Score);
		}
		// 去除最高分 最低分
		d.pop_back();
		d.pop_front();

		// 求平均分
		int num = 0;
		for (deque<int>::iterator dt = d.begin(); dt != d.end(); dt++)
		{
			num += *dt;
		}
		int avg = num / d.size();

		// 赋值
		it->m_Score = avg;
	}
}

// 显示平均分
void showScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名" << it->m_Name << "得分" << it->m_Score << endl;
	}
 }

void test01()
{
	//设置随机数种子
	srand((unsigned int)time(NULL));

	//1、创建5名选手
	vector<Player> v;
	createPlayer(v);

	//2、打分
	setScore(v);

	//3、显示平均分
	showScore(v);

	/*for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 分数： " << it->m_Score << endl;
	}*/

}
int main() 
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
```
# Day02
## 笔记
```text
1	栈容器 Stack
	1.1	符合先进后出的数据结构
	1.2	对外接口
		1.2.1	入栈 push
		1.2.2	出栈 pop 
		1.2.3	栈顶 top
		1.2.4	是否为空 empty
		1.2.5	栈大小   size
2	队列容器 Queue
	2.1	符合先进先出的数据结构
	2.2	对外接口
		2.2.1	入队 push
		2.2.2	出队 pop
		2.2.3	队头元素  front
		2.2.4	队尾元素  back
		2.2.5	是否为空  empty
		2.2.6	队列大小  size
3	list容器
	3.1	双向循环链表
	3.2	对外接口
		3.2.1	构造、赋值、大小、重置大小、是否为空
		3.2.2	反转 reverse
		3.2.3	排序 sort
			3.2.3.1	如果容器的迭代器支持随机访问，可以使用系统提供的标志算法
			3.2.3.2	不支持随机访问的迭代器的容器，内部会提供对应的算法接口
			3.2.3.3	对于自定义数据类型，必须要指定排序规则
		3.2.4	对自定义数据类型做了高级排序
		3.2.5	如果利用remove删除自定义数据类型，需要重载 == 
4	set 容器
	4.1	关联式容器  key就是value
	4.2	默认排好序  从小到大
	4.3	插入  insert    大小  size  是否为空  empty
	4.4	查找  find  返回值  迭代器
	4.5	统计 count   对于set的结果 要么是0  要么是1
	4.6	lower_bound(keyElem);    //返回第一个key>=keyElem元素的迭代器。
	4.7	upper_bound(keyElem);    //返回第一个key>keyElem元素的迭代器。
	4.8	equal_range(keyElem);      //返回容器中key与keyElem相等的上下限的两个迭代器。
	4.9	pair对组
		4.9.1	创建方式
		4.9.2	pair<string, int> p("Tom", 10);
		4.9.3	pair<string, int> p2 = make_pair("Jerry", 18);
	4.10	set.insert的返回值是个对组  pair<iterator, bool> bool代表插入是否成功
	4.11	multiset可以插入重复的key值
	4.12	可以指定set容器的排序规则，但是必须在插入前指定，利用仿函数的技术
	4.13	对于自定义数据类型，set通常都会指定出排序规则
5	map容器
	5.1	关联式容器
	5.2	默认按照key从小到大排序
	5.3	插入 
		5.3.1	m.insert(pair<int, int>(1, 10));
		5.3.2	m.insert(make_pair(2, 20));
		5.3.3	m.insert(map<int, int>::value_type(3, 30));
		5.3.4	m[4] = 40;
	5.4	查找 find  返回值 是迭代器
	5.5	统计 count  
	5.6	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	5.7	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	5.8	equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	5.9	利用仿函数  实现指定排序规则
6	STL容器使用时机
7	作业布置 
```
## Code
### 01 评委打分案例.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Player
{
public:
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;  //姓名
	int m_Score; //平均分
};


void createPlayer(vector<Player>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Player player(name, score);

		v.push_back(player);
	}
}


void setScore(vector<Player>&v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		deque<int>d; //存放评委打分的容器
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~  100
			d.push_back(score);
		}

		//cout << it->m_Name << "打分情况：" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//排序
		sort(d.begin(), d.end());

		//去除最高最低分
		d.pop_back();  // 最高分
		d.pop_front(); // 最低分

		//总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//平均分
		int avg = sum / d.size();

		it->m_Score = avg;
	}
}

void showScore(vector<Player>&v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 平均分数： " << it->m_Score << endl;
	}
}

int main(){

	//设置随机数种子
	srand((unsigned int)time(NULL));

	//1、创建5名选手
	vector<Player> v;
	createPlayer(v);

	//2、打分
	setScore(v);

	//3、显示平均分
	showScore(v);

	/*for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 分数： " << it->m_Score << endl;
	}*/


	system("pause");
	return EXIT_SUCCESS;
}
```
### 02 Stack栈容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stack>

/*
3.4.3.1 stack构造函数
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
stack(const stack &stk);//拷贝构造函数
3.4.3.2 stack赋值操作
stack& operator=(const stack &stk);//重载等号操作符
3.4.3.3 stack数据存取操作
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
3.4.3.4 stack大小操作
empty();//判断堆栈是否为空
size();//返回堆栈的大小
*/

void test01()
{
	stack<int>S;
	//入栈
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);

	cout << "size  = " << S.size() << endl;

	while (!S.empty())
	{
		//访问栈顶元素
		cout << S.top() << endl;
		//出栈
		S.pop();
	}
	cout << "size  = " << S.size() << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 03 Queue容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	queue<Person> Q; //队列容器

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);


	//入队
	Q.push(p1);
	Q.push(p2);
	Q.push(p3);
	Q.push(p4);

	cout << "size = " << Q.size() << endl;

	while ( !Q.empty())
	{
		cout << "队头元素--- 姓名：  " << Q.front().m_Name << " 年龄： " << Q.front().m_Age << endl;
		cout << "队尾元素--- 姓名：  " << Q.back().m_Name << " 年龄： " << Q.back().m_Age << endl;

		//出队
		Q.pop();
	}

	cout << "size = " << Q.size() << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 04 list容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>
/*
void test01()
{

	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++){
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead){
			node = node->_Next;
			//node = node->_Prev
		}
	}


}
*/

/*
3.6.4.1 list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

//遍历链表
void printList(const list<int> & L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//正序遍历
	//for (list<int>::iterator it = L1.begin(); it != L1.end();it++)
	//{
	//	cout << *it << endl;
	//}
	//逆序遍历
	for (list<int>::reverse_iterator it = L1.rbegin(); it != L1.rend();it++)
	{
		cout << *it << endl;
	}

	//list迭代器是不是支持随机访问 ,答案：不支持，是一个双向迭代器
	list<int>::iterator itBegin = L1.begin();
	//itBegin = itBegin + 1;
}

void test03()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	L.pop_back(); //尾删
	L.pop_front(); //头删
	// 200 100 10 20
	printList(L);


	//插入
	L.insert(L.begin(), 10000);
	// 10000 200 100 10 20
	printList(L);

	L.erase(L.begin());
	// 200 100 10 20 
	printList(L);

	//remove 删除容器中所有与elem值匹配的元素。
	L.push_back(100);
	L.push_back(100);
	L.remove(100);
	printList(L);

}

/*
3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
*/
void test04()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	list<int>L2;
	L2.assign(10, 100);

	L.swap(L2);

	printList(L);

}


/*
3.6.4.6 list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/
bool myCompare(int v1 ,int v2)
{
	return v1 > v2;
}

void test05()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	//反转
	L.reverse();

	printList(L);

	//排序  
	//如果容器的迭代器支持随机访问，可以使用系统提供的标志算法
	//不支持随机访问的迭代器的容器，内部会提供对应的算法接口
	//sort(L.begin(), L.end());
	/*L.sort(myCompare);
	printList(L);*/
}


class Person
{
public:
	Person(string name, int age , int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	bool operator==( const Person & p )
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

bool myComparePerson( Person &p1, Person &p2)
{
	if (p1.m_Age == p2.m_Age )
	{
		return p1.m_Height < p2.m_Height;
	}

	return  p1.m_Age > p2.m_Age;
}

void test06()
{
	list<Person> L;

	Person p1("亚瑟", 40 ,  180);
	Person p2("赵云", 20 , 160);
	Person p3("妲己", 30 , 120);
	Person p4("孙悟空", 50 , 200);
	Person p5("关羽", 10 ,  170 );
	Person p6("刘备", 10  , 165);
	Person p7("张飞", 10 , 185);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//按照年龄进行降序   从大到下 , 如果年龄相等，按照身高进行升序 
	//对于自定义数据类型，必须要指定排序规则
	L.sort(myComparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： "<< it->m_Height <<endl;
	}

	//删除孙悟空
	L.remove(p4);

	cout << "删除孙悟空后：" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
	}

}

int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}
```
### 05 set容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>
#include <string>

/*
3.7.2.1 set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。
*/

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s;

	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);

	printSet(s);


	if (s.empty())
	{
		cout << "set容器为空" << endl;
	}
	else
	{
		cout << "set容器不为空  大小为： " << s.size() << endl;
	}

	s.erase(30);

	printSet(s);
}


/*
3.7.2.5 set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test02()
{
	set<int>s;

	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);

	set<int>::iterator pos = s.find(30);
	if (pos != s.end())
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//对于set而言，count的结果  要么是0  要么是1
	int num = s.count(40);

	cout << "key为40的个数为：" << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	set<int>::iterator pos2 = s.lower_bound(30);

	if (pos2 != s.end())
	{
		cout << "lower_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	pos2 = s.upper_bound(30);
	if (pos2 != s.end())
	{
		cout << "upper_bound的值为：" << *pos2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

	pair< set<int>::iterator, set<int>::iterator>  ret = s.equal_range(30);

	if (ret.first != s.end())
	{
		cout << "equal_range中的lower_bound的值为：" << *ret.first << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	if (ret.second != s.end())
	{
		cout << "equal_range中的upper_bound的值为：" << *ret.second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}

//pair创建
void test03()
{
	pair<string, int> p("Tom", 10);

	cout << "姓名： " << p.first <<  " 年龄： "<< p.second << endl;


	pair<string, int> p2 = make_pair("Jerry", 18);
	cout << "姓名： " << p2.first << " 年龄： " << p.second << endl;
}


void test04()
{
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	
	
	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}


	printSet(s);

	//允许插入重复的key值
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	cout << "---------" << endl;
	for (multiset<int>::iterator it = ms.begin(); it != ms.end();it++)
	{
		cout << (*it) << endl;
	}

}


class myCompareInt
{
public:
	bool operator()(int v1 , int v2)
	{
		return v1 > v2;
	}
};

void test05()
{
	//set容器的排序规则要在插入之前指定
	set<int, myCompareInt >s;

	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);

	//printSet(s);

	for (set<int, myCompareInt>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << endl;
	}
}

//对于自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
	string m_Name;
	int m_Age;
};

class myComparePerson
{
public:
	bool operator()( const Person & p1 , const Person & p2)
	{
		//按照年龄 升序  从小到大
		return p1.m_Age < p2.m_Age;
	}
};

void test06()
{
	//利用仿函数  指定出自定义数据类型的排序规则
	set<Person,myComparePerson> s;

	Person p1("aaa", 10);
	Person p2("bbb", 40);
	Person p3("ccc", 20);
	Person p4("ddd", 30);
	Person p5("eee", 50);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person, myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << (*it).m_Age << endl;
	}

}


int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	
	system("pause");
	return EXIT_SUCCESS;
}
```
### 06 map容器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>
/*
3.8.2.1 map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数
3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空
3.8.2.4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
*/

void test01()
{
	map<int, int> m;

	//第一种插入方式
	m.insert(pair<int, int>(1,10));

	//第二种插入方式  推荐
	m.insert(make_pair(2, 20));

	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));

	//第四种
	m[4] = 40;

	//cout << m[10] << endl; //如果利用第四种 使用未指定的key，生成一个key为为指定的值，value为0的数据插入到容器中

	for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

}

/*
3.8.2.5 map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。
*/
void test02()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	m.erase(3); //删除传入key值

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

}

/*
3.8.2.6 map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test03()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	map<int,int>::iterator ret = m.find(3);
	if (ret != m.end())
	{
		cout << "找到了 key为 " << ret->first << " value = " << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计  count 
	int num =  m.count(4);
	cout << "key为4的对组个数为： " << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	map<int,int>::iterator pos = m.lower_bound(3);

	if (pos != m.end())
	{
		cout << "找到了lower_bound key: " << pos->first << " value: " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	pos = m.upper_bound(3);
	if (pos != m.end())
	{
		cout << "找到了upper_bound key: " << pos->first << " value: " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair<map<int, int>::iterator, map<int, int>::iterator>  ret2 = m.equal_range(3);

	if ( ret2.first != m.end() )
	{
		cout << "找到了equal_range中的 lower_bound的 key =  " << ret2.first->first << " value = " << ret2.first->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (ret2.second != m.end())
	{
		cout << "找到了equal_range中的 upper_bound的 key =  " << ret2.second->first << " value = " << ret2.second->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}


class myCompareInt
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void test04()
{
	map<int, int, myCompareInt> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	for (map<int, int, myCompareInt>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

}


int main(){
	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}
```
# Day03
## 笔记
```text
1	函数对象
	1.1	本质是一个类的对象，因此称为函数对象，也叫仿函数
	1.2	函数对象 超出了普通函数的概念，可以拥有自己状态
	1.3	函数对象可以作为函数参数
2	谓词
	2.1	普通函数或者仿函数的返回值是bool类型，称为谓词
	2.2	一元谓词
		2.2.1	查找容器中大于20的数字    find_if
	2.3	二元谓词
		2.3.1	对容器进行排序  sort
	2.4	lambda表达式 	[](){}
3	内建函数对象
	3.1	引入头文件  #include< functional>
	3.2	取反  negate<int>
	3.3	加法  plus<int>
	3.4	大于  greater<int>
4	适配器
	4.1	函数对象适配器
		4.1.1	1、利用bind2nd 进行绑定
		4.1.2	2、继承 public binary_function<参数1 类型,参数2类型,返回值类型>
		4.1.3	3、加const
	4.2	取反适配器
		4.2.1	一元取反  not1
			4.2.1.1	  1、利用not1进行取反
			4.2.1.2	  2、继承 public unary_function<int,bool>
			4.2.1.3	  3、加const
		4.2.2	二元取反  not2
	4.3	函数指针适配器
		4.3.1	ptr_fun将普通函数指针 适配成函数对象
	4.4	成员函数适配器
		4.4.1	如果存放的是对象实体   mem_fun_ref
		4.4.2	如果存放的是对象指针   mem_fun
5	常用遍历算法
	5.1	for_each
		5.1.1	用于遍历
		5.1.2	有返回值
		5.1.3	可以绑定参数进行输出
	5.2	transform
		5.2.1	搬运
		5.2.2	注意：目标容器要有容量
6	常用查找算法
	6.1	find  查找
	6.2	find_if  按条件查找
	6.3	adjacent_find算法 查找相邻重复元素
	6.4	binary_search算法 二分查找法
		6.4.1	注意: 在无序序列中不可用
	6.5	count算法 统计元素出现次数
	6.6	count_if 按条件进行统计
7	常用排序算法
	7.1	merge 合并  
		7.1.1	将两个容器合并到 目标容器中 
		7.1.2	注意： 两个容器必须是有序序列
		7.1.3	目标容器必须有容量
	7.2	sort 排序
	7.3	random_shuffle 洗牌
	7.4	reverse 反转
8	常用的拷贝和替换算法
	8.1	copy 拷贝
		8.1.1	实现打印  copy(v.begin(),v.end() , ostream_iterator<int>(cout , “ ”));
	8.2	replace 替换
	8.3	replace_if 按条件替换
	8.4	swap 交换
9	常用的算数生成算法
	9.1	头文件  #include <numeric>
	9.2	accumulate算法 计算容器元素累计总和
	9.3	fill算法 向容器中添加元素
10	常用集合算法
	10.1	set_intersection算法 求两个set集合的交集
	10.2	set_union算法 求两个set集合的并集
	10.3	set_difference算法 求两个set集合的差集
	10.4	注意:两个集合必须是有序序列
11
```
## Code
### 02函数对象.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(int num)
	{
		cout << num << endl;
		m_Count++;
	}

	int m_Count = 0;
};

void myPrint02(int num)
{
	cout << num << endl;
}

void test01()
{
	MyPrint myPrint;
	myPrint(100); //本质是一个类的对象，因此称为函数对象，也叫仿函数

	myPrint02(100);
}


void test02()
{
	//函数对象 超出了普通函数的概念，可以拥有自己状态

	MyPrint myPrint;
	myPrint(100);
	myPrint(100);
	myPrint(100);
	myPrint(100);

	cout << "调用次数为： " << myPrint.m_Count << endl;
}


//函数对象可以作为函数参数
void doPrint(MyPrint myPrint, int num)
{
	myPrint(num);
}

void test03()
{
	doPrint(MyPrint(), 1000);
}

int main() {

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 03谓词.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

//一元谓词 --- 里面的参数只有一个，返回值为bool值
class GreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator ret = find_if(v.begin(), v.end(), GreaterThan20());
	if (ret != v.end())
	{
		cout << "找到大于20的数字为： " << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}



//二元谓词 --- 里面的参数有两个，返回值为bool值

void myPrintInt(int val)
{
	cout << val << " ";
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};


void test02()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end()); //从小到大

	for_each(v.begin(), v.end(), myPrintInt);
	cout << endl;


	sort(v.begin(), v.end(), MyCompare());

	//lambda表达式  匿名函数  []代表lambda表达式标志  [](){}
	for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });

	cout << endl;
}


int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 04内建函数对象.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <functional>  //内建函数对象  头文件
#include <vector>
#include <algorithm>
/*
template<class T> T negate<T>//取反仿函数  一元运算
*/

void test01()
{
	negate<int>n;

	cout << n(10) << endl;
}

//template<class T> T plus<T>//加法仿函数
void test02()
{
	plus<int> p;

	cout << p(10, 10) << endl;

}



//template<class T> bool greater<T>//大于
void test03()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);

	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());

	//                           lamba表达式
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

int main() {

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 05适配器.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class MyPrint :public binary_function<int, int, void>  // 传入值的类型 和 返回值的类型
{
public:
	void operator()(int val, int start)const  // 加const
	{
		cout << "val = " << val << " start = " << start << " sum = " << val + start << endl;
	}
};

//1、函数对象适配器
void test01()
{ 
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值： " << endl;
	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

// 因为仿函数只能传入一个值，要想传入多个值就应该采用适配器

//1、利用bind2nd 进行绑定
//2、继承 public binary_function<参数1类型,参数2类型,返回值类型>
//3、加const




//2、取反适配器
class GreaterThanFive :public unary_function<int, bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//一元取反
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThanFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));

	if (pos != v.end())
	{
		cout << "找到小于5的值为： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//二元取反 --- 会改变原先的顺序
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}

//1、利用not1进行取反
//2、继承 public unary_function<int,bool>
//3、加const




void myPrint3(int val, int start)
{
	cout << val + start << endl;
}
//3、 函数适配器  -- 如果里面是一个值，直接使用回调函数就行，不用使用适配器(对于仿函数同理可得)
void test03()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//将函数指针 适配成函数对象  ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 1000));
}




//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "成员函数----姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	void addAge()
	{
		this->m_Age += 100;
	}

	string m_Name;
	int m_Age;
};

//void myPrint4( Person & p)
//{
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}

void test04()
{
	vector< Person > v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//利用 mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}



// test05： 利用成员函数指针做适配器
// 利用mem_fun
int main() {

	//	test01();
	//	test02();
	//	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}
```
### 06常用遍历算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		m_Count++;
	}

	int m_Count = 0;
};

//for_each  用于遍历
//有返回值的
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	MyPrint print = for_each(v.begin(), v.end(), MyPrint());

	cout << "print.count = " << print.m_Count << endl;

}

//for_each可以绑定参数输出
class MyPrint2 :public binary_function<int, int, void>
{
public:
	void operator()(int val, int start) const
	{
		cout << val << endl;

	}

};

void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), bind2nd(MyPrint2(), 1000));

}


//transform算法 将指定容器区间元素搬运到另一容器中
class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 10000;
	}
};
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}



	vector<int>v2;
	// 进行搬运需要先指定目标容器的大小
	v2.resize(v.size());  

	transform(v.begin(), v.end(), v2.begin(), MyTransform());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });

}

int main() {
	//test01();
	//test02();
	test03();


	system("pause");
	return EXIT_SUCCESS;
}
```
### 06常用遍历算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		m_Count++;
	}

	int m_Count = 0;
};

//for_each  用于遍历
//有返回值的
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	MyPrint print = for_each(v.begin(), v.end(), MyPrint());

	cout << "print.count = " << print.m_Count << endl;

}

//for_each可以绑定参数输出
class MyPrint2 :public binary_function<int, int, void>
{
public:
	void operator()(int val, int start) const
	{
		cout << val << endl;

	}

};

void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), bind2nd(MyPrint2(), 1000));

}


//transform算法 将指定容器区间元素搬运到另一容器中
class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 10000;
	}
};
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}



	vector<int>v2;
	// 进行搬运需要先指定目标容器的大小
	v2.resize(v.size());  

	transform(v.begin(), v.end(), v2.begin(), MyTransform());

	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });

}

int main() {
	//test01();
	//test02();
	test03();


	system("pause");
	return EXIT_SUCCESS;
}
```
### 07常用查找算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置


find_if算法 条件查找
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return bool 查找返回true 否则false

*/



void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	// find 按元素查找，返回的是迭代器
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);

	if (pos != v.end())
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person& p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 对于自定义数据类型 需要重载operator==
	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos != v.end())
	{
		cout << "找到了元素  姓名： " << (*pos).m_Name << " 年龄： " << (*pos).m_Age << endl;
	}

}

class MyComparePerson :public binary_function< Person*, Person*, bool>
{
public:
	bool operator()(Person* p1, Person* p2) const
	{
		return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
	}
};

void test03()
{
	vector<Person*> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person* p = new Person("bbb", 20);

	// 对于超过的两个值，需要采用适配器
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyComparePerson(), p));

	if (pos != v.end())
	{
		cout << "找到了元素--- 姓名： " << (*pos)->m_Name << " 年龄： " << (*pos)->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


//adjacent_find算法 查找相邻重复元素
void test04()
{
	vector<int>v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(300);
	v.push_back(300);
	v.push_back(6);
	v.push_back(3);

	vector<int>::iterator ret = adjacent_find(v.begin(), v.end());

	if (ret != v.end())
	{
		cout << "找到了相邻的重复元素： " << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
*/

void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(4);  必须是有序序列，如果无效 结果未知

	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
	{
		cout << "查到了数据2" << endl;
	}
	else
	{
		cout << "未找到数据2" << endl;
	}

}

/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
class GreaterThan3
{
public:
	bool operator()(int val)
	{
		return val >= 3;
	}
};

void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 3);

	cout << "3的个数为： " << num << endl;


	//统计大于等于3的个数
	num = count_if(v.begin(), v.end(), GreaterThan3());
	// 0 1 2 3 4 5 6 7 8 9 3 3 3 
	cout << "大于等于3的个数为： " << num << endl;

}


int main() {
	//test01();
	test02();
	//test03();
	//test04();
	//test05();
	//test06();


	system("pause");
	return EXIT_SUCCESS;
}
```
### 08常用排序算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
/*
merge算法 容器元素合并，并存储到另一容器中
注意 : 两个容器必须是有序的,顺序要一致(同为升序 或者 同为降序)
*/

void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}


	vector<int>vTarget; //目标容器
	vTarget.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), [](int val) {cout << val << " "; });

}

//sort
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//降序排序

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}


//random_shuffle算法 对指定范围内的元素随机调整次序
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//random_shuffle(v.begin(), v.end());
	random_shuffle(v.begin(), v.begin() + 5);  // 对指定范围进行打乱
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//reverse算法 反转指定范围的元素
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	cout << "反转前打印：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;


	// reverse(v.begin(), v.end());
	reverse(v.begin(), v.begin() + 5);  // 对指定范围内进行反转

	cout << "反转后打印： " << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });

	cout << endl;
}

int main() {

	srand((unsigned int)time(NULL));

	//test01();
	//test02();
	//test03();
	test04();


	system("pause");
	return EXIT_SUCCESS;
}
```
### 09常用拷贝和替换算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>
//copy算法 将容器内指定范围的元素拷贝到另一容器中
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());  // 拷贝前需要指定容器大小
	copy(v.begin(), v.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	//cout << endl;

	// 利用copy进行打印  ostream_iterator的头文件是iterator
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

//replace算法 将容器内指定范围的旧元素修改为新元素
//replace_if(iterator beg, iterator end, _callback, newvalue) 按条件替换

class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//将容器中的3替换为 3000
	replace(v.begin(), v.end(), 3, 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;



	//将容器中所有大于3的都替换为 30000;  条件替换
	replace_if(v.begin(), v.end(), MyReplace(), 30000);
	// 0 1 2 30000 ...
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


//swap交换 -- 本质是交换指针
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2(2, 100);

	cout << "交换数据前：" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	cout << "交换数据后：" << endl;
	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

int main() {

	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
```
### 10常用算术生成算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> //accumulate算法头文件


//accumulate算法 计算容器元素累计总和
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int num = accumulate(v.begin(), v.end(), 1000); // 参数3代表 累加起始值

	cout << "num = " << num << endl;
}

//fill算法 向容器中添加元素
void test02()
{
	vector<int>v;
	v.resize(10);

	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

}


int main() {

	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}
```
### 11常用集合算法.cpp
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
set_intersection算法 求两个set集合的交集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;

	vTarget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;
}


/*
set_union算法 求两个set集合的并集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test02()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;
}

/*
set_difference算法 求两个set集合的差集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/

void test03()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(max(v1.size(), v2.size()));

	// A 与 B 差集
	//vector<int>::iterator itEnd  = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// B 与 A 差集
	vector<int>::iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());


	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " "; });
	cout << endl;

}


int main() {
	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}
```


