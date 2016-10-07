//AddrBook.cpp
//Written by Jesse Gibbons
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "AddrBook.h"
#include "Contact.h"
#include "Name.h"
#include "Address.h"
#include "MyFuncs.h"
using namespace AddrBookLib;

AddrBook::AddrBook()
{
	used = 0;
}

void AddrBookLib::AddrBook::AddContact(CategorizedContact itemToAdd)
{
	if (used < MAX_ADDRBOOK_SIZE)
		contacts[used++] = itemToAdd;
}

void AddrBookLib::AddrBook::RemoveContact(CategorizedContact itemToRemove)
{
	int index = FindContact(itemToRemove);
	if (index != -1)
		RemoveByIndex(index);
}

int AddrBookLib::AddrBook::FindContact(CategorizedContact itemToFind) const
{
	for (int i = 0; i < used; i++)
	{
		if (itemToFind.ToString() == contacts[used].ToString())
			return i;
	}
	return -1;
}

void AddrBookLib::AddrBook::RemoveByIndex(int indexToRemove)
{
	if (used > 0 && InRange(indexToRemove, 0, used - 1))
		contacts[indexToRemove] = contacts[--used];
}

CategorizedContact AddrBookLib::AddrBook::GetContact(int index) const
{
	return contacts[index];
}

void AddrBookLib::AddrBook::PrintAllContacts() const
{
	for (int i = 0; i < used; i++)
	{
		cout << i + 1 << ") ";
		cout << contacts[i].ToString() << endl << endl;
	};
}

void AddrBookLib::AddrBook::PrintByCategory(Field category) const
{
	int count = 1;
	for (int i = 0; i < used; i++)
		if (contacts[i].GetCategory() == category)
			cout << count++ << ") " << contacts[i].ToString() << endl;
}

void AddrBookLib::AddrBook::AddContactFromCommandPrompt()
{
	CategorizedContact tmpContact;
	if (used >= MAX_ADDRBOOK_SIZE)
	{
		cout << "Address book full. Please delete a contact and try again.\n";
		return;
	}
	tmpContact.ConsoleInput();
	AddContact(tmpContact);
}

void AddrBookLib::AddrBook::ReadFile(string fileName)
{
	ifstream fileIn(fileName);
	CategorizedContact tmpContact;
	//Name tmpName;
	//Address tmpAddress;
	//Field tmpField;
	char delim = ',';
	if (!fileIn)
	{
		cerr << "Error opening file " << fileName << " to read." << endl << endl;
		return;
	}
	while (!fileIn.fail())
	{
		//read format fname1,lname1,street address1,city1,state1,zip1,phone1,email1,bday1,picture file1,
		if (tmpContact.ReadFromFile(fileIn, delim))
			AddContact(tmpContact);
		//if (fileIn.peek() == '\n') fileIn.ignore();
	}
	fileIn.close();
	return;
}

void AddrBookLib::AddrBook::WriteFile(string fileName) const
{
	ofstream outFile;
	outFile.open(fileName);
	if (!outFile)
	{
		cerr << "Error opening file for writing." << endl << endl;
		system("pause");
		return;
	}

	//write to file

	for (int i = 0; i < used; i++)
	{
		outFile << contacts[i].ToFileString() << endl;
	}

	outFile.close();

}