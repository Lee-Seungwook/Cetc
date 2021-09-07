//telphonebook.h

#ifndef _TELPHONEBOOK_H_
#define _TELPHONEBOOK_H_

#include <iostream>
#include "array.h"
using namespace std;

const int MAXPERSON = 1000 ;

class TelPhoneBook
{	
	CArray phoneList ;     
public:
	TelPhoneBook() 
	{   }
	~TelPhoneBook() {   }
	void insert() ;
	void remove() ;
	void search() ;
	void printAll() ; 
	void update() ;
};

#endif          