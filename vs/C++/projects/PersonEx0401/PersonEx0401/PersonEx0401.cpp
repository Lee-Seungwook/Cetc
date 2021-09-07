#include "pch.h"
#include"iostream"
using namespace std;

class person
{
	//private: //캡슐 내부에서는 접근이 가능하지만 외부에서의 접근은 할 수 없다.
	//public: //캡슐화를 임시로 풀어주기 위하여
private:
	char name[30] = { '\0' };
	int age = 0;

public: // talk와 see는 외부에서 접근 가능하다.
	person() // 생성자 함수
	{
		strcpy_s(name, strlen("\0") + 1, "\0");
		cout << "난 person 기본생성자" << endl;
	}

	person(int page, const char pname[30])
	{
		cout << "난 인자 둘인 person 생성자" << endl;
		age = page;
		strcpy_s(name, strlen(pname) + 1, pname);
	} /* 파라미터 (괄호안에 값들어가는)가 있는 함수를 만드려면 기본 함수가 필수로 필요하다.
	  (즉, perso(int page, const char pname [30]이 있으려면, person()일 필요하다.)*/

	int getname()
	{
		return (char*)name;
	}

	void setname(const/*상수화 시키겠다.*/ char pname[30])
	{
		strcpy_s(name, strlen(pname) + 1, pname);
		
	}

	void Setage(int page)
		//내부에 함수(Setage)를 선언하여, private으로 선언한 age의 값을 수정하고 출력할수 있다.
	{
		age = page;
		cout << "age=" << age << endl;
	}

	void setage()
	{
		age = 45;
		cout << "age= " << age << endl;
	}

	int getage() //  멤버함수를 호출하여, private으로 선언한 age를 외부에서 호출하고 출력할 수 있게 해준다.
	{
		return age;
	}

	void talk() // method (멤버함수)
	{
		age = 7;
		cout << "person이 말한다." << endl;
	}
	void see() // method
	{
		talk();
		cout << "person이 본다." << endl;
	}

};



int main()
{
	//person  hodong;/*hodong 이라는 객체를 생성, 호동=객체참조변수, 인스턴스변수*/
	//클래스가 하나의 타입이된다.(persond은 참조형타입)
	//hodong.setage = 7;
	int num[3] = { 0, 1, 2 };
	int val[3] = { 0, 1, 2 };
	person hodong;
	//hodong.name = "강호동"; // <-  큰 따옴표로 묶인 것은 컴파일러에서 문자열 상수데이터로 취급한다.
	//person hodong = person()/*<- person() 생성자 함수라 한다.*/;
	//person wonbin = person{ 41, "원빈" };
	person wonbin{ 41, "원빈" }; // 위의 wonbin과 같은 결과가 나온다.
	cout << "wonbin.name=" << wonbin.getname() << "wonbin.age=" << wonbin.getage() << endl;
	hodong.setname("강호동");
	cout << "hodong.name=" << hodong.getname() << endl;
	//strcpy_s(hodong.name, strlen("강호동") +1 /*+1은 널문자가 들어갈 자리를 확보하기 위함이다.*/, "강호동");
	hodong.Setage(45);
	hodong.setage();
	cout << "hodong.age=" << hodong.getage() << endl;
	hodong.talk();/*public:때문에 talk함수 실행 가능*/

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
