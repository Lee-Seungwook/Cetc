#pragma once
#include "Mammal.h"
#include <iostream>
using namespace std;

class Person : public Mammal
{
protected:
	const int iq;
	//char name[30] = { '\0' , };
	char* name;
	int age = 0;

public:
	Person() : Mammal(), age(0), name(NULL), iq(100)   //->> : 이용해 초기화
	{
		//iq = 100;  //error
		//age = 0;  
		//name = NULL;
		//name = new char[strlen( "\0" )+1];
		//strcpy_s(name, strlen("\0") + 1, "\0");  
		cout << "난 Person 기본생성자" << endl;
	}

	Person(int page, const char pname[30]);

	~Person()
	{
		cout << "~Person() 소멸자 호출됨" << endl;
		if (name != NULL)
			delete[] name;
	}

	void setName(const char pname[30])
	{
		//strcpy_s(name, strlen(pname) + 1, pname);

	}


	char* getName() const
	{
		return (char*)name;
	}

	const int getAge() const;

	inline void setAge(int page);

	void talk() const
	{
		cout << "Person이 말한다." << endl;
	}
	void see()
	{
		talk();
		cout << "Person이 본다." << endl;
	}

	void show()
	{
		cout << "name = " << name << ", age = " << age << endl;
	}
};



