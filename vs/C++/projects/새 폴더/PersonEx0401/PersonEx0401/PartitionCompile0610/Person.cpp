#include "pch.h"
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(int page, const char pname[30]) : age(page), iq(100)
{

	cout << "�� ���� ���� Person ������" << endl;
	//age = page;
	name = new char[strlen(pname) + 1];   //�����޸� 20����Ʈ �Ҵ�
	strcpy_s(name, strlen(pname) + 1, pname);
}

const int Person::getAge() const
{
	//age = 38;  //error
	//name = NULL; //error
	return age;
}

inline void Person::setAge(int page)     //  :: (����������)
{
	age = page;
}