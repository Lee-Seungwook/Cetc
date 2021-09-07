// InheriEx0513.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

using namespace std;

class Mammal {
public:
	Mammal()
	{
		cout << "난 Mammal기본생성자" << endl;
	}
};

/*public이면 Mammal에서 상속 허용된 모든것을 상속 받겠다, protected이면 일부만 상속, private은 더욱 소수만 상속 받는다.*/

class  Person : public Mammal //상속관계를 맺어 주겠다. (: <- 파생된다. derived extends) Mammal이 부모(기본, 상위), Person이 자식(파생, 하위) 클래스
{
protected:
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

//클래스 안의 멤버 함수는 다른 클래스에서 사용할수 없다. //하지만 두 클래스간의 부모 자식의 상속관계를 만들면 문제를 해결할수 있다.

class man : public Person
{
	int money;
	char myname[30];
public:
	man()
	{
		talk();
		strcpy_s(myname, strlen(name) + 1, name); //private으로 선언된 것은 상속 관계여도 사용할 수 없다.
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


int main()
{
	new Person();
	Man *hyunjin = new Man();

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
