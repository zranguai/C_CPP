#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class News
//{
//public:
//
//	void header()
//	{
//		cout << "������ͷ��" << endl;
//	}
//	void footer()
//	{
//		cout << "�����ĵײ�" << endl;
//	}
//	void leftList()
//	{
//		cout << "����������б�" << endl;
//	}
//
//	void content()
//	{
//		cout << "���Ų���..." << endl;
//	}
//};
//
//
//class Sport
//{
//public:
//
//	void header()
//	{
//		cout << "������ͷ��" << endl;
//	}
//	void footer()
//	{
//		cout << "�����ĵײ�" << endl;
//	}
//	void leftList()
//	{
//		cout << "����������б�" << endl;
//	}
//
//	void content()
//	{
//		cout << "���籭����..." << endl;
//	}
//};


//���ü̳�ģ����ҳ
//�̳��ŵ㣺 �����ظ��Ĵ��룬��ߴ��븴����
class BasePage
{
public:
	void header()
	{
		cout << "������ͷ��" << endl;
	}
	void footer()
	{
		cout << "�����ĵײ�" << endl;
	}
	void leftList()
	{
		cout << "����������б�" << endl;
	}
};
// �﷨�� class ���� �� �̳з�ʽ   ����
// News		����    ������
// BasePage ����    ����
class News : public BasePage
{
public:
	void content()
	{
		cout << "���Ų���..." << endl;
	}
};

class Sport :public BasePage
{
public:
	void content()
	{
		cout << "���籭..." << endl;
	}

};


void test01()
{
	News news;
	cout << "����ҳ���������£�" << endl;
	news.header();
	news.footer();
	news.leftList();
	news.content();


	Sport sp;
	cout << "����ҳ���������£�" << endl;
	sp.header();
	sp.footer();
	sp.leftList();
	sp.content();

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}