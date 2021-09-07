#include "pch.h"
#include <iostream>
using namespace std;

class Person
{
private:
	const int iq;
	//char name[30] = { '\0' , };
	char* name;
	int age = 0;

public:
	Person() : age(0), name(NULL), iq(100)   //->> : 이용해 초기화
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
		cout << "~Person() 호출됨" << endl;
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
};     //end of class Person  //Person 클래스로 캡슐화 시켰다. (멤버들을 외부로부터 보호) //정보은닉

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
	const char* myname = "홍길동";
	cout << "myname = " << myname << endl;

	const Person kyungkuy;   //상수 객체는 상수 멤버함수만 호출 가능
	//kyungkuy.see();  //error
	kyungkuy.getAge();
	kyungkuy.talk();

	Person hodong;

	Person wonbin = Person(41, "원빈");
	//Person wonbin(41, "원빈");        
	wonbin.see();

	cout << "wonbin.name = " << wonbin.getName()
		<< ", wonbin.age = " << wonbin.getAge() << endl;

	Person *pjaesuk = new Person(45, "유재석");
	cout << "pjaesuk -> age = " << pjaesuk->getAge() << endl;

	cout << "pjaesuk -> name = " << (*pjaesuk).getName()
		<< ", pjaesuck -> age = " << pjaesuk->getAge() << endl;


	delete pjaesuk;

	return 0;
}