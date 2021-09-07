#pragma once
#include <iostream>
using namespace std;

class Mammal
{
public:
	//virtual void work() = 0;    //순수가상함수
	//virtual void work() {};         //가상함수
	Mammal()
	{
		cout << "난 Mammal 기본생성자" << endl;
	}
	~Mammal()
	{
		cout << "난 Mammal 기본소멸자" << endl;
	}
};

