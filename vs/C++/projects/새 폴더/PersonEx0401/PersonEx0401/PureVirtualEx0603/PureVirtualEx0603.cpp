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
	virtual ~StarCraft()
	{
		cout << "난 StarCraft 기본소멸자" << endl;
	}

	virtual void zergAttack() = 0;
	virtual void terranAttack() = 0;
	virtual void print() = 0;
	virtual void GoodGame() = 0;
};

class Zerg : virtual public StarCraft
{
protected:
	int zerg;
public:
	Zerg() {}
	Zerg(int pzerg) : StarCraft()
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
	/*virtual void print() 
	{}*/
};

class Terran :virtual public StarCraft
{
protected:
	int terran;
public:
	Terran(){}
	Terran(int pterr) : StarCraft()
	{
		cout << "난 Terran 생성자" << endl;
		terran = pterr;
	}
	~Terran()
	{
		cout << "난 Terran 기본소멸자" << endl;
		
	}
	virtual void terranAttack()
	{
		cout << "terran 공격 개시" << endl;
	}
	/*virtual void GoodGame()
	{}*/ 
};

class Game : public Zerg, public Terran
{
	static int Nuclear;
	char* name;
public:
	Game(int zerg, int terran, int pnu, const char* pname) : Zerg(zerg), Terran(terran) 
	{
		cout << "난 Game 생성자" << endl;
		Nuclear = pnu;
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);
	}
	~Game()
	{
		cout << "나는 Game 기본소멸자" << endl;
	}
	virtual void zergAttack() { Zerg::zergAttack(); }
	virtual void terranAttack() { Terran::terranAttack(); }
	virtual void print() 
	{
		cout << "zerg = " << zerg << ", terran = " << terran << ", Nuclear = " << Nuclear << ", Name = " << name << endl; 
	}
	virtual void GoodGame() {}
};

int Game::Nuclear = 1;

int main()
{
	//Game *yuneaol = new Game(5,7,2,"이윤열");
	StarCraft *yuneaol = new Game(5, 7, 2, "이윤열");
	yuneaol->print();
	yuneaol->zergAttack();
	yuneaol->terranAttack();
	
	delete yuneaol;
	return 0;
}

