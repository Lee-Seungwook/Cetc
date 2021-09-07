#include "pch.h"
#include <iostream>
using namespace std;

class samp
{
	int num = 0;
public:
	samp() { }
	samp(int num) //생성자 메서드를 오버로딩
	{
		num = num;
	}
	void show()
	{
		cout << "num = " << num << endl;
	}
};

int main()
{
	samp * pob = new samp(7);
	pob->show();
	return 0;
}
#include<iostream>
using namespace std;

class Animal {    };
class Monkey : public Animal
{    };
class Tiger : public Animal
{    };
class Lion : public Animal
{    };

class Zookeeper
{
public:
	void wash(Animal*  ob)
	{
		cout << ob << " 를 씻긴다"
			<< endl;
	}
	
	/*void wash(Monkey  *mk)
	{
		cout << mk << " 를 씻긴다"
			<< endl;
	}
	void wash(Tiger *tg)
	{
		cout << tg << " 를 씻긴다"
			<< endl;
	}
	void wash(Lion *li)
	{
		cout << li << " 를 씻긴다"
			<< endl;
	}  */	 
};

int main()
{
	Zookeeper *zob = new Zookeeper();
	Monkey *obmk = new Monkey();
	Lion *obli = new Lion();
	Tiger *obtg = new Tiger();

	zob->wash(obmk);
	zob->wash(obtg);
	zob->wash(obli);
}