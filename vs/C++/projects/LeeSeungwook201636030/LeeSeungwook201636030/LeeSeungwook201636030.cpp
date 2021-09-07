// LeeSeungwook201636030.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <conio.h>
#include "pch.h"

using namespace std;
char menu()
{
	cout << "1.Insert" << endl;
	cout << "2.Delete" << endl;
	cout << "3.Search" << endl;
	cout << "4.Print All" << endl;
	cout << "5.Update" << endl;
	cout << "6.Exit" << endl;
	return getch();
}

class TelephoneBook
{
private:
		char* name;
		char* num;
public:
	void input(char* bufname = 0, char*bufnum = 0)
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
	TelephoneBook index[100];
	int count;
public:
	numbook()
	{
		count = 0;
	}

	void writephnum()
	{
		char _bufname[100];
		char _bufnum[100];
		cout << "Input Name :";
		cin.getline(_bufname, 20, '\n');
		cout << "Input Number : ";
		cin.getline(_bufname, 20, '\n');
		index[count++].input(_bufname, _bufnum);

		void printphnum()
		{
			int i;
			for (i = 0; i < count; ++i)
				cout << index[i].getname() << ":" << index[i].getnum() << endl;

			int main()
			{
				numbook main;
				bool run = true;
				while (run)
				{
					switch(menu())
					{
					case'1':
						main.writephnum();
						break;
					case'4':
						main.printphnum();
						break;
						
					}
				}
			}
		}
	}
};