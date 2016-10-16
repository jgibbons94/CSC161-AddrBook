//AddrBook.cpp
//Written by Jesse Gibbons
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "AddrBook.h"
#include "Contact.h"
#include "Name.h"
#include "Address.h"
#include "AddrTest.h"
using namespace AddrBookLib;

AddrBook::AddrBook(int initialSize)
{
	used = 0;
	size = 0;
	content = NULL;
	alloc(initialSize);
}

AddrBookLib::AddrBook::AddrBook(const AddrBook & oldAddrBook)
{
	/*
	//in case it is full, add 1 to size to make the first addContact() easier.
	size = oldAddrBook.size + 1;
	used = oldAddrBook.used;
	content = new CategorizedContact[size];
	copy(oldAddrBook.content, oldAddrBook.content + oldAddrBook.size, content);
	*/
	*this = oldAddrBook;
}

AddrBookLib::AddrBook::~AddrBook()
{
	free();
}

void AddrBookLib::AddrBook::AddContact(const CategorizedContact & itemToAdd)
{
	if (used >= size)
		alloc(2);
		content[used++] = itemToAdd;
}

/*required but not used.*/
void AddrBookLib::AddrBook::RemoveContact(const CategorizedContact & itemToRemove)
{
	int index = FindContact(itemToRemove);
	if (index != -1)
		RemoveByIndex(index);
}

/*required but not used*/
int AddrBookLib::AddrBook::FindContact(const CategorizedContact & itemToFind) const
{
	for (int i = 0; i < used; i++)
	{
		if (itemToFind == content[i])
			return i;
	}
	return -1;
}

void AddrBookLib::AddrBook::RemoveByIndex(int indexToRemove)
{
	if (used > 0 && InRange(indexToRemove, 0, used - 1))
		content[indexToRemove] = content[--used];
}

/*required but not used*/
CategorizedContact AddrBookLib::AddrBook::GetContact(int index) const
{
	return content[index];
}

void AddrBookLib::AddrBook::PrintAllContacts() const
{
	for (int i = 0; i < used; i++)
	{
		cout << '\t'<<(i + 1) << ")\n";
		cout << content[i].ToString() << endl << endl;
		//wait half a second between displaying contacts
		//adjustable if this is too fast or slow.
		Delay(500);
	};
}

void AddrBookLib::AddrBook::PrintByCategory(const Field & category) const
{
	int count = 1;
	for (int i = 0; i < used; i++)
		if (content[i].GetCategory() == category)
		{
			cout << '\t' << count++ << ")\n" << content[i].ToString() << endl;
			//Unless the user is Data from STNG, we need a slight delay between printing functions.
			Delay(500);
		}
}

void AddrBookLib::AddrBook::ReadFile(const string & fileName)
{
	ifstream fileIn(fileName);
	CategorizedContact tmpContact;
	char delim = ',';
	if (!fileIn)
	{
		cerr << "Error opening file " << fileName << " to read." << endl << endl;
		fileIn.close();
		return;
	}
	while (!fileIn.fail())
	{
		// read format fname1,lname1,street address1,city1,state1,zip1,phone1,email1,bday1,picture file1,
		//if (tmpContact.ReadFromFile(fileIn, delim))
		fileIn >> tmpContact;
		if (!fileIn.fail())
			AddContact(tmpContact);
	}
	fileIn.close();
	return;
}

void AddrBookLib::AddrBook::WriteFile(const string & fileName) const
{
	ofstream outFile;
	outFile.open(fileName);
	if (!outFile)
	{
		cerr << "Error opening file for writing." << endl << endl;
		return;
	}

	// write to file

	for (int i = 0; i < used; i++)
	{
		outFile << content[i].ToFileString() << endl;
	}

	outFile.close();

}

AddrBook & AddrBookLib::AddrBook::operator=(const AddrBook & newAddrBook)
{
	// In case it is full, add 1 to size to make the first addContact() easier.
	// Do it anyway if it isn't full!
	if (this == &newAddrBook) return *this;
	free();
	size = newAddrBook.size + 1;
	used = newAddrBook.used;
	content = new CategorizedContact[size];
	copy(newAddrBook.content, newAddrBook.content + newAddrBook.size, content);
	return *this;
}

void AddrBookLib::AddrBook::alloc(int sizeIncrease)
{
	CategorizedContact * tmpContent = new CategorizedContact[size + sizeIncrease];
	if(content != NULL)
	copy(content, content + size, tmpContent);
	free();
	size += sizeIncrease;
	content = tmpContent;
}

void AddrBookLib::AddrBook::free()
{
	delete[] content;
	content = 0;
}
