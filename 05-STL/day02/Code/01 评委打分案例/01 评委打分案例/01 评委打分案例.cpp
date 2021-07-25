#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
//5. person.score = ƽ����
*/

class Player
{
public:
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;  //����
	int m_Score; //ƽ����
};


void createPlayer(vector<Player>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "ѡ��";
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
		deque<int>d; //�����ί��ֵ�����
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~  100
			d.push_back(score);
		}

		//cout << it->m_Name << "��������" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//����
		sort(d.begin(), d.end());

		//ȥ�������ͷ�
		d.pop_back();  // ��߷�
		d.pop_front(); // ��ͷ�

		//�ܷ�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//ƽ����
		int avg = sum / d.size();

		it->m_Score = avg;
	}
}

void showScore(vector<Player>&v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "������ " << (*it).m_Name << " ƽ�������� " << it->m_Score << endl;
	}
}

int main(){

	//�������������
	srand((unsigned int)time(NULL));

	//1������5��ѡ��
	vector<Player> v;
	createPlayer(v);

	//2�����
	setScore(v);

	//3����ʾƽ����
	showScore(v);

	/*for (vector<Player>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "������ " << (*it).m_Name << " ������ " << it->m_Score << endl;
	}*/


	system("pause");
	return EXIT_SUCCESS;
}