#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//CPU����
class CPU
{
public:
	virtual void calculate() = 0;
};
//�Կ�����
class VideoCard
{
public:
	virtual void display() = 0;
};
//�ڴ����
class Memory
{
public:
	virtual void storage() = 0;
};


//������
class computer
{
public:

	computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		cout << "���Թ������" << endl;
		this->m_Cpu = cpu;
		this->m_Vc = vc;
		this->m_Mem = mem;
	}

	void doWork()
	{
		this->m_Cpu->calculate();
		this->m_Vc->display();
		this->m_Mem->storage();
	}

	~computer()
	{
		cout << "������������" << endl;
		if (this->m_Cpu)
		{
			delete this->m_Cpu;
			this->m_Cpu = NULL;
		}
		if (this->m_Vc)
		{
			delete this->m_Vc;
			this->m_Vc = NULL;
		}
		if (this->m_Mem)
		{
			delete this->m_Mem;
			this->m_Mem = NULL;
		}
	}

	CPU * m_Cpu;
	VideoCard * m_Vc;
	Memory * m_Mem;
};


//inter����
class intelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "intelCPU��ʼ������" << endl;
	}
};

class intelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "intel �Կ���ʼ��ʾ��" << endl;
	}

};
class intelMemory :public Memory
{
public:
	void storage()
	{
		cout << "intel �ڴ�����ʼ�洢��" << endl;
	}
};


//Lenovo ����
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo CPU��ʼ������" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo �Կ���ʼ��ʾ��" << endl;
	}

};
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo �ڴ�����ʼ�洢��" << endl;
	}
};


void test01()
{
	cout << "��һ̨������ɣ�" << endl;

	CPU * intelCpu = new intelCPU;
	VideoCard * lenovoVC = new LenovoVideoCard;
	Memory * lenovoMem = new LenovoMemory;

	computer c1(intelCpu, lenovoVC, lenovoMem);

	c1.doWork();

	cout << "�ڶ�̨������ɣ�" << endl;

	CPU * intelCpu2 = new LenovoCPU;
	VideoCard * lenovoVC2 = new intelVideoCard;
	Memory * lenovoMem2 = new intelMemory;

	computer c2(intelCpu2, lenovoVC2, lenovoMem2);

	c2.doWork();


}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}