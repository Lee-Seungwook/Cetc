#include "pch.h"
#include <iostream>
using namespace std;

void func()                                          //C에서는 안되지만 C++에서는 가능함 (함수(메서드)의 중복)                              //0415추가
{cout << "fuc() 전역함수" << endl;}                  //클래스 멤버 아니기 때문에 멤버는 아니고 전역함수
                                                     //파라미터 로 구분
void func(int a)                                     
{cout << "정수형 인자 한개인fuc(int)" << endl;}

void func(int a, char ch)
{cout << "인자 두개인fuc(int, char)" << endl;}

class Person
{
private:  //아무것도 없으면 private이 적용
//public: //접근권한지정자(Access Specifier)      //객체지향ppt 21페이지 참조
	char name[30] = { '\0' , }; //초기화 해도되고 안해도 됨                          -->>정적메모리(7바이트만 쓰면 23바이트가 남는다) ->> 해결윟 동적메모리 할당
	int age = 0;                                                 //필수구성요소

public:
	Person() //Default Constructor    //(파라미터 없으면)안써도 알아서 되지만 명시해줌
	{
		age = 0;
		strcpy_s(name, strlen("\0") + 1, "\0");  //생성자에서 초기값 지정하면 위에서 초기값 안해도 됨
		cout << "난 Person 기본생성자" << endl;
	}

	Person(int page, const char pname[30])          //기본생성자 명시안하고 파라미터 있는 생성자만 명시하여 사용하면 기본생성자에서 찾지않고 명시된 생성자에서만 찾는다
	{												//파라미터 있는 생성자 쓸 때는 기본생성자 써놓는게 좋다.
	
		cout << "난 인자 둘인 Person 생성자" << endl; //생성자 실행여부 확인
		age = page;
		strcpy_s(name, strlen(pname) + 1, pname);  
	}


	~Person()  //Destructor Method (소멸자)                                                                                   //0415추가
	{
		cout << "~Person() 호출됨" << endl;
	}

	void setName(const char pname[30])  //const붙이는 이유: pname 이 전달받은 원본문자를 바꾸지 말라는 뜻으로 붙임
	{
		strcpy_s(name, strlen(pname) + 1, pname);
	}
	
	
	char* getName() //name은 배열명 (포인터상수) 따라서 캐릭터 포인터인 char* 을 반환타입으로 사용하면 name의 주소값 반환
	{
		return (char*)name;
	}

	int getAge()
	{
		return age;
	}

	void setAge(int page)
	{
		age = page;
		//cout << "age = " << age << endl;
	}

	void talk()  //Person 클래스의 멤버함수(= method)            //고유행위
	{
		cout << "Person이 말한다." << endl;
		//age=45;// 가능은 하지만 setAge있어서 불필요
	}
	void see()  //see method
	{
		talk();  //public: 없어도 가능
		cout << "Person이 본다." << endl;
	}
};     //end of class Person  //Person 클래스로 캡슐화 시켰다. (멤버들을 외부로부터 보호) //정보은닉

int main()
{
	func(); func(7); func(5,'A');                                                                                                 //0415추가
	
	Person hodong;  //main()의 stack에 Person class의 복사본 생성, 생성된 객체 이름을 hodong이라고 하겠다. hodong은 객체 참조변수(or instance 변수), class가 하나의 타입이 됨   //(참조형  타입)
	//Person hodong = Person(); //Person함수가 실행되어 객체가 생성된다. (Person hodong; 이렇게 써도 Person hodong = Person();이렇게 실행됨. 
							  //Person();-> 기본생성자(Default Constructor)  초기값 지정하고, 객체 생성함 
	
	Person wonbin = Person(41, "원빈"); //-> 명시적 호출
	//Person wonbin(41, "원빈");        //-> 묵시적 호출    똑같음
	
	//hodong.name="강호동" //error//배열명은 포인터상수! (변경불가), "" 에 묶여있으면 문자열 상수데이터로 취급(변수취급x)
	hodong.setName("강호동");
	//strcpy_s(hodong.name, strlen("강호동")+1, "강호동");//스트링 카피이용해 name배열에 넣는다, (문자 넣을 공간, 길이(스트링렌스 이용 널문자 포함해야함으로 +1, 넣을 문자열)
														//name이 private되면 name 바로 못씀 따라서 간접접근할수 있는 멤버함수 이용해야함	
	cout << "hodong.name = "<< hodong.getName() <<endl; 
														//hodong.age = 45; //age는 private이면  error  
	hodong.setAge(45);//int page 사용하면 main에서 값 입력가능 -> setAge통해 age에 저장
	cout << "hodong.age = " << hodong.getAge() << endl;  //age는 private 따라서 getAge함수를 만들어 메인함수에서 쓴다.
	hodong.talk(); //public: 없으면 캡슐화 때문에 외부접근 불가

	cout << "wonbin.name = " << wonbin.getName()
		<< ", wonbin.age = " << wonbin.getAge() << endl;
	 
	Person *pjaesuk = new Person(45,"유재석");  //Person 클래스의 복사본(=객체) 생성   //*pjaesuk -> 객체 포인터 변수                                 //0415추가

	cout << "pjaesuk -> name = " << (*pjaesuk).getName()
		<< ", pjaesuck -> age = " << pjaesuk->getAge()<< endl;            //둘다 똑같음 하는일 (* 도 포인터(참조연산자), -> 도 포인터(참조실행연산자)  비슷함 그냥

	Person ob[4];
	ob[3].setName("류현진");
	cout << "ob[3].name=" << ob[3].getName() << endl;


	delete pjaesuk;
	return 0;
	//멤버 변수 위주로 프로그래밍 
	//멤버변수 직접접근이 안되서 멤버함수 통해 간접적으로 접근
	//멤버 변수 public이면 함수 필요 x 
	//하지만 캠슐화의 원리(정보은닉) 지켜주기 위해 함수사용
	//변수를 위해 함수를 사용 따라서 변수위주의 프로그래밍
}

