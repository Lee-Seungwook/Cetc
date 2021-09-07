#include "pch.h"
#include <iostream>
#include <string>
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

class Person : public Mammal                                   //  :  상속기호
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
};     //end of class Person  //Person 클래스로 캡슐화 시켰다. (멤버들을 외부로부터 보호) //정보은닉

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

	Man(int page,  const char* pn, int pmo, const char* pjob) : Person(page, pn)
	{
		cout << "인자 4개인 Man의 생성자" << endl;
		age = page;
		name = new char[strlen(pn)+1];
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
		cout << "money = " << money << endl<< "job = " << job << endl;
	}
};

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

int main()
{
	int a = 7;
	Person *jisung = new Person();
	Person *chulsu = new Person(25, "김철수");
	Man *hyunjin = new Man();
	//Mammal *hyunjin = new Man();
	hyunjin->work();
	hyunjin->talk();

	Man *heungmin = new Man(32, "손흥민", 500, "soccer");
	heungmin->show();
	//heungmin->disp();

	delete jisung;
	delete chulsu;
	delete hyunjin;
	delete heungmin;


	return 0;
}