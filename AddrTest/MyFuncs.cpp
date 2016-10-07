//MyFuncs.cpp
//Written by Jesse Gibbons

#include <iostream>
#include <string>
using namespace std;
#include "MyFuncs.h"
#include "AddrBook.h"
using namespace AddrBookLib;

/*
std::string AddrBookLib::Prompt(std::string strPrompt)
{
	string response = "";
	cout << strPrompt;
	ClearConsoleInput();
	getline(cin, response);
	return response;
}
*/
/*
bool AddrBookLib::GetField(std::ifstream & fileIn, string & outField, char delimeter)
{
	if (!fileIn)
	{
		return false;
	}
	getline(fileIn, outField, delimeter);
	if (fileIn.peek() == delimeter)
		fileIn.ignore();
	return true;
}
/**/
/*
int AddrBookLib::GetResponseFromMenu()
{
	int response = -1;
	char peek;
	//Enter the numbered choice.
	//Or enter the letter in the parentheses.
	cout << "1: (A)dd a new contact to the address book.\n";
	cout << "2: (C)ount the Contacts are in the address book.\n";
	cout << "3: (P)rint out all the Contacts in the address Book.\n";
	cout << "4: (D)elete a contact from the address book.\n";
	cout << "5: (Q)uit.\n";
	cout << endl;
	cout << "Plese pick an option: ";
	//Spaces prevent this menu style from working with other functions.
	ClearConsoleInput();
	if (isdigit(peek = cin.peek()))
	{
		cin >> response;
	}
	else
	{
		switch (tolower(peek))
		{
		case 'a':
		case '1':
			response = 1;
			break;
		case 'c':
		case '2':
			response = 2;
			break;
		case 'p':
		case '3':
			response = 3;
			break;
		case 'd':
		case '4':
			response = 4;
			break;
		case 'q':
		case '5':
			response = 5;
			break;
		}
	}
	return response;
}
/**/
/*
int AddrBookLib::GetContactToDeleteFromConsole(const AddrBook & book)
{
	int response = -1;
	book.PrintAllContacts();
	cout << "Which contact would you like to delete?";
	ClearConsoleInput();
	if (isdigit(cin.peek()))
		cin >> response;
	return response;
}

/**/
/*
void AddrBookLib::ClearConsoleInput()
{
	string str = "";
	char peek = '\n';
	while ((peek = (char)(cin.peek())) == '\n')
	{
		getline(cin, str);
	}
}

/**/

Field AddrBookLib::Prompt(const Field & fldPrompt)
{
	Field ret;
	cout << fldPrompt;
	cin >> ret;
	return ret;
}
