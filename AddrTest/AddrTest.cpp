/*
	Name:					Jesse Gibbons
	Course:					CSC161 - Section 001
	Program Name:			AddrBook Project 3
	Program Description:	Address book program that utilizes contact categories.
	Program Date:			September 29 2016
	Sources:

	Main Source
	Developer:				Scott Miner
	Scott's Source:			http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string,
							Jones, B. L., Aitken, P., & Miller, D. (2014). Sames Teach Yourself C Programming In One Hour a Day (7th ed.). Indianapolis, IN: Sams Publishing.
							Forouzan, B. A., & Gilberg, R. F. (2007). Computer science: A structured programming approach using C. Boston, MA: Thomson Course Technology.

	New sources:				http://www.cplusplus.com/reference/thread/this_thread/sleep_for/
								http://web.mst.edu/~nmjxv3/articles/templates.html
								C++ Primer Plus, 6th edition (Developer's library) by Steven Prata, Kindle edition
								http://www.windows-tech.info/17/51bc6313e18ef525.php


	TODO in main
	for Project 2:				1.  All strings that are Contact fields, need to be changed to Field class
								2.  Remove all getline functions and use >> on the Field object
								3.  Change the remove - instead of printing the entire Contact object for each, print Last, First for each one.
								4.  Change the print to print by category using the same format as Scott setup with this new sub-menu:
									(a) Work
									(b) Family
									(c) Friends
									(d) Other
									(e) All Contacts
								5. Change address.csv to include the category name (not letter) for an 11th Field.
								6. Change to CategorizedContact not Contact
								7. Review the project #2 specs for compliance
*/
#include <iostream> //provides cout and cin
#include <sstream>  //provides stringstream
#include <string>
#include <thread>
using namespace std;
#include "BinTree.h"
#include "AddrTest.h"
using namespace AddrBookLib;
#ifdef RUN_TESTS
#include "Tests.h"
using namespace test;
#endif

//PROTOTYPES for functions used by this demonstration program:

//quick menu functions

int main(int argc, const char * argv[]);

int menu(void);
//Postcondition: An integer is returned representing the user's menu choice

//char MenuCategory(bool get = false, istream& is=cin);
//parameter: get
// set to true if the user wants to print all the contacts in a category
// set to false (default) if the user wants to add a contact.
//Postcondition: A field is returned representing the user's choice from a list of cagegories.

//prompt 1
void addNewContact(AddrBook& myAddrBook);
//Precondition: AddrBook.getUsed() <= Capacity
//Postcondition: A new contact has been added into the bag

//prompt 2
void printUsed(AddrBook& myAddrBook);
//Postcondition: The number of entries in the address book is printed to the console window+

//prompt 4
void removeContacts(AddrBook& myAddrBook);
//Postcondition: If the entry is a valid entry, the entry is removed from the address book



//helpers



Field trim(const Field& str, const Field& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string

Field reduce(const Field& str, const Field& fill = " ", const Field& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string and any additional spaces
//between words have been removed from the string as well


//implementations

int main(int argc, const char * argv[])
{
#ifdef RUN_TESTS
	TestAll();
	Delay(24000);
#else
	int command = 0;
	AddrBook myAddrBook;

	//open the file for reading
	myAddrBook.ReadFile("address.csv");

	//call the menu function and get response
	command = menu();

	//take appropriate action based on user response
	while (command != 5)
	{
		switch (command)
		{
		case 1:
			addNewContact(myAddrBook);
			break;
		case 2:
			printUsed(myAddrBook);
			break;

		case 3:
		{
			Field choice = GetCategoryFromUser(true, "All");
			cout << "\n\tPrinting...\n\n";
			Delay();
			if (choice == "All") // print all contacts
			{
				myAddrBook.PrintAll();
			}
			else
			{
				int j = 0;
				for (AddrBook::Iterator i = myAddrBook.Begin(); i; i.Next())
				{
					CategorizedContact contact = *i;
					if (contact.GetCategory() == choice)
					{
						cout << j++ << " : " << contact;
					}
				}
			}
			cout << "\tReturning to Main Menu...\n\n";
			Delay();
			break;
		}
		case 4:
			removeContacts(myAddrBook);
			break;

		default:
			cout << "\n\tInvalid entry, please try again.\n";
			cout << "\tReturning to Main Menu...\n";
			Delay();
			break;
		}

		command = menu();
	}

	//when program is exited, write the file before leaving
	myAddrBook.WriteFile("address.csv");
	Delay();

	return 0;
#endif
}

//quick menu functions
int menu(void)
{
	Field reply;
	int choice;

	cout << "\t****************************************************************" << endl;
	cout << "\t*                          MENU                                *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t*   1.  Add a new Contact to the Address Book                  *" << endl;
	cout << "\t*   2.  Find out how many Contacts are in this AddressBook     *" << endl;
	cout << "\t*   3.  Print out all the contacts in the AddressBook          *" << endl;
	cout << "\t*   4.  Delete a Contact from the AddressBook                  *" << endl;
	cout << "\t*   5.  Exit the Program                                       *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\n\tPlease enter your selection: ";
	cin >> reply;

	//converts the number into an integer for processing
	stringstream(reply) >> choice;

	return choice;
}



//prompt 1
void addNewContact(AddrBook& myAddrBook)
{

	Name newName;
	Address newAddress;
	CategorizedContact newContact;
	Field answer;

	cout << "\n";

	cin >> newContact;

	//add the contact to the address book
	myAddrBook.Add(newContact);

	//confirmation of contact added
	cout << "\tContact has been added.\n";
	cout << "\tReturning to Main Menu...\n\n";

	Delay();
}

//prompt 2
void printUsed(AddrBook& myAddrBook)
{
	//Prints a message to the console window

	cout << "\n";
	cout << "\t****************************************************************\n";
	cout << "\t*                                                              *\n";
	cout << "\t*  Address Book contains " << myAddrBook.CountItems() << " contact(s).                         *\n";
	cout << "\t*                                                              *\n";
	cout << "\t****************************************************************\n";

	cout << "\n\tReturning to Main Menu....\n\n";
	Delay();
}

//prompt 3

//prompt 4
void removeContacts(AddrBook& myAddrBook)
{
	Field answer;
	int choiceRemove = 0;

	cout << "\n\tPrinting Contacts...\n";
	Delay();

	//print the contacts so user has a reference of what he is removing
	myAddrBook.PrintAll();

	//if user attempts to remove 0 entries from the address book
	if (myAddrBook.CountItems() == 0) {
		cout << "\tPlease add a contact to the address book before proceeding.";
		cout << "\n\tReturning to Main Menu....\n\n";
		Delay();
		return;
	}

	//prompt for entry number
	cout << "\tEnter the number of the entry you would like to delete: ";
	cin >> answer;

	//convert the string into an integer for processing
	stringstream(answer) >> choiceRemove;

	//call remove by index function, error processing is handled in the function
	myAddrBook.Remove(choiceRemove - 1);

	Delay();
}

Field reduce(const Field& str, const Field& fill, const Field& whitespace)
{
	//function from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	// removes trailing and leading white spaces and any additional spaces the user might hit between words
	// (ie. [  Scott       Miner   ] = [Scott Miner]

	// trim first
	auto result = trim(str, whitespace);

	// replace sub ranges
	auto beginSpace = result.find_first_of(whitespace);
	while (beginSpace != Field::npos)
	{
		const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
		const auto range = endSpace - beginSpace;

		result.replace(beginSpace, range, fill);

		const auto newStart = beginSpace + fill.length();
		beginSpace = result.find_first_of(whitespace, newStart);
	}

	return result;
}

Field trim(const Field& str, const Field& whitespace)
{
	//function from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	// removes trailing and leading white spaces
	// ie. [   Scott Miner     ] = [Scott Miner]

	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

void AddrBookLib::Delay(int milliseconds)
{

	this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

Field AddrBookLib::GetCategoryFromUser(bool get, Field fldDefault, std::istream & is)
{
	Field reply = "";
	Field category = "";
	char choice = '\0';
	cout << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\t*                Please enter a category                       *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t*   (a)  Work                                                  *" << endl;
	cout << "\t*   (b)  Family                                                *" << endl;
	cout << "\t*   (c)  Friends                                               *" << endl;
	cout << "\t*   (d)  Other                                                 *" << endl;
	if (get)
		cout << "\t*   (e)  All Contacts                                          *" << endl;

	cout << "\t*                                                              *" << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\n\tPlease enter your selection: ";
	is >> reply;

	//converts the number into an integer for processing
	stringstream(reply) >> choice;

	switch (choice)
	{
	case 'a':
	case 'A':
		category = "Work";
		break;
	case 'b':
	case 'B':
		category = "Family";
		break;
	case 'c':
	case 'C':
		category = "Friends";
		break;
	case 'd':
	case 'D':
		category = "Other";
		break;
	default:
		category = fldDefault;
	}
	return category;
}
