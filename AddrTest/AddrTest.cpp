/*
	Name: Jesse Gibbons
 Course:              CSC161 - Section 001
 Program Name:        AddrBook Project 3
 Program Description: Address book program that utilizes contact categories.
 Program Date:		  September 29 2016
 Sources:

   Main Source
   Developer:		      Scott Miner
   Scott's Source:      http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string,
					  Jones, B. L., Aitken, P., & Miller, D. (2014). Sames Teach Yourself C Programming In One Hour a Day (7th ed.). Indianapolis, IN: Sams Publishing.
					  Forouzan, B. A., & Gilberg, R. F. (2007). Computer science: A structured programming approach using C. Boston, MA: Thomson Course Technology.

   New sources:       http://www.cplusplus.com/reference/thread/this_thread/sleep_for/

TODO in main
for Project 2:		 1.  All strings that are Contact fields, need to be changed to Field class
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
#include "AddrBook.h"
#include "AddrTest.h"
using namespace AddrBookLib;

//PROTOTYPES for functions used by this demonstration program:

//quick menu functions

int menu(void);
//Postcondition: An integer is returned representing the user's menu choice

char MenuCategory(bool get = false);
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

Field CategoryFromChoice(char choice, const Field & fldDefault = "Other");
//parameter: choice
// A choice from MenuCategory()
//parameter: fldDefault
// The default return value if not from the menu
//Postcondition: Returns a Field represented by the given choice


//helpers

void delay(int milliseconds = 2000);
//Postcondition: The program is delayed for the specified amount of time in milliseconds
//param: milliseconds: the amount of time to delay
//milliseconds default: 2000 milliseconds = 2 seconds


Field trim(const Field& str, const Field& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string

Field reduce(const Field& str, const Field& fill = " ", const Field& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string and any additional spaces
//between words have been removed from the string as well


//implementations

int main(int argc, const char * argv[])
{
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
			char choice = MenuCategory(true);
			cout << "\n\tPrinting...\n\n";
			delay();
			if (choice == 'e') // print all contacts
			{
				myAddrBook.PrintAllContacts("\t");
			}
			else
			{
				myAddrBook.PrintByCategory(CategoryFromChoice(choice), "\t");
			}
			cout << "\tReturning to Main Menu...\n\n";
			delay();
			break;
		}
		case 4:
			removeContacts(myAddrBook);
			break;

		default:
			cout << "\n\tInvalid entry, please try again.\n";
			cout << "\tReturning to Main Menu...\n";
			delay();
			break;
		}

		command = menu();
	}

	//when program is exited, write the file before leaving
	myAddrBook.WriteFile("address.csv");
	delay();

	return 0;
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

	getline(cin, reply);

	//converts the number into an integer for processing
	stringstream(reply) >> choice;

	return choice;
}

char MenuCategory(bool get)
{
	string reply = "";
	Field category = "";
	char choice = '\0';

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
	getline(cin, reply);

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

	//if the address book is full, alert the user
	if (myAddrBook.GetUsed() >= MAX_ADDRBOOK_SIZE)
	{
		cout << "\t****************************************************************\n";
		cout << "\t*                                                              *\n";
		cout << "\t*   Address Book is full.                                      *\n";
		cout << "\t*   Please remove 1 or more entries before adding any more.    *\n";
		cout << "\t*                                                              *\n";
		cout << "\t****************************************************************\n";
		cout << "\n\tReturning to Main Menu....\n\n";
		delay();
		return;
	}


	//Have the user specify the new contact's category.
	answer = CategoryFromChoice(MenuCategory(false));
	newContact.SetCategory(answer);

	cout << "\t****************************************************************\n";
	cout << "\t*\n";
	cout << "\t*\n";

	// Get all the contact user from the user, trim and reduce white space, set contact information for the new contact
	cout << "\t*   Enter First Name: ";
	cin >> answer;
	answer = reduce(answer);
	newName.SetFirstName(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Last Name: ";
	cin >> answer;
	answer = reduce(answer);
	newName.SetLastName(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Street Address: ";
	cin >> answer;
	answer = reduce(answer);
	newAddress.SetStreetAddress(answer);
	cout << "\t*\n";

	cout << "\t*   Enter City: ";
	cin >> answer;
	answer = reduce(answer);
	newAddress.SetCity(answer);
	cout << "\t*\n";

	cout << "\t*   Enter State: ";
	cin >> answer;
	answer = reduce(answer);
	newAddress.SetState(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Zip: ";
	cin >> answer;
	answer = trim(answer);
	newAddress.SetZip(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Phone Number: ";
	cin >> answer;
	answer = trim(answer);
	newContact.SetPhone(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Email Address: ";
	cin >> answer;
	answer = trim(answer);
	newContact.SetEmail(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Birthday: ";
	cin >> answer;
	answer = trim(answer);
	newContact.SetBirthday(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Picture File: ";
	cin >> answer;
	answer = trim(answer);
	newContact.SetPictureFile(answer);
	cout << "\t*\n";

	cout << "\t****************************************************************\n\n";

	//update full name and address for the new contact
	newContact.SetFullName(newName);
	newContact.SetFullAddress(newAddress);

	//add the contact to the address book
	myAddrBook.AddContact(newContact);

	//confirmation of contact added
	cout << "\tContact has been added.\n";
	cout << "\tReturning to Main Menu...\n\n";

	delay();
}

//prompt 2
void printUsed(AddrBook& myAddrBook)
{
	//Prints a message to the console window

	cout << "\n";
	cout << "\t****************************************************************\n";
	cout << "\t*                                                              *\n";
	cout << "\t*  Address Book contains " << myAddrBook.GetUsed() << " contact(s).                         *\n";
	cout << "\t*                                                              *\n";
	cout << "\t****************************************************************\n";

	cout << "\n\tReturning to Main Menu....\n\n";
	delay();
}

//prompt 3

//prompt 4
void removeContacts(AddrBook& myAddrBook)
{
	Field answer;
	int choiceRemove = 0;

	cout << "\n\tPrinting Contacts...\n";
	delay();

	//print the contacts so user has a reference of what he is removing
	myAddrBook.PrintAllContacts();

	//if user attempts to remove 0 entries from the address book
	if (myAddrBook.GetUsed() == 0) {
		cout << "\tPlease add a contact to the address book before proceeding.";
		cout << "\n\tReturning to Main Menu....\n\n";
		delay();
		return;
	}

	//prompt for entry number
	cout << "\tEnter the number of the entry you would like to delete: ";
	getline(cin, answer);

	//convert the string into an integer for processing
	stringstream(answer) >> choiceRemove;

	//call remove by index function, error processing is handled in the function
	myAddrBook.RemoveByIndex(choiceRemove - 1);

	delay();
}

//helpers
Field CategoryFromChoice(char choice, const Field & fldDefault)
{
	Field category;
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

void delay(int milliseconds)
{

	this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
