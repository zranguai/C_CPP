#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <functional>  //�ڽ���������  ͷ�ļ�
#include <vector>
#include <algorithm>
/*
template<class T> T negate<T>//ȡ���º���  һԪ����
*/

void test01()
{
	negate<int>n;

	cout << n(10) << endl;

}
//template<class T> T plus<T>//�ӷ��º���
void test02()
{
	plus<int> p;

	cout << p(10, 10) << endl;

}

//template<class T> bool greater<T>//����
void test03()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);

	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());


	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
	cout << endl;
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}