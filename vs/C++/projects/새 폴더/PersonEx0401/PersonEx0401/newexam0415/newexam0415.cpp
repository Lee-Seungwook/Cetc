#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int *p = 0;
	int a = 7;
	//p = (int*)malloc(sizeof(int));   //new 쓰면 malloc보다 더 편함
	
	/*p = new int;      //공간할당
	*p = 9;   */        //값넣어줌(초기화)                 //메모장참고
	p = new int(9);     //이렇게 한번에

	char* pch = new char('B');
	//*pch = 'B';
	cout << "pch = " << *pch << endl;
	cout << "*p = " << *p << endl;

	//동적메모리에 문자열 할당
	/*const*/ 
	char* name = new char[20];   //const char -> 문자열 상수 (사용자가 수정 못함) 
	strcpy_s(name, strlen("Gildong") + 1, "Gildong");  //strcpy쓰면 const 빼줘야함
	//name = "Gildong";
	cout << "name = " << name << endl;

	delete[] name; //name이 가리키는 배열공간 전부 지워짐 ([] 써야 배열공간 모두 사라짐)
	delete p;
	delete pch;                                    //delete 후에도 프로그램 실행하는 데에는 문제 없어야함
	
	return 0;
}

