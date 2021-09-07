// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

	class car
	{
	
	private:
		int speed = 0;
		int number = 0;
		
		char name[30] = {'\0'};
		char color[30] = {'\0'};
		char address[50] = {'\0'};

		

	public:

		void carspeed(int speed) 
		{               
			cout << "차량 속도: " << speed << endl;
		}
		void carnumber(int number) //<=전달 받을값을 저장할 공간, const=>전달받은 값을 setName안에서 임의로 변경하지마라(상수화)
		{
			cout << "차량 번호: " << number << endl;
		}

		char* getname() 
		{               
			return (char*)name;
		}
		void carname(const char cname[30]) 
		{
			strcpy_s(name, strlen(cname) + 1, cname);
		}

		char* getcolor() 
		{               
			return (char*)color;
		}

		void carcolor(const char ccolor[30]) 
		{
			strcpy_s(color, strlen(ccolor) + 1, ccolor);
		}

		char* getaddress() 
		{               
			return (char*)address;
		}
		void caraddress(const char caddress[100]) 
		{
			strcpy_s(address, strlen(caddress) + 1, caddress);
		}
	};

	int main()
	{
		car my;
		my.carspeed(100);
		my.carnumber(1234);
		
		my.carname("소나타");
		my.carcolor("검정색");
		my.caraddress("인천시 남구 용현동");

		
		
		cout << "차량 이름: " << my.getname() << endl;
		cout << "차량 색상: " << my.getcolor() << endl;
		cout << "운전자의 주소: " << my.getaddress() << endl;
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
