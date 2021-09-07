#include "pch.h"
#include <iostream>
using namespace std;

class Car
{
public:
	int  speed;   int number;
	char *name;   char *color;
	char *address;

	Car()
	{
	}
	
	const Car(int ps, int pnum, const char* pna, const char* pcol, const char* padd)
	{
		name = new char[strlen(pna) + 1];
		strcpy_s(name, strlen(pna) + 1, pna);

		color = new char[strlen(pcol) + 1];
		strcpy_s(color, strlen(pcol) + 1, pcol);

		number = pnum;

		address = new char[strlen(padd) + 1];
		strcpy_s(address, strlen(padd) + 1, padd);

		speed = ps;
	}

	char*  getName()
	{
		return  (char*)name;
	}
	char* getColor()
	{
		return  (char*)color;
	}
	char*  getAddress()
	{
		return  (char*)address;
	}
	int speedUp(int plspeed)
	{
		speed = speed + plspeed;
		return speed;
	}
	int speedDown(int mispeed)
	{
		speed = speed - mispeed;
		return speed;
	}
};


class  RentCar : public Car
{
	int   fare;   //렌트 요금 관련된 변수
	char*  company;  //렌터카 업체(회사)명과 관련된 변수
public:
	RentCar(const char  pna[20], const char  pcol[20], int pnum, const char  padd[50], int ps, int pfare, char pcom[20], int pplspeed, int pmispeed):Car(ps, pnum, pna, pcol, padd)
	{
		
		fare = pfare;
		company = pcom;

		speed = speedUp(pplspeed);
		speed = speedDown(pmispeed);


	}

	int getFare()
	{
		return  fare;
	}
	void setFare(int pfare)
	{
		fare = pfare;
	}
	char* getCompany()
	{
		return  (char*)company;
	}

	void setCompany(const char  pcom[20])
	{
		strcpy_s(company, strlen(pcom) + 1, pcom);
	}
};


int main()
{
	int speed = 0;
	int number = 0;
	int fare = 0;
	char name[20] = { '\0', };
	char color[20] = { '\0' , };
	char address[50] = { '\0' , };
	char company[20] = { '\0', };
	int plspeed = 0;
	int mispeed = 0;

	cout << "차 이름을 입력하세요: ";
	cin >> name;
	cin.get();
	cout << "차 색을 입력하세요:  ";
	cin >> color;
	cin.get();
	cout << "차량번호를 입력하세요: ";
	cin >> number;
	cin.ignore(1, '\n');
	cout << "운전자 주소를 입력하세요: ";
	cin.getline(address, 51, '\n');
	cout << "속도를 입력하세요: ";
	cin >> speed;
	cin.get();
	cout << "렌트비를 입력하세요: ";
	cin >> fare;
	cin.get();
	cout << "렌트회사를 입력하세요: ";
	cin >> company;

	RentCar* cha = new RentCar(name, color, number, address, speed, fare, company, plspeed, mispeed);
	cout << "\n차 이름: " << cha->getName() << endl;
	cout << "차 색: " << cha->getColor() << endl;
	cout << "차량번호: " << cha->number << endl;
	cout << "운전자 주소: " << cha->getAddress() << endl;
	cout << "속도: " << cha->speed << endl;
	cout << "\n렌트요금: " << cha->getFare() << endl;
	cout << "렌트회사명: " << cha->getCompany() << endl;

	cout << "속도를 얼마나 증가시킵니까?: ";
	cin >> plspeed;
	cout << "속도: " << cha->speedUp(plspeed) << endl;
	cout << "속도를 얼마나 감소시킵니까?: ";
	cin >> mispeed;
	cout << "속도: " << cha->speedDown(mispeed) << endl;
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
