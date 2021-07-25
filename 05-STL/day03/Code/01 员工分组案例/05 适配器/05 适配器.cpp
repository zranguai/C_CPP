#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class MyPrint :public binary_function<int,int,void>
{
public:
	void operator()(int val , int start)const 
	{
		cout << "val = " << val << " start = " << start <<  " sum = " <<val +  start << endl;
	}
};
//1����������������
void test01()
{
	vector<int>v;

	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	cout << "��������ʼ�ۼ�ֵ�� " << endl;
	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd( MyPrint(), num ) );
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

//1������bind2nd ���а�
//2���̳� public binary_function<����1 ����,����2����,����ֵ����>
//3����const


//2��ȡ��������
class GreaterThanFive:public unary_function<int,bool>
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
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//һԪȡ��
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThanFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( bind2nd( greater<int>() , 5 )));

	if (pos != v.end())
	{
		cout << "�ҵ�С��5��ֵΪ�� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


	//��Ԫȡ��
	sort(v.begin(), v.end(),  not2 (less<int>()));
	for_each(v.begin(), v.end(), [](int val){cout << val << endl; });
}

//1������not1����ȡ��
//2���̳� public unary_function<int,bool>
//3����const


void myPrint3( int val , int start) 
{
	cout << val + start << endl;
}
//3�� ����������
void test03()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//������ָ�� ����ɺ�������  ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 1000));
}


//4����Ա����������
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
		cout << "��Ա����----������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
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
//	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
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
	//���� mem_fun_ref
	for_each(v.begin(), v.end(),  mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main(){

//	test01();
//	test02();
//	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}