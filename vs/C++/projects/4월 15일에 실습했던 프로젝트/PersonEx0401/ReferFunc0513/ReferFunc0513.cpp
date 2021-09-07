// ReferFunc0513.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int global = 2;

/*int func() //주소를 return하고 그 주소가 가리키는 값을 참조하라
{
	return global;
}*/


int& func() //그 주소의 주소를 알려줄테니 주소의 변수를 참조해달라
{
	return global;
}

void callnypointer(int *pa) //주소값을 받으면
{
	cout << "*pa=" << *pa << endl;
}

/*void callbyrefence(int &ra) //&ra는 실제로 메모리 할당X, main함수에 있는 a값을 참조한다.
{
	cout << "&ra=" << &ra << endl;
}*/

void callbyrefence(int &ra) //&ra는 실제로 메모리 할당X, main함수에 있는 a값을 참조한다.
{
	cout << "ra=" << ra << endl;
}



int main()
{
	int a = 5;
	int result = 0;
	callnypointer(&a); // a의 주소값을 전달
	callbyrefence(a); //주소 연산자를 쓰면 컴파일 오류
	result = func();
	cout << "res =" << result << endl;
	cout << "global =" << global << endl;
	func() = 8;
	cout << "func()=8; 수행후 global=" << global << endl;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
