// newexam0415.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	int *p = 0;
	//p = (int*)malloc(sizeof(int)); // 동적메모리 할당 (동적 메모리 할당하는 방법에는 malloc, calloc, realloc 3개가 있다.), <- 메모리 절약과 실행속도 개선을 위해사용, static이 붙으면 정적메모리 할당
	int a = 7;
	p = new int(9); //new 연산자 (메모리 동적 할당) new연산자 선언과 함께 p에 9라는 값을 할당한다.
	//*p = 9;
	
	char* pch = new char('B'); //new연산자 선언과 함께 'B'라는 값을 할당
	//*pch = 'B';

	cout << "*pch=" << *pch << endl;
	cout << "*p=" << *p << endl;

	/*cosnt*/ char* name = new char[20]; //const char* //문자열 상수 값 수정을 하지 못한다.
	strcpy_s(name, strlen("gildong") + 1, "gildong");
	//name = "gildong";
	cout << "name=" << name << endl;

	

	delete p; //new 연산자를 사용하면 delete연산자로 삭제 해줘야 한다.
	delete pch;
	delete[] name; //그냥 name만 delete하면 name[0]만 삭제 되기 때문에 이처럼 delete해야한다.
	

	return 0;

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
