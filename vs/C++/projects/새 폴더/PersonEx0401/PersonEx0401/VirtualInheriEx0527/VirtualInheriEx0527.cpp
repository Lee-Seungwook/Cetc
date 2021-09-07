#include "pch.h"
#include <iostream>
using namespace std;

class Animal
{
protected:
	int age;
public:
	virtual~Animal()
	{
		cout << "난 Animal 소멸자" << endl;
	}
	virtual void show() //중계하는 역할
	{
		cout << "show 메서드 age = " << age << endl;
	}
	int getAge()
	{
		return age;
	}

	Animal()
	{
		age = 7;
		cout << "난 Animal 기본생성자" << endl;
	}
};

class Horse :virtual public Animal
{
public:
	//Override
	void show()  //얘도 virtual --> virtul 태그 없지만 가상메서드가 됨 (가상메서드는 상속되기때문에)
	{
		cout << "난 Horse의 show()" << endl;
	}
	~Horse()
	{
		cout << "난 Horse 소멸자" << endl;
	}
	virtual void sleep() = 0; //중계시켜줌
	Horse() :Animal()
	{
		cout << "난 Horse 기본생성자" << endl;
	}
	void run()
	{
		cout << "Horse가 달린다." << endl;
	}
};

class Bird : virtual public Animal
{
public:
	virtual ~Bird() 
	{
		cout << "난 Bird 소멸자" << endl;
	}
	Bird() : Animal()
	{
		cout << "난 Bird 기본생성자" << endl;
	}
	void fly()
	{
		cout << "Bird가 난다." << endl;
	}
};

class Pegasus : public Horse, public Bird
{
public:
	~Pegasus()
	{
		cout << "난 Pegasus 소멸자" << endl;
	}
	Pegasus() :Horse(), Bird()
	{
		cout << "난 Pegasus 기본생성자" << endl;
	}
	//Override(재생) 시킨 메서드
	virtual void show() override //override 키워드는 가상메서드를 오버라이드할때 붙여줌 
	{
		//cout << "age = " << Horse::age << endl;
		cout << "Pegasus의 show 메서드 age = " << Bird::age << endl;
	}
	void sleep()
	{
		cout << "Pegasus가 잠잔다." << endl;
	}
};
int main()
{
	//Pegasus* pe = new Pegasus();
	//bird* pe = new Pegasus();
	Animal* pe = new Pegasus();
	pe->show();
	//pe->run();
	//pe->fly();
	//pe->sleep();
	//pe->show();
	cout << "age = " << pe->getAge() << endl;
	cout << "age = " << pe->getAge() << endl;

	delete pe;

	return 0;
}