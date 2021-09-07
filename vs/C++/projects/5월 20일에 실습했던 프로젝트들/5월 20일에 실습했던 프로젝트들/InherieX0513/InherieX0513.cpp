// InherieX0513.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include<string>
using namespace  std;

class Mammal{ 
public:
	//virtual void work() = 0;
	//virtual void work() {   } ;
	Mammal()
	{
		cout << "난 Mammal기본생성자"	
			<< endl;
	}
	~Mammal()
	{
		cout << "난 Mammal 기본소멸자" 
			<< endl;
	}
};

class  Person  : public  Mammal
{
protected:
	const int  IQ;
	//char  name[30] = { '\0', };
	char*   name;
	int   age = 0;
public:

	//Person() //default constructor
	Person() : Mammal(), age(0), 
		name(NULL), IQ(100)
	{
		//IQ = 100; //ERROR
		//name = new char[strlen("\0") + 1];
		//strcpy_s(name, strlen("\0") + 1, "\0");
		cout << "난 Person 기본생성자" << endl;
	}
	Person(int page,
		const char  pname[30]);


	~Person()//Destructor Method(기본소멸자)
	{
		cout << "~Person() 소멸자호출됨" 
			<< endl;
		if (name != NULL)
			delete[]  name;
	}

	char*    getName() const
	{
		return  (char*)name;
	}

	void setName(const char  pname[30])
	{
		//strcpy_s(name, strlen(pname) + 1,
		//	pname);
	}

	const int  getAge() const;

	inline void setAge(int   page);

	void  talk() const //method(멤버함수)
	{
		//age = 45; //error
		cout << "Person 이 말한다" << endl;
	}
	void  see() //method
	{
		talk();
		cout << "Person 이 본다" << endl;
	}
	void  show()
	{
		cout <<"name=" << name<<", age="
			<< age << endl;
	}
};  //end of class Person

class  Man  :  public  Person
{
	int  money;
	char*  job;
public:
	~Man()
	{
		cout << "난 Man 기본소멸자" << endl;
	}
	void work()
	{  
		cout << "Man이 일한다." << endl;
	};
	Man() : Person()
	//Man() : Person(24 , "홍길동")
	{
		cout <<"난 Man의 기본생성자"<<endl;
	}
	Man(int  page, const char*  pn, 
		int  pmo, 
		const	char*   pjob) : 
		Person(page, pn)
	{
		cout << "인자 4개인 Man의 생성자" 
			<< endl;
		//age = page;
		//name = new char[strlen(pn) +1];
		//strcpy_s(name, strlen(pn)+1, pn);
		//name = pn;
		money = pmo;
		job = new char[strlen(pjob) + 1];
		strcpy_s(job, strlen(pjob) + 1,
						pjob);
	}
	//Method  Overriding(재생)
	void show()
	{		
		Person::show();
		cout << "money=" << money
			<< ", job=" << job << endl;
	}
};//end of class Man

Person::Person(int page,
	const char  pname[30]) :
	age(page), IQ(100)
{
	cout << "난 인자 둘인 Person생성자" << endl;
	//age = page;
	//name = pname;
	name = new char[strlen(pname) + 1];
	strcpy_s(name, strlen(pname) + 1,
		pname);
}

const int  Person::getAge() const
{
	//name = NULL;//error
	//age = 38;//error
	return   age;
}

inline void  Person::setAge(int   page)
{
	age = page;
	//cout << "age=" << age << endl;
}

int main()
{
	int a = 7;
	Person  *jisung = new Person();
	Person  *chulsu = 
				new Person(27,"김철수");
	//*hyunjin  : 객체포인터변수
	Man  *hyunjin = new Man();
	//Person  *hyunjin = new Man();
	//Mammal  *hyunjin = new Man();
	hyunjin->work();
	hyunjin->talk();

	Man  *heungmin = 
	  new Man(32, "손흥민", 500, "soccer");
	heungmin->show();
	//heungmin->disp();
	delete  heungmin;

	return 0;
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
