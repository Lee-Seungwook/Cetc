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
		cout << "Man�� ���Ѵ�." << endl;
	};

	Man() : Person()
	{
		cout << "���� Man�� �⺻������" << endl;
	}

	Man(int page, const char* pn, int pmo, const char* pjob) : Person(page, pn)
	{
		cout << "���� 4���� Man�� ������" << endl;
		age = page;
		name = new char[strlen(pn) + 1];
		strcpy_s(name, strlen(pn) + 1, pn);
		//name = pn;
		job = new char[strlen(pjob) + 1];
		strcpy_s(job, strlen(pjob) + 1, pjob);
	}

	~Man()
	{
		cout << "���� Man�� ��Ҹ���" << endl;
	}

	void show()
	{
		Person::show();
		cout << "money = " << money << endl << "job = " << job << endl;
	}
};

