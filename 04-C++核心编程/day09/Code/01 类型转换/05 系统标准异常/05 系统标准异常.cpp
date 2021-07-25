#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdexcept> //  std ��׼  except �쳣


class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("��������� 0 ~ 150֮��");
			//throw length_error("��������� 0 ~ 150֮��");
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};

void test01()
{
	try
	{
		Person p(151);
	}
	//catch ( out_of_range &e)
	catch ( exception &e)
	{
		cout << e.what() << endl;
	}

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}