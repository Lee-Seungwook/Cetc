// InheritEx0513.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Mammal
{
public:
	Mammal() //기본생성자 함수
	{
		cout << "나는 Mammal의 기본생성자" << endl;
	}
}; // : 상속 기호, 상속 관계이면 다른 클래스의 함수, 변수들을 가져다 사용할 수 있음

class  Person : public Mammal // (상속할 범위)  부모=mammal, 자식=person
{                       // public>>protected>>private
protected: // protected접근 권한자는 외부에서는 참조가 불가능 하지만 상속받은 클래스는 참조 가능
   //char  name[30] = { '\0', };
	const int IQ;
	char *name;
	int   age = 0;
public: // 외부객체들도 접근 가능
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

class Man : public Person // public권한 만큼 person(부모)클래스에서의 함수, 변수를 쓸 수 있음
{                         // mammal>>person>>man =>mammal은 man의 2차부모, person은 1차부모
	char myname[30];
	int money;
	char *job;
public:
	void work()
	{
		cout << "Man이 일한다." << endl;
	};
	Man()
	{
		cout << "나는 Man의 기본생성자" << endl;
		age = 0;
		talk();
		strcpy_s(myname, strlen(name) + 1, name); // name변수는 접근권한이 private이기 때문에 가져다 쓸 수x =>권한을 proteccted로 바꾸면 가능 
	}
	// 이미 만들어져있는 person클래스의 변수들을 가져다 씀(코드의 중복을 최소화 하기 위해)
};

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
	// *hyunjin= 객체포인터변수

	Man *hyunjin = new Man(); // 최상위 클래스(mammal)를 복사(객체 생성=기본생성자 함수 실행)
						// ->다음 클래스(person)를 복사(객체 생성/ parameter가없기 때문에 기본생성자 실행)
						//-> 마지막으로 Man클래스가 실행(person 클래스의 자식이기 때문)
	// hyunjin객체는 여러가지 타입을 갖을 수 있다() = 다형성

	hyunjin->work(); // 생성된 hyunjin객체가 work() 메소드를 찾기 위해서 상위(부모)쪽으로 올라가며 찾음
					 // hyunjin객체의 타입이 Person이면 Person클래스부터 위쪽(부모)으로 메소드를 찾는다.
	hyunjin->talk();
	return 0;
}