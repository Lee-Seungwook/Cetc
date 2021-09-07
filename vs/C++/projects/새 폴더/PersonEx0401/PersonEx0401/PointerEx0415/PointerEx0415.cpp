#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 7, b = 8;
	int *pa = 0;     //int형 포인터 (int*  pa)
	pa = &a;         //pa가 a의 주소 따라서 *pa가 a를 가리킴
	int *pb = &b;
	//pb = &b;
	char str[4] = "box"; //배열명은 포인터 상수
	char* pt = str;      //문자형 포인터 변수 pt선언
	for (int i = 0;i <= 3;++i)
		cout << "pt[" << i << "] = " << pt[i] << endl;
	
	cout << "pt = " << pt << endl;                               //pt는 주소값이라 주소값 출력될 줄 알았지만 "box"출력됨
	                
																 //iostream에 있는 cout.operator<<("pt")가 실행되기 때문 (cout << "pt = " 이부분에 의해)
	                                                             //char 형이 넘어왔을때는 넘어온 주소의 문자열이 출력되도록 만들어짐 (int형은 그냥 주소 출력)



	cout << "a의 시작주소 = " << &a << endl; //a의 주소값 출력
	cout << "pa가 저장한 주소 = " << pa << endl; 
	cout << "a = " << a << endl;
	cout << "*pa = " << *pa << endl; //pa가 가리키는 공간(a)의 값을 출력
	cout << "b = " << b << endl;

	*pa = *pb;  //pa가 가리키는 공간(a)의 값은 pb가 가리키는 공간(b)의 값(8)이다 (assign)
	cout << "*pa=*pb 실행후 a = " << a << endl;
	

	return 0;
}