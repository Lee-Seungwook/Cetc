// ArrayEx0318.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	const double pi = 3.14; //pi값은 수정 불가능
	
	const char *p = "apple"; //const를 꼭 쓰자

	cout << "p=" << p << endl;
	printf("p=%p\n", p);
	printf("p=%s\n", p);

	//*p = 'A'; //error
	
	int n[3] = { 10, 20, 30 };
	int v[3] = { 40, 50, 60 };
	
	char name[5] = "book";
	
	cout << "name = " << name << endl;

	name[0] = 'B';
	
	cout << "수정 후 name = " << name << endl;

	printf("name이 저장한 값 = %p\n", name);

	char copy[5] = "desk";

	strcpy_s(name , strlen(copy) +1 , copy); // /* <- copy에서 name으로 복사 */strlen(), strcat()

	cout << "복사후name=" << name << endl;
	//name = copy;

	//name[0] = copy[0]

	//char *p = "book";
	
	// n = v; //error..
	//배열명은 포인터(주소)상수이기때문에
	n[3] = v[3];

	/*
	cout << "n[0]=" << n[0] << endl;
	cout << "n[1]=" << n[1] << endl;
	cout << "n[2]=" << n[2] << endl;
	*/

	for (int i = 0; i <= 2; ++i)
	{
		cout << "n["<<i<<"]=" << n[i] << endl;
	}

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
