#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Building
{
	//����friend�ؼ�����ȫ�ֺ���  goodGay��Ϊ��������ѣ����Է���˽�г�Ա
	friend void goodGay(Building * buliding);

public:
	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom; //����
};

//�û���ȫ�ֺ���  ���Է���Building��˽������
void goodGay( Building * buliding)
{
	cout << "�û������ڷ��ʣ�" << buliding->m_SittingRoom << endl;

	cout << "�û������ڷ��ʣ�" << buliding->m_BedRoom << endl;
}

void test01()
{
	Building buliding;
	goodGay(&buliding);
}

int main(){
	test01();
	

	system("pause");
	return EXIT_SUCCESS;
}