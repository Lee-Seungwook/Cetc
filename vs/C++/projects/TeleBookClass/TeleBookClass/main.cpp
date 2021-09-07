//main.cpp

#include <iostream>
#include "telphonebook.h"
using namespace std;

void print_menu()
{
	cout << endl << endl ;  
	cout << "---Menu ---" << endl  ;  
	cout << " 1. Insert" << endl ;
	cout << " 2. Delete " << endl ;
	cout << " 3. Search " << endl ;  
	cout << " 4. Print All" << endl ;
	cout << " 5. Update" << endl;
	cout << " 6. Exit " << endl ; 
}

int main()
{
	TelPhoneBook tpbook ;
	int choice ;
	char stopper;

	while(1)
	{
		print_menu() ;
		cout << endl <<"Choose the item : " ;
		cin >> choice ;
		cin.get() ;

		switch(choice)
		{
		case 1: tpbook.insert() ; break ;
		case 2: tpbook.remove() ; break ;
		case 3: tpbook.search() ; break ;
		case 4: tpbook.printAll() ; break ;
		case 5: tpbook.update(); break;
		case 6 : 
		
		return 0 ;
		default : cout << endl << " Illegal selection..." << endl ;
			break ;
		}
		if (choice < 1)
			break;
		if (choice > 6)
			break;
	}
	return 0 ;     
}