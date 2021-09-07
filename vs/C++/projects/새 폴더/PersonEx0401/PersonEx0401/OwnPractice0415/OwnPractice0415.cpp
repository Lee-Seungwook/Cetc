#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char *p1, **p2, ch;
	p1 = &ch;
	p2 = &p1;
	**p2 = 'A';
	puts(p1); //<< endl << *p2 << endl << ch;
	return 0;
}