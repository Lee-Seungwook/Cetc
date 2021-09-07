#include "pch.h"
#include <iostream>
using namespace std;

class car
{
public:
	int  speed;   int number;
	char *name;   char *color;
	char *address;

	car()
	{}

	car(const char  pname[20], const char  pcolor[20], int pnumber, const char  paddress[50], int pspeed)
	{
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);

		color = new char[strlen(pcolor) + 1];
		strcpy_s(color, strlen(pcolor) + 1, pcolor);
		speed = pspeed;
		number = pnumber;

		address = new char[strlen(paddress) + 1];
		strcpy_s(address, strlen(paddress) + 1, paddress);
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

	char* getname()
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
	char*  comp;  //렌터카 업체(회사)명과 관련된 변수
public:
	rentcar(const char  pname[20], const char  pcolor[20], int pnumber, const char  paddress[50], int pspeed, int pfare, char pcomp[20], int pplspeed, int pmispeed) :car(pname, pcolor, pnumber, paddress, pspeed)
	{
		fare = pfare;
		comp = pcomp;

		speed = speedup(pplspeed);
		speed = speeddown(pmispeed);


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
		return  (char*)comp;
	}

	void setompany(const char  pcompany[20])
	{
		strcpy_s(comp, strlen(pcompany) + 1, pcompany);
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
	char comp[20] = { '\0', };
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
	cin >> comp;

	rentcar* rent = new rentcar(name, color, number, address, speed, fare, comp, plspeed, mispeed);
	cout << "\n차 이름: " << rent->getname() << endl;
	cout << "차 색: " << rent->getcolor() << endl;
	cout << "차량번호: " << rent->number << endl;
	cout << "운전자 주소: " << rent->getaddress() << endl;
	cout << "속도: " << rent->speed << endl;
	cout << "\n렌트요금: " << rent->getfare() << endl;
	cout << "렌트회사명: " << rent->getcompany() << endl;

	cout << "속도를 얼마나 증가시킵니까?: ";
	cin >> plspeed;
	cout << "현재 속도: " << rent->speedup(plspeed) << endl;
	cout << "속도를 얼마나 감소시킵니까?: ";
	cin >> mispeed;
	cout << "현재 속도: " << rent->speeddown(mispeed) << endl;
	return 0;
}