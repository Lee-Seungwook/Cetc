//person.h

#pragma once

#include <iostream>
#include <string>
using namespace std;

const int NAMELEN = 20 ;
const int PHONELEN = 20 ;

class Person
{
	char name[NAMELEN] ;	
	char phone[PHONELEN] ; 
	
public:
	Person()  {   } ;
	/*
	~Person() 
	{
		if(flag == 1 )
			cout<<"³­ Person ¼Ò¸êÀÚ "<<endl ; 
		delete[] name ;
	}*/
	Person(char* n , char* p) 
	{			
		strcpy_s(name , strlen(n)+1, n) ; 
		strcpy_s(phone, strlen(p) + 1 , p) ;
	}
	char* getPhoneNumber() 
	{
		return (char*)phone ;		
		//return phone ;		
	}
	//const char* getName() const
	char* getName() 
	{
		return (char*)name ;		
		//return  name ;		
	}
};
  