#include "pch.h"
#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(int page, const char pname[30]) : age(page), iq(100)
{

	cout << "난 인자 둘인 Person 생성자" << endl;
	//age = page;
	name = new char[strlen(pname) + 1];   //동적메모리 20바이트 할당
	strcpy_s(name, strlen(pname) + 1, pname);
}

const int Person::getAge() const
{
	//age = 38;  //error
	//name = NULL; //error
	return age;
}

inline void Person::setAge(int page)     //  :: (영역연산자)
{
	age = page;
}