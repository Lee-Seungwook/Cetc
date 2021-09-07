// VirtualInheriEx0527.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Animal
{
protected:
	int age; //자식 객체에서 접근 가능
public:
	void disp()
	{
		cout << "disp 메서드 age=" << age << endl;
	}
	int getage()
	{
		return age;
	}
	Animal()
	{
		age = 7;
		cout << "난 Animal 기본생성자" << endl;
	}
};

class Horse : virtual public Animal
{
public:
	virtual void sleep() = 0; //=0의 의미는 순수 가상함수라는 의미이다. method의 헤더만 존재(몸통 존재 X), 자식클래스에 있는 함수를 호출시켜줌(중계시켜줌)
	Horse() : Animal() // Horse의 기본 생성자를 호출시키기전에 Animal클래스의 기본생성자를 먼저 복사
	{
		cout << "나는 Horse의 기본생성자 입니다." << endl;
	}
	void run()
	{
		cout << "Horse가 달린다." << endl;
	}
};


class Bird :virtual public Animal
{
public:
	~Bird()
	{
		cout << "난 Bird의 소멸자" << endl;
	}
	Bird() : Animal()
	{
		cout << "나는 Bird의 기본 생성자입니다." << endl;
	}
	void fly()
	{
		cout << "Bird가 날아간다." << endl;
	}
};


class Pegasus : public Horse, public Bird
{
public:
	~Pegasus()
	{
		cout << "난 Pegasus 소멸자" << endl;
	}
	Pegasus() : Horse(), Bird()
	{
		cout << "난 Pegasus 기본생성자" << endl;
	}
	void show()
	{
		cout << "age=" << Horse::age << endl; //cout << "age=" << Bird::age << endl; 이것또한 실행 가능
	}
	void sleep()
	{
		cout << "Pegasus가 잠잔다." << endl;
	}
};

int main()
{
	Pegasus* pe = new Pegasus();
	//pe->disp();
	pe->run();
	pe->fly();
	pe->sleep();
	pe->show();
	cout << "age=" << pe->getage() << endl;

	cout << "age=" << pe->Horse::getage() << endl;
	cout << "age=" << pe->Bird::getage() << endl;
	delete pe;

	/*Horse* pe = new Pegasus();
	pe->run();
	pe->fly();
	pe->sleep();
	pe->show();
	cout << "age=" << pe->Horse::getage() << endl;
	cout << "age=" << pe->Bird::getage() << endl;*/

	/*Bird* pe = new Pegasus();
	pe->run();
	pe->fly();
	pe->sleep();
	pe->show();
	cout << "age=" << pe->Horse::getage() << endl;
	cout << "age=" << pe->Bird::getage() << endl;*/

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
