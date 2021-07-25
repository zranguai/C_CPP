#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void test01()
{
	//����  a  s     ��һ�� a  �ڶ���  s  ������ ����  ���Ĵ� �ȴ��´�����
	char c = cin.get();

	cout << "c = " << c << endl;

	c = cin.get();
	
	cout << "c = " << c << endl;

	c = cin.get();

	cout << "c = " << c << endl;


	c = cin.get();

	cout << "c = " << c << endl;
}


void test02()
{
	char buf[1024] = { 0 };
	cin.get(buf, 1024);

	char c = cin.get();
	//����cin.get��ȡ�ַ���ʱ�򣬻��з������ڻ�������
	if (  c== '\n')
	{
		cout << "���з������ڻ�����" << endl;
	}
	else
	{
		cout << "���з����ڻ�����" << endl;
	}
	cout << buf << endl;

}

void test03()
{
	char buf[1024] = { 0 };

	//����cin.getline��ȡ�ַ���ʱ�򣬻��з����ᱻȡ�ߣ�Ҳ���ڻ������У�����ֱ���ӵ�
	cin.getline(buf, 1024);

	char c = cin.get();
	if (c == '\n')
	{
		cout << "���з������ڻ�����" << endl;
	}
	else
	{
		cout << "���з����ڻ�����" << endl;
	}
	cout << buf << endl;

}

//cin.ignore() ���� Ĭ�Ϻ���1���ַ��� ����������X���������X���ַ�
void test04()
{
	cin.ignore(2);
	char c = cin.get();
	cout << "c = " << c << endl;
}

//cin.peek() ͵��
void test05()
{
	char c = cin.peek();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

}

//cin.putback() �Ż�
void test06()
{
	char c = cin.get();
	cin.putback(c);

	char buf[1024] = { 0 };

	cin.getline(buf, 1024);
	cout << buf << endl;
}


//����1�� �ж��û���������� ���ַ�����������  12345     abcde
void test07()
{
	cout << "������һ���ַ�����������" << endl;
	char c = cin.peek();

	if (c >= '0' && c <= '9')
	{
		int num;
		cin >> num;
		cout << "������������� Ϊ��" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "����������ַ��� ��" << buf << endl;
	}
}

//����2�� �û����� 0 ~ 10 ֮������֣��������������������
void test08()
{
	cout << "������ 0 ~ 10 ֮�������" << endl;

	int num;

	while (true)
	{
		cin >> num;

		if (num >= 0 && num <= 10)
		{
			cout << "������ȷ������ֵΪ��" << num << endl;
			break;
		}
		
		//��ջ����� ���ñ�־λ 
		cin.clear();
		cin.sync();
		//cin.ignore();//vs2013���ϰ汾���� 
		//�����־λΪ 0  ������������    �����־λΪ1   �������쳣
		//cout << " cin.fail()  = " << cin.fail() << endl;
		
		cout << "�����������������룺 " << endl;
	}

}

int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

	
	
	system("pause");
	return EXIT_SUCCESS;
}