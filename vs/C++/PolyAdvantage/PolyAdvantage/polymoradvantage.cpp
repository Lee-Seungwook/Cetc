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
		cout << ob << " �� �ı��"
			<< endl;
	} 
	/*
	void wash(Monkey  *mk)
	{
		cout << mk << " �� �ı��"
			<< endl;
	}
	void wash(Tiger *tg)
	{
		cout << tg << " �� �ı��"
			<< endl;
	}
	void wash(Lion *li)
	{
		cout << li << " �� �ı��"
			<< endl;
	}  	*/
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