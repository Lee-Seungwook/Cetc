// 0325.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int hakbun = 0;
	char name[20] = { '\0', };
	int num = 0;
	char blood = '\0';
	char addr[80] = { '\0' , };

	cout << "혈액형 입력= ";
	blood = cin.get();
	//cin >> blood;
	cout << "blood= " << blood << endl;
	cout << "학번 입력: ";
	cin >> hakbun;
	cout << "hakbun= " << hakbun << endl;
	
	
	cin.ignore(1, '\n');
	//getchar(); //널 문자 때문에 삽입 
	cout << "이름입력: ";
	//cin.getline(name , 20, '\n'); //띄워 쓰기 가능
	gets_s(name , sizeof(name) );
	
	//cin >> name;
	cout << "name=" << name << endl;
	return 0;
}

//cin객체는 문자뒤에 공백문자(스페이스 바, 엔터, 탭등)를 위치시키면 공백 문자가 나올때 문자열이 끝난것을 간주한다.

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
