// thisex0610.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

//class Samp; //Forward Reference (전방참조) //구버전에서는 됐지만 지금은 안됨

class Samp
{

private:
	static int val; //Samp클래스 밖으로 나가서 초기화 해야함
	int num = 0;
public:
	Samp() { }
	Samp(int num) //생성자 메서드를 오버로딩
	{
		this->num = num;
		//pob->num = num;  //error //메인함수 지나면 쓸 수 없음
	}
	void show()
	{
		cout << "num = " << this->num << endl;
	}
	static void disp()  //특정(pob)객체에 소속x, static메서드에는 this 없음
	{
		cout << "disp() 안 val = " << val << endl;
	}

	friend void access(Samp *ob); //access라는 전역함수는 Samp클래스의 friend라고 선언
}; //end of class Samp

int Samp::val = 1;

void access(Samp *ob)
{
	cout << "ob->num = " << ob->num << endl;
}

int main()
{
	//*pob 는 객체 포인터 변수
	Samp * pob = new Samp(7);
	pob->show();
	Samp::disp();
	pob->disp();
	access(pob);

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
