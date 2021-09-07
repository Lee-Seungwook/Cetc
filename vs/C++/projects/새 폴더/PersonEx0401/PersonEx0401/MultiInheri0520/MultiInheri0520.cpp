#include "pch.h"
#include <iostream>
using namespace std;

class Animal
{
protected:
	int age;
public:
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

class Horse : public Animal
{
public:
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

class Bird : public Animal
{
public:
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
	Pegasus() :Horse(), Bird()
	{
		cout << "난 Pegasus 기본생성자" << endl;
	}
	void show()
	{
		cout << "age = " << Horse:: age << endl;
	}
	void sleep()
	{
		cout << "Pegasus가 잠잔다." << endl;
	}
};
int main()
{
	Pegasus* pe = new Pegasus();
	//bird* pe = new Pegasus();
	pe->run();
	pe->fly();
	pe->sleep();
	cout << "age = " << pe->Horse::getAge() << endl;
	cout << "age = " << pe->Bird::getAge() << endl;
	pe->show();

	return 0;
}