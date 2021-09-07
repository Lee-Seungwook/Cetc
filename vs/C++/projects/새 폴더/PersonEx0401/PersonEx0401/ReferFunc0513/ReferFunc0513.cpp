#include "pch.h"
#include <iostream>
using namespace std;

int global = 2;

int& func()               //global 변수의 번지수가 전달됨
{
	return global;
}

void callByPointer(int *pa)
{
	cout << "*pa = " << *pa << endl;    //값
}

void callByRefer(int &ra)
{
	cout << "&ra = " << &ra << endl;  //주소값
	cout << "ra = " << ra << endl;    //값
}

int main()
{
	int a = 5, res = 0;
	callByPointer(&a);   //a의 주소값 전달  
	callByRefer(a);                           //ra(참조형변수)는 포인터와 달리 실제 데이터 값이 할당되지 않는다. 

	res = func();
	cout << "res = " << res << endl;
	cout << "global = " << global << endl;

	func() = 8;  //func 함수에 &(참조자) 없으면 2=8 인 꼴이 돼서 오류 //&썼기 때문에 global의 번지를 참조해서 거기에 8이라는 값을 넣음
	cout << "(func() = 8 수행 후)global = " << global << endl;

	return 0;
}