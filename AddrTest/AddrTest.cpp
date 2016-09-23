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
	int menuAnswer = -1;
	int subMenuAnswer = -1;
	do
	{
		menuAnswer = GetResponseFromMenu();
		/*
		1. Add a new Contact to the AddressBook
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
			5. Exit the Program*/
		switch (menuAnswer)
		{
		case 1:
			yellowPages.AddContactFromCommandPrompt();
			break;
		case 2:
			cout << "There are " << yellowPages.GetUsed() << " contacts in the AddressBook.\n";
			break;
		case 3:
			yellowPages.PrintAllContacts();
			break;
		case 4:
			subMenuAnswer = GetContactToDeleteFromConsole(yellowPages);
			if (!InRange(subMenuAnswer, 1, yellowPages.GetUsed()))
				cout << "Invalid response. Please enter a number between 1 and " << yellowPages.GetUsed() << endl;
			else
				yellowPages.RemoveContactByIndex(subMenuAnswer);
			break;
		}

	} while (menuAnswer != 5);

	yellowPages.WriteFile(DB_LOCATION);

	cout << "\n\n";
	system("pause");
	return EXIT_SUCCESS;
}





