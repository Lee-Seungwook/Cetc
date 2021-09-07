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
	Samp(int num ) //생성자 메서드를 오버로딩
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