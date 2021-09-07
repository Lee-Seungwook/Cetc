// PersonEx0401.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
using namespace  std;

void  func()
{ cout << "func() 전역함수" << endl; }
void  func(int  a)
{ cout << "정수형 인자 한개인 func(int)" << endl; }
void  func(int  a, char   ch)
{
	cout << "인자 두개인 func(int, char)" << endl;
}

class  Person
{ 
private:
	char  name[30] = { '\0', };	
	int   age = 0;
public:
	
	Person() //default constructor
	{
		age = 0;  
		strcpy_s(name, strlen("\0") + 1, "\0");
		cout << "난 Person 기본생성자" << endl;
	}  

	Person(int page, const char  pname[30])
	{
		cout << "난 인자 둘인 Person생성자" << endl;
		age = page;
		strcpy_s(name, strlen(pname) +1, pname);
	}

	~Person()//Destructor Method(기본소멸자) - 소멸자는 기본 소멸자만 있다.
	{
		cout << "~Person() 호출됨" << endl;
	}

	char*    getName()
	{
		return  (char*)name;
	}

	void setName(const char  pname[30] )
	{
		strcpy_s(name,  strlen(pname)+1 , pname);
	}

	int getAge()
	{
		return  age;
	}
	void setAge(int   page)
	{
		age = page ;
		//cout << "age=" << age << endl;
	}
	void  talk() //method(멤버함수)
	{
		// age = 45;//가능
		cout << "Person 이 말한다" << endl;
	}
	void  see() //method
	{
		talk();
		cout << "Person 이 본다" << endl;
	}
};  //end of class Person

int main()
{
	func(); func(7); func(5, 'A');
	int  num[3] = { 0,1,2 };	int  val[3] = { 0,1,2 };
	//num = val;
	Person   hodong;
	//Person   hodong  =  Person() ;
	//Person  wonbin = Person( 41, "원빈");
	Person  wonbin(41, "원빈");
	cout << "wonbin.name=" << wonbin.getName()
		<< ", wonbin.age=" << wonbin.getAge()
		<< endl;

	//Person()=>기본생성자(Default Constructor)
	//hodong.name = "강호동";
	hodong.setName("강호동");
	cout << "hodong.name=" << 
			hodong.getName() << endl;
		
	//hodong.age = 45;
	hodong.setAge(45);
	cout << "hodong.age=" << hodong.getAge() << endl;
	//cout << "hodong.age=" << hodong.setAge(45) << endl;
	hodong.talk();

	Person  *pjaesuk = new Person(45, "유재석");
	//*pjaesuk ==>객체포인터변수

	cout << "pjaesuk->name=" <<
			pjaesuk->getName() << endl;
		//(*pjaesuk).getName() << endl;

	Person ob[4]; //ob는 객체 배열, Person()함수가 배열처럼 4개가 생성
	//Person ob[4] = { Person(), Person(), Person(), Person() }; // 위의 결과와 동일
	ob[3].setName("류현진");
	cout << "ob[3].name=" << ob[3].getName() << endl;

	delete  pjaesuk; 
	return  0;
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
