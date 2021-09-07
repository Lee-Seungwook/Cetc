#include "pch.h"
#include "Mammal.h"
#include "Person.h"
#include "Man.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 7;
	Person *jisung = new Person();
	Person *chulsu = new Person(25, "김철수");
	Man *hyunjin = new Man();
	//Mammal *hyunjin = new Man();
	hyunjin->work();
	hyunjin->talk();

	Man *heungmin = new Man(32, "손흥민", 500, "soccer");
	heungmin->show();
	//heungmin->disp();

	delete jisung;
	delete chulsu;
	delete hyunjin;
	delete heungmin;


	return 0;
}