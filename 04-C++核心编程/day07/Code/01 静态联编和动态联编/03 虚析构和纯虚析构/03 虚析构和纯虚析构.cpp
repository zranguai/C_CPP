#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal�Ĺ��캯������" << endl;
	}
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
	//�����������ָ����������ԣ���ôҪ�������������� ��delete��ʱ�� �����������������
	//virtual ~Animal()
	//{
	//	cout << "Animal��������������" << endl;
	//}

	//�������� ��Ҫ������ Ҳ��Ҫ��ʵ��
	//���һ������ ���� ����������������ô�����Ҳ���ڳ����࣬�޷�ʵ����������
	virtual ~Animal() = 0;

};

Animal::~Animal()
{
	cout << "Animal�Ĵ���������������" << endl;
}


class Cat :public Animal
{
public:
	Cat(char * name)
	{
		cout << "Cat�Ĺ��캯������" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual void speak()
	{
		cout << this->m_Name <<" Сè��˵��" << endl;
	}

	~Cat()
	{
		if (this->m_Name)
		{
			cout << "Cat��������������" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}
	char * m_Name;
};

void test01()
{
	Animal * animal = new Cat("Tom");
	animal->speak();

	delete animal;
}




int main(){
	test01();

	//Animal aaa;  ��Animal�����˴���������Ҳ���ڳ�����

	system("pause");
	return EXIT_SUCCESS;
}