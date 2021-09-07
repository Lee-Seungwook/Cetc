// PureVirtualEx0603.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

class StarCraft  //100% 순수 가상 메서드로만 이루어진 클래스를 interface라고 한다.
{
public:
	StarCraft()
	{
		cout << "난 StarCraft 기본생성자" << endl;
	}
	~StarCraft()
	{
		cout << "난 StarCraft 기본소멸자" << endl;
	}

	virtual void zergAttack() = 0;
	virtual void terranAttack() = 0;
	virtual void print() = 0;
	virtual void GoodGame() = 0;
};

class Zerg : public StarCraft
{
	int zerg;
public:
	Zerg(int pzerg)
	{
		zerg = pzerg;
		cout << "나는 Zerg 생성자" << endl;
	}
	~Zerg()
	{
		cout << "나는 Zerg 기본소멸자" << endl;
	}
	virtual void zergAttack()
	{
		cout << "zerg 공격 개시" << endl;
	}
	virtual void print()
	{}
};

class Terran : public StarCraft
{
	int terran;
public:
	Terran(int pterr)
	{
		terran = pterr;
	}
	~Terran()
	{
		cout << "난 Terran 기본소멸자" << endl;
	}
	virtual void terranAttack()
	{
		cout << "난 Terran 공격개시" << endl;
	}
};

class Game : public Zerg, public Terran
{
	static int Nuclear;
	char* name;
public:
	Game(int zerg, int terran, int pnu, char* pname) : Zerg(zerg), Terran(terran)
	{ }
	~Game()
	{
		cout << "난 Game 기본소멸자" << endl;
	}
};

int main()
{
	Game *yunyeaol = new Game(5, 7, 2, "이윤열");
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
