/*
	Name: Jesse Gibbons
	Course Prefix, Number, Section: CSC161001
	Program Name: AddrTest
	Program Description: Tests the AddrBook library:
	Add a new Contact to the AddressBook
	Prompt for First Name
	Prompt for Last Name
	Prompt for Street Address
	Prompt for City Address
	Prompt for State Address
	Prompt for Zip Address
	Prompt for Phone Number
	Prompt for Email Address
	Prompt for Birthday
	Prompt for Picture File
	2. Find out how many Contacts are in the AddressBook
	3. Print out all the Contacts in the AddressBook
	(Print a counter in front of each contact - starting at 1)
	4. Delete a Contact from the AddressBook
	Prompt for the item number to delete (counting number starting at 1)
	5. Exit the Program

	Program Date: 12 September, 2016
	Sources Cited (book, website, other):
		No citations.
*/
#include <iostream>
//#include <string>
#include <cstdlib>
using namespace std;
#include "Name.h"
#include "Address.h"
#include "Contact.h"
#include "AddrBook.h"
#include "MyFuncs.h"
using namespace AddrBookLib;
#define DB_LOCATION ("Address.csv")
int main()
{
	AddrBook yellowPages;
	yellowPages.ReadFile(DB_LOCATION);
	Contact tempContact;
	char chAnswer = 'y';

	tempContact.ConsoleInput();
	yellowPages.AddContact(tempContact);
	//how many contacts?
	yellowPages.PrintAllContacts();
	cout << "There are " << yellowPages.GetUsed() << " contacts in the AddressBook.\n";
	//What if the user does not want to delete a contact?
	//Prompt the user if we should delete a contact:
	if (yellowPages.GetUsed() < MAX_ADDRBOOK_SIZE-1)
	{
		do
		{
			cout << "Do you want to delete a contact? (y/n) ";
			cin >> chAnswer;
		} while (tolower(chAnswer) != 'y'&&tolower(chAnswer) != 'n');
	}
	else
	{
		cout << "Address book is almost Full. Please delete a contact.";
	}
	if (tolower(chAnswer) == 'y')
	{
		int indexToRemove = -1;
		//TODO: list all the contacts in yellowPages, prompt which one we should delete, and delete by index that contact.
		do
		{
			yellowPages.PrintAllContacts();
			cout << endl;

			cout << "Please enter the contact number to delete: ";
			cin >> indexToRemove;
		}
		while (!(InRange(indexToRemove,1,yellowPages.GetUsed())));
		yellowPages.RemoveContactByIndex(indexToRemove-1);
	}
	yellowPages.WriteFile(DB_LOCATION);

	cout << "\n\n";
	system("pause");
	return EXIT_SUCCESS;
}