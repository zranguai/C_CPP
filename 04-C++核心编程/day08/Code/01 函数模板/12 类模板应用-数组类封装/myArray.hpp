#pragma  once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//MyArray(){};

	//�вι���
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray & arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//����=   
	MyArray& operator=( const MyArray & arr)
	{
		if (this->pAddress)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}


	//����[] 
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void pushBack(const T&val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//����
	~MyArray()
	{
		if (this->pAddress)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T * pAddress; //ָ�������ʵ����ָ��

	int m_Capacity; //��������

	int m_Size;  //�����С

};
