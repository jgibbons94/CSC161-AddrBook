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
using namespace AddrBookLib;

AddrBook::AddrBook()
{
	used = 0;
}

void AddrBookLib::AddrBook::AddContact(Contact itemToAdd)
{
	if (used < MAX_ADDRBOOK_SIZE)
		contacts[used++] = itemToAdd;
}

void AddrBookLib::AddrBook::RemoveContact(Contact itemToRemove)
{
	int index = FindContact(itemToRemove);
	if (index != -1)
		RemoveContactByIndex(index);
}

int AddrBookLib::AddrBook::FindContact(Contact itemToFind) const
{
	for (int i = 0; i < used; i++)
	{
		if (itemToFind.ToString() == contacts[used].ToString())
			return i;
	}
	return -1;
}

void AddrBookLib::AddrBook::RemoveContactByIndex(int indexToRemove)
{
	if (used > 0 && indexToRemove >= 0 && indexToRemove < used)
		contacts[indexToRemove] = contacts[--used];
}

void AddrBookLib::AddrBook::PrintAllContacts() const
{
	for (int i = 0; i < used; i++)
	{
		cout << i+1 << ") ";
		cout << contacts[i].ToString() << endl;
	};
}

void AddrBookLib::AddrBook::ReadFile(std::string fileName)
{
	ifstream fileIn(fileName);
	Contact tmpContact;
	Name tmpName;
	Address tmpAddress;
	string tmpField;
	char delim = ',';
	if (!fileIn)
	{
		cerr << "Error opening file " << fileName << " to read." << endl;
		return;
	}
	while (!fileIn.fail())
	{
		//read format fname1,lname1,street address1,city1,state1,zip1,phone1,email1,bday1,picture file1,
		if(tmpContact.ReadFromFile(fileIn, delim))
			AddContact(tmpContact);
		if (fileIn.peek() == '\n') fileIn.ignore();
	}
	fileIn.close();
	return;
}

void AddrBookLib::AddrBook::WriteFile(std::string fileName) const
{
	ofstream outFile;
	outFile.open(fileName);
	if (!outFile)
	{
		cerr << "Error opening file for writing\n";
		system("pause");
		return;
	}

	//write to file

	for (int i = 0; i < used; i++)
	{
		outFile << contacts[i].ToFileString() << endl;
		string str = contacts[i].ToFileString();
		int loc = str.find_first_of('\n');
		cerr << contacts[i].ToFileString() << endl;
	}

	outFile.close();

}