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
		cout << ob << " ¸¦ ¾Ä±ä´Ù"
			<< endl;
	} 
	/*
	void wash(Monkey  *mk)
	{
		cout << mk << " ¸¦ ¾Ä±ä´Ù"
			<< endl;
	}
	void wash(Tiger *tg)
	{
		cout << tg << " ¸¦ ¾Ä±ä´Ù"
			<< endl;
	}
	void wash(Lion *li)
	{
		cout << li << " ¸¦ ¾Ä±ä´Ù"
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