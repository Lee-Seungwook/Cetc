#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Man : public Person
{
	int money;
	char* job;

public:
	void work()
	{
		cout << "Man이 일한다." << endl;
	};

	Man() : Person()
	{
		cout << "나는 Man의 기본생성자" << endl;
	}

	Man(int page, const char* pn, int pmo, const char* pjob) : Person(page, pn)
	{
		cout << "인자 4개인 Man의 생성자" << endl;
		age = page;
		name = new char[strlen(pn) + 1];
		strcpy_s(name, strlen(pn) + 1, pn);
		//name = pn;
		job = new char[strlen(pjob) + 1];
		strcpy_s(job, strlen(pjob) + 1, pjob);
	}

	~Man()
	{
		cout << "나는 Man의 기소멸자" << endl;
	}

	void show()
	{
		Person::show();
		cout << "money = " << money << endl << "job = " << job << endl;
	}
};

