//MyFuncs.cpp
//Written by Jesse Gibbons
#include <iostream>
#include <string>
using namespace std;
#include "MyFuncs.h"
#include "AddrBook.h"
using namespace AddrBookLib;


std::string AddrBookLib::Prompt(std::string strPrompt)
{
	string response = "";
	cout << strPrompt;
	getline(cin, response);
	return response;
}
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

int AddrBookLib::GetResponseFromMenu()
{
	int response = -1;
	char chResponse = '\0';
	cout << "1: (A)dd a new contact to the address book.\n";
	cout << "2: (C)ount the Contacts are in the address book.\n";
	cout << "3: (P)rint out all the Contacts in the address Book.\n";
	cout << "4: (D)elete a contact from the address book";
	cout << "5: (Q)uit.";
	cout << "Plese pick an option: ";
	if (isdigit(cin.peek()))
	{
		cin >> response;
	}
	else
	{
		cin >> chResponse;
		switch (tolower(chResponse))
		{
		case 'a':
			response = 1;
			break;
		case 'c':
			response = 2;
			break;
		case 'p':
			response = 3;
			break;
		case 'd':
			response = 4;
			break;
		case 'q':
			response = 5;
			break;
		}
	}
	return response;
}

int AddrBookLib::GetContactToDeleteFromConsole(const AddrBook & book)
{
	int response = -1;
	book.PrintAllContacts();
	cout << "Which contact would you like to delete?";
	cin >> response;
	return response;
}
