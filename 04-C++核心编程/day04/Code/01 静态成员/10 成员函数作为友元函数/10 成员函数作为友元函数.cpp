#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
class Building;
class GoodGay
{
public:

	GoodGay();

	void visit(); //���Է���building��˽��

	void visit2(); // �����Է���building��˽��

	Building * m_building;
};

class Building
{
	//��GoodGay���е� visit��Ա������Ϊ��Ԫ
   friend void GoodGay::visit();
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
	this->m_building = new Building;
}

void GoodGay::visit()
{
	cout << "�û������ڷ��ʣ� " << this->m_building->m_SittingRoom << endl;
	cout << "�û������ڷ��ʣ� " << this->m_building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "�û������ڷ��ʣ� " << this->m_building->m_SittingRoom << endl;
	//cout << "�û������ڷ��ʣ� " << this->m_building->m_BedRoom << endl;
}


void test01()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}