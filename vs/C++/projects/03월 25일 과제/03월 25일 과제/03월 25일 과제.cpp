﻿// 03월 25일 과제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int english = 0;
	int science = 0;
	int math = 0;
	char name[20] = { '\0', };
	char department[20] = { '\0' , };
	char address[100] = { '\0' , };
	

	cout << "이름을 입력하세요: ";
	cin >> name;
	cin.ignore(1, '\n');
	cout << "학과명을 입력하세요: ";
	cin >> department;
	cin.ignore(1, '\n');
	cout << "영어, 물리학, 미적분학 점수를 입력하세요:";
	cin >> english; cin >> science; cin >> math;
	cin.get();
	cout << "주소를 입력하세요: ";
	cin.getline(address, 100, '\n');

	int all = english + science + math;
	int par = all / 3;

	cout << "이름= " << name << endl;
	cout << "학과= " << department << endl;
	cout << "영어= " << english << ", 물리학= " << science << ", 미적분학= " << math << ", 총합= " << all << ", 평균= " << par << endl;
	cout << "주소= " << address << endl;
	
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
