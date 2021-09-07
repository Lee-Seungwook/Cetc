#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 7, b = 6;
	int &ra = a;   //참조형변수는 선언과 동시에 초기화해야함 //여기있는 &는 참조연산자
	cout << "a = " << a << endl;
	cout << "a의 시작주소 = " << &a << endl;
	cout << "ra = " << ra << endl;
	cout << "ra가 참조하는 주소 = " << &ra << endl;    //여기있는 &는 주소연산자

	int &rb = b;
	cout << "b = " << b << endl;
	cout << "rb = " << rb << endl;
	cout << "b의 시작주소 = " << &b << endl;

	ra = b;                                            // a 값이 6으로 바뀜
	cout << "ra = b 수행 후 a = " << a << endl;
	cout << "ra = b 수행 후 b = " << b << endl;
	cout << "ra = b 수행 후 ra = " << ra << endl;
	cout << "ra = b 수행 후 ra가 참조하는 주소 = " << &ra << endl;     //a의 시작주소와 같음


	return 0;
}
