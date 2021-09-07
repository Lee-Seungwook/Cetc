//array.h
//

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include<iostream>
#include "person.h"
using namespace std;

typedef Person* ArrayElm ;

class CArray
{
	ArrayElm* arr ;  
	int size ;
	int aidx ;
public:
	CArray(int sz = 10 ) ;
	~CArray() ;
	void Insert(ArrayElm data , int idx) ;
	void Insert(ArrayElm data) ;
	void Remove(int idx) ;
	void Update(ArrayElm data , int idx) ;

	ArrayElm GetItem(int idx) ;     
	int GetSize() { return aidx ; }     

	bool IsEmpty() 
	{
		return aidx <= 0 ? true : false ;       
	}
};

#endif       