#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
class Building;
class GoodGay
{
public:

	GoodGay();

	void visit();

	Building * m_building;
};

class Building
{
	//��goodGay����Ϊ Building�ĺ����ѣ����Է���˽�г�Ա
	friend class GoodGay;

public:
	Building();

	string m_SittingRoom;

private:
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	this->m_building =  new Building;
}

void GoodGay::visit()
{
	cout << "�û������ڷ��ʣ� " << this->m_building->m_SittingRoom << endl;
	cout << "�û������ڷ��ʣ� " << this->m_building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}