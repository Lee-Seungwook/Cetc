//telphonebook.cpp
//
#include "telphonebook.h"

void TelPhoneBook::insert()
{
	char name[NAMELEN];
	char phone[PHONELEN];

	cout << "[ Insert ]" << "\n";

	cout << "Input Name : ";
	cin.getline(name, NAMELEN, '\n');
	cout << "Input Tel Number : ";
	cin.getline(phone, PHONELEN, '\n');
	cout << "주소를 입력하세요: ";
	cin.getline(address, 51, '\n');

	//Person   ob(name , phone) ;
	//phoneList[pidx++] = ob ;
	phoneList[pidx++] = virtual Person(name, phone);
	//Person   kang = Person(name , phone) ;
	//cout<<"name= "<<kang.getName()<<", "<<
		//"phone="<<kang.getPhoneNumber()<<endl ;

	cout << "New Data Inserted..." << endl;


} ;       

void TelPhoneBook::search()
{
	char name[NAMELEN];

	cout << "Enter Name : ";
	cin.getline(name, NAMELEN, '\n'); ;

	cout << endl << " [ Search Result ] :  ";

	for (int i = 0; i < pidx; i++)
		if (strcmp(phoneList[i].getName(), name) == 0)
		{
			cout << "Name : " << phoneList[i].getName() << " / "
				<< "Phone : " << phoneList[i].getPhoneNumber() << endl;
			return;
		}
	cout << "No Data Found " << endl;
} ;       

void TelPhoneBook::remove()
{
	char name[NAMELEN];
	cout << "Enter Name : ";
	cin.getline(name, NAMELEN, '\n');
	cout << endl << "[ Delete Result ] : ";
	for (int i = 0; i < pidx; i++)
		if (strcmp(phoneList[i].getName(), name) == 0)
		{
			for (int j = i + 1; j < pidx; j++)
				phoneList[j - 1] = phoneList[j];
			pidx--;
			cout << "Delete Completed... " << endl;
			return;
		}
	cout << "No Data Found" << endl;
}

void TelPhoneBook::printAll()
{
	cout << endl << " [ Print Result ] : " << endl;

	for (int i = 0; i < pidx; i++)
		cout << "Name : " << phoneList[i].getName() << " / "
		<< "Phone : " << phoneList[i].getPhoneNumber() << endl;

	 
}

void TelPhoneBook::update()
{
	char name[30];
	char phone[30];

	int upidx = 0;
	int choice = 0;

	cout << "Index for Update : ";
	cin >> upidx;

	cin.ignore(1, '\n');
	cout << "Enter Name : ";
	cin.getline(name, 30, '\n');
	printf("Enter Phone Number : ");
	cin.getline(phone, 30, '\n');
	strcpy_s(phoneList[upidx].getName(), strlen(name) + 1, name);
	strcpy_s(phoneList[upidx].getPhoneNumber(), strlen(phone) + 1, phone);

	printf(" ---> Update Completed..\n");
}
