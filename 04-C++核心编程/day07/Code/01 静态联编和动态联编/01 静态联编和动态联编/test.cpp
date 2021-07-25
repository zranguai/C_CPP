#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

	virtual void eat(int a )
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	void eat(int a)
	{
		cout << "Сè�ڳԷ�" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};


//��̬��̬����������
//���м̳й�ϵ
//���������麯����������д�����е��麯��
//�����ָ�������  ָ������Ķ���

//�����и��ӹ�ϵ��������  ָ��������� �ǿ���ֱ��ת����
void doSpeak(Animal & animal) //Animal & animal = cat;
{
	//�����ַ��Ͱ󶨺��ˣ���ַ��󶨣����ھ�̬����
	//��������Сè˵�������ʱ�����ĵ�ַ�Ͳ�����Ͱ󶨺ã����������н׶���ȥ�󶨺�����ַ�����ڵ�ַ��󶨣��ж�̬����
	animal.speak(); 

}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}




void test02()
{
	//cout << "sizeof  Animal = " << sizeof (Animal) << endl;

	Animal * animal = new Cat;
	//animal->speak();
	// *(int *)animal �����õ��麯������
	// *(int *)*(int *)animal �����õ�����speak��ַ

	//����è˵��
	((void(*)()) (*(int *)*(int *)animal)) ();


	//C/C++Ĭ�ϵ��ù���  __cdecl
	//�����е���ʱ�� ��ʵ���ù���  �� __stdcall
	//����è�Է�
	typedef void( __stdcall *FUNPOINT)(int);

	(FUNPOINT (*((int*)*(int*)animal + 1)))(10);
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}