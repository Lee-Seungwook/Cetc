//main.cpp

#include <iostream>
#include<stdlib.h>
#include "telphonebook.h"
using namespace std;

typedef Person* ArrayElm

void print_menu()
{
	cout << endl << endl ;  
	cout << "---Menu ---" << endl  ;  
	cout << " 1. Insert" << endl ;
	cout << " 2. Delete " << endl ;
	cout << " 3. Search " << endl ;  
	cout << " 4. Update " << endl ;
	cout << " 5. Print All" << endl ;
	cout << " 6. Exit " << endl ; 
}

int main()
{
	TelPhoneBook tpbook ;
	//int choice ;
	char  choice[255] ;
	int arrIndex = 0 ;     

	while(1)
	{
		print_menu() ;
		cout << endl <<"Choose the item : " ;
		//cin >> choice ; 
		//cin.get() ;
		cin.getline( choice , 255, '\n') ; 
		
		while(choice[arrIndex] !='\0')
		{			
			if(	(strlen(choice) == 1) &&
				((choice[arrIndex]>=49) && ( choice[arrIndex]<=54) ) )
				//((choice[arrIndex]>= '1') && ( choice[arrIndex]<= '6') ) )
			     arrIndex++ ; 
			else
			{
				cout<<"잘못된 숫자 또는 문자를 입력하셨습니다. "
					<<" 1~6까지의 숫자를 정확히 입력하세요!!!"<<endl ;   
				
				cout << endl <<"Choose the item : " ; 
				cin.getline(choice , 255, '\n') ; 				
				arrIndex = 0  ; 				
			} 			
		}//end_while

		switch( atoi(choice) )
		{
			case 1: tpbook.insert() ; break ;
			case 2: tpbook.remove() ; break ;
			case 3: tpbook.search() ; break ;
			case 4: tpbook.update() ; break ;
			case 5: tpbook.printAll() ; break ;
			case 6: return 0 ;
			default : cout << endl << " Illegal selection..." << endl ;
				break ;
		}
	}
	return 0 ;     
}