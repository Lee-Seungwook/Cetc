#pragma once
#include <iostream>
using namespace std;

class Mammal
{
public:
	//virtual void work() = 0;    //���������Լ�
	//virtual void work() {};         //�����Լ�
	Mammal()
	{
		cout << "�� Mammal �⺻������" << endl;
	}
	~Mammal()
	{
		cout << "�� Mammal �⺻�Ҹ���" << endl;
	}
};

