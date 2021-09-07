//telphonebook.h

#pragma once

#include <iostream>
#include "person.h"
using namespace std;

const int MAXPERSON = 1000 ;

class TelPhoneBook
{
	int pidx ;
	Person phoneList[MAXPERSON] ;
public:
	TelPhoneBook() : pidx(0) 
	{   }
	~TelPhoneBook() {   }
	void insert() ;
	void remove() ;
	void search() ;
	void update();
	void printAll() ;   
};

       