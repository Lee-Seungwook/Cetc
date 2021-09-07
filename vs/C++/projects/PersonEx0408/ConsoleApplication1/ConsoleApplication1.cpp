// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;
char menu()
{
	cout << "1.전화번호 등록" << endl;
	cout << "2.전화번호 출력" << endl;
	cout << "3.전화번호 검색" << endl;
	cout << "4.전화번호 삭제" << endl;
	cout << "0.프로그램 종료" << endl;
	return _getch();
}

class phnum
{
private:
	char* name;
	char*num;
public:
	void input(char* bufname = 0, char* bufnum = 0)
	{
		name = bufname;
		num = bufnum;
	}

	char* getname()
	{
		return name;
	}

	char* getnum()
	{
		return num;
	}
};

class numbook
{
private:
	phnum index[100];
	int count;
public:
	numbook()
	{
		count = 0;
	}
	void writephnum()
	{
		if (count == 0)
		{
			cout << "이름을" << endl;
			cout << "홍길동dd" << endl;
		}
		char _bufname[100];
		char _bufnum[100];
		cout << "이름 / 번호 입력:";
		char* bufname = new char[strlen(_bufname) + 1];
		char* bufnum = new char[strlen(_bufnum) + 1];
		cin >> bufname >> bufnum;
		index[count++].input(bufname, bufnum);
	}
	void printphnum()
	{
		int i;
		for (i = 0; i < count; ++i)
			cout << index[i].getnum() << endl;
	}

	void search()
	{
		cout << "1.번호검색" << endl << "2.이름검색" << endl;
		switch (_getch())
		{
		case '1':
			char searchnum[100];
			cout << "검색할 번호를 입력하세요: ";
			cin >> searchnum;
			for (int i = 0; i < count; ++i)
				if (strcmp(index[i].getnum(), searchnum) == 0)
					cout << index[i].getname() << ":" << index[i].getnum << endl;
			break;

		case '2':
			char searchname[100];
			cout << "검색할 이름을 입력하세요 :";
			cin >> searchname;
			for (int i = 0; i < count; ++i)
				if (strcmp(index[i].getname(), searchname) == 0)
					cout << index[i].phnum::getname << " : " << index[i].getnum() << endl;
			break;
		}
	}

	void Delete()
	{
		int i;
		char search[100];
		cout << "삭제할 이름을 입력하세요 :";
		cin >> search;
		for (i = 0; i < count; ++i)
			if (strcmp(index[i].getname(), search) == 0)
			{
				delete[] index[i].phnum::getname();
				delete[] index[i].phnum::getnum;
				index[i].input(index[i + 1].getname(), index[i + 1].getnum());
				count--;
			}
	}

	void deletehip()
	{
		for (int i = 0; i < count; i++)
		{
			delete[] index[i].getname();
			delete[] index[i].getnum;
		}
	}
};

void main()
{
	numbook main;
	bool run = true;
	while (run)
	{
		switch (menu())
		{
		case '1':
			main.writephnum();
			break;
		case '2':
			main.printphnum();
			break;
		case '3':
			main.search();
			break;
		case '4':
			main.Delete();
			break;
		case '0':
			run = false;
			break;

		}
	}
	main.deletehip();
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
