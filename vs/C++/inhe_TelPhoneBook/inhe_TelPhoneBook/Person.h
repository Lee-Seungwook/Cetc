//Person.h
//
#ifndef _PERSON_H_
#define _PERSON_H_
typedef Person* ArrayElm

#include<iostream>
#include<string>
using namespace std;

const int NAMELEN = 20 ;
const int PHONELEN = 20 ;
const int ADDRLEN = 100 ;
const int POSLEN = 20 ;

class Person
{
protected:
	char *name  ; //절대 변경 불가...임의로 name 변수를 배열로 변경하지 마시오.
	char *phone ; //절대 변경 불가...임의로 phone 변수를 배열로 변경하지 마시오.
public:
	Person() { cout<<" 난 Person 의 생성자 "<< endl ; }
	Person(char* n , char* p)
	{
		strcpy_s(name, strlen(n) + 1, n);
		strcpy_s(phone, strlen(p) + 1, p);


	}
	virtual ~Person() {  } //절대 변경 불가..virtual 키워드 삭제하시 마시오.

	char* getPhoneNumber() const
	{
		return (char*)phone;
		//return phone ;
	}
	char* getName() const
	{
		return (char*)name;
		//return  name ;

	}
	virtual void print() = 0 ; //절대 변경 불가...virtual 키워드 삭제하시 마시오.    	 
};

class Friend: public Person
{
private:
	char *addr;
public:
	
	
	Friend()
	{}

	Friend(const char paddr[50])
	{
		addr = new char[strlen(paddr) + 1];
		strcpy_s(addr, strlen(paddr) + 1, paddr);
	}

	char*  getaddr()
	{
		return  (char*)addr;
	}

	virtual void print() = 0; //절대 변경 불가...virtual 키워드 삭제하시 마시오.

	virtual ~Person(){}


};

class Companion: public Person 
{
private:
	char* position;
public:
	

	Companion(){}

	companion(const char pposition[50])
	{
		position = new char[strlen(pposition) + 1];
		strcpy_s(position, strlen(pposition) + 1, pposition);
	}

	char *getposition()
	{
		return (char*)position;
	}

	virtual void print() = 0; //절대 변경 불가...virtual 키워드 삭제하시 마시오.
	
	virtual ~Person(){}

};

#endif