#include "pch.h"
#include <iostream>
using namespace std;

class car
{private:
public:
	int  speed;   int number;
	char *name;   char *color;
	char *address;

	car()
	{
	}

	car(const char  pna[20], const char  pcol[20], int pnum, const char  padd[50], int ps)
	{
		name = new char[strlen(pna) + 1];
		strcpy_s(name, strlen(pna) + 1, pna);

		color = new char[strlen(pcol) + 1];
		strcpy_s(color, strlen(pcol) + 1, pcol);
		speed = ps;
		number = pnum;

		address = new char[strlen(padd) + 1];
		strcpy_s(address, strlen(padd) + 1, padd);
	}
	int speedup(int plspeed)
	{
		speed = speed + plspeed;
		return speed;
	}
	int speeddown(int mispeed)
	{
		speed = speed - mispeed;
		return speed;
	}
	char*  getname()
	{
		return  (char*)name;
	}
	char* getcolor()
	{
		return  (char*)color;
	}
	char*  getaddress()
	{
		return  (char*)address;
	}
	
};


class  rentcar : public car
{
	int   fare;   //렌트 요금 관련된 변수
	char*  company;  //렌터카 업체(회사)명과 관련된 변수
public:
	rentcar(const char  pna[20], const char  pcol[20], int pnum, const char  padd[50], int ps, int pfare, char pcom[20], int ppls, int pmis) :car(pna, pcol, pnum, padd, ps)
	{
		fare = pfare;
		company = pcom;

		speed = speedup(ppls);
		speed = speeddown(pmis);


	}

	int getfare()
	{
		return  fare;
	}
	void setfare(int pfare)
	{
		fare = pfare;
	}
	char* getcompany()
	{
		return  (char*)company;
	}

	void setcompany(const char  pcom[20])
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

	rentcar* mycar = new rentcar(name, color, number, address, speed, fare, company, plspeed, mispeed);
	cout << "\n차 이름: " << mycar->getname() << endl;
	cout << "차 색: " << mycar->getcolor() << endl;
	cout << "차량번호: " << mycar->number << endl;
	cout << "운전자 주소: " << mycar->getaddress() << endl;
	cout << "속도: " << mycar->speed << endl;
	cout << "\n렌트요금: " << mycar->getfare() << endl;
	cout << "렌트회사명: " << mycar->getcompany() << endl;

	cout << "속도를 얼마나 증가시킵니까?: ";
	cin >> plspeed;
	cout << "현재 속도: " << mycar->speedup(plspeed) << endl;
	cout << "속도를 얼마나 감소시킵니까?: ";
	cin >> mispeed;
	cout << "현재 속도: " << mycar->speeddown(mispeed) << endl;
	return 0;
}