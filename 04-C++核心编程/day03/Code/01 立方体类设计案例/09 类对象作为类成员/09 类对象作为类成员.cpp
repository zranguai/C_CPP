#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Phone
{
public:

	Phone(string pName)
	{
		cout << "phone ���вι������" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "phone ��������������" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:

	Game(string gName)
	{
		cout << "Game ���вι������" << endl;
		m_GameName = gName;
	}
	~Game()
	{
		cout << "Game ��������������" << endl;
	}

	string m_GameName;
};


class Person
{
public:

	Person(string name, string pName, string gName) : m_Name(name), m_Phone(pName), m_Game(gName)
	{
		cout << "Person ���вι������" << endl;
	}

	void PlayGame()
	{
		cout << m_Name << "���� << " << m_Phone.m_PhoneName << " >> ���ֻ������� :" << m_Game.m_GameName << endl;
	}

	~Person()
	{
		cout << "Person ��������������" << endl;
	}

	string m_Name; //����
	Phone m_Phone; //�ֻ�
	Game  m_Game;  //��Ϸ
};



void test01()
{
	//����������� ��Ϊ�����Ա���ȹ�������������ٹ�������������˳��͹����෴
	Person p("����", "ƻ��", "������ҫ");
	p.PlayGame();

	Person p2("����", "����", "������");
	p2.PlayGame();
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}