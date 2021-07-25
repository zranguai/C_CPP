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
3.6.4.1 list���캯��
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����
3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
*/

//��������
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

	//�������
	//for (list<int>::iterator it = L1.begin(); it != L1.end();it++)
	//{
	//	cout << *it << endl;
	//}
	//�������
	for (list<int>::reverse_iterator it = L1.rbegin(); it != L1.rend();it++)
	{
		cout << *it << endl;
	}

	//list�������ǲ���֧��������� ,�𰸣���֧�֣���һ��˫�������
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

	L.pop_back(); //βɾ
	L.pop_front(); //ͷɾ
	// 200 100 10 20
	printList(L);


	//����
	L.insert(L.begin(), 10000);
	// 10000 200 100 10 20
	printList(L);

	L.erase(L.begin());
	// 200 100 10 20 
	printList(L);

	//remove ɾ��������������elemֵƥ���Ԫ�ء�
	L.push_back(100);
	L.push_back(100);
	L.remove(100);
	printList(L);

}

/*
3.6.4.3 list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
3.6.4.5 list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�
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
3.6.4.6 list��ת����
reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
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

	//��ת
	L.reverse();

	printList(L);

	//����  
	//��������ĵ�����֧��������ʣ�����ʹ��ϵͳ�ṩ�ı�־�㷨
	//��֧��������ʵĵ��������������ڲ����ṩ��Ӧ���㷨�ӿ�
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

	Person p1("��ɪ", 40 ,  180);
	Person p2("����", 20 , 160);
	Person p3("槼�", 30 , 120);
	Person p4("�����", 50 , 200);
	Person p5("����", 10 ,  170 );
	Person p6("����", 10  , 165);
	Person p7("�ŷ�", 10 , 185);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//����������н���   �Ӵ��� , ���������ȣ�������߽������� 
	//�����Զ����������ͣ�����Ҫָ���������
	L.sort(myComparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << " ��ߣ� "<< it->m_Height <<endl;
	}

	//ɾ�������
	L.remove(p4);

	cout << "ɾ������պ�" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << " ��ߣ� " << it->m_Height << endl;
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