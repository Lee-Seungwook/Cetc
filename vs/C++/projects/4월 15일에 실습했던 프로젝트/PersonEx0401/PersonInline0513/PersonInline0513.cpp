// PersonInline0513.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

class  Person
{
private:
	//char  name[30] = { '\0', };
	const int IQ;
	char *name;
	int   age = 0;
public:
	Person() : age(0), name(NULL), IQ(100) //멤버변수 값을 초기화가능, : 멤버초기자
	{

		cout << "난 Person 기본생성자" << endl;
	}

	Person(int page, const char  pname[30]); // 생성자 함수 헤더만 표현


	~Person()//Destructor Method(소멸자)
	{
		cout << "~Person() 호출됨" << endl;
		if (name != NULL)
			delete[] name;
	}

	char* getName() const
	{
		return  (char*)name;
	}

	void setName(const char  pname[30])
	{
		strcpy_s(name, strlen(pname) + 1, pname);
	}

	const int getAge() const; // 상수함수 표현은 구현부, 선언부 다 써줘야됨

	inline void setAge(int   page); // inline을 붙이면 명시적으로 인라인 함수가 됨(선언할때만 inline써주면 됨, 구현부에서는 할 필요x 하는것이 원칙)

	void  talk() const // 자동인라인 함수, talk함수의 스택이 생성되지 않고 main스택에서 함수의 요소들을 바로 실행.
	{
		//age = 45;//error
		cout << "Person 이 말한다" << endl;
	}

	void  see()
	{
		talk();
		cout << "Person 이 본다" << endl;
	}
};  //end of class Person

Person::Person(int page, const char  pname[30]) : age(page), IQ(100)
{
	cout << "난 인자 둘인 Person생성자" << endl;

	name = new char[strlen(pname) + 1];
	strcpy_s(name, strlen(pname) + 1, pname);
}

const int Person::getAge() const
{
	// name = NULL; //error
	// age=38; // error
	return  age;
}
void Person::setAge(int   page) // ::=범위지정 연산자, 소속을 밝혀줌, 인라인 함수x(클래스 바깥에 존재하기 때문)
{
	age = page;
	//cout << "age=" << age << endl;
}
int main()
{
	const char* myname = "홍길동";
	cout << "my name=" << myname << endl;

	const Person gyunggyu; // 기본 생성자 
	gyunggyu.getAge();
	gyunggyu.talk();

	Person hodong;



	Person  wonbin(41, "원빈");
	cout << "wonbin.name=" << wonbin.getName()
		<< ", wonbin.age=" << wonbin.getAge()
		<< endl;


	Person  *pjaesuk = new Person(45, "유재석");
	cout << "pjaesuk->age" << pjaesuk->getName() << endl;

	cout << "pjaesuk->name=" <<
		pjaesuk->getName() << endl;


	delete  pjaesuk;
	return  0;
}


