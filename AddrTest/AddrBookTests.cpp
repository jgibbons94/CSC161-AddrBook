//AddrBookTests.cpp
//Created by Jesse Gibbons

#include <cassert>
#include <iostream>
using namespace std;

#include "AddrBookTests.h"

//We don't need AddrBook to include AddrTests unless we are compiling the friend functions.
#ifndef ADDRBOOK_TEST_FRIENDS
#define ADDRBOOK_TEST_FRIENDS
#endif

#include "AddrBook.h"
#include "Contact.h"
using namespace AddrBookLib;
void test::TestAddrBook()
{
	TestAddrBook_CopyConstructor();
	TestAddrBook_Destructor();
	TestAddrBook_Assignment0();
	TestAddrBook_Assignment1();
	TestAddrBook_AddContact();
	TestAddrBook_RemoveContact();
	TestAddrBook_FindItem();
	TestAddrBook_RemoveByIndex();
	TestAddrBook_GetUsed();
	TestAddrBook_GetContact();
	TestAddrBook_ReadFile();
	TestAddrBook_WriteFile();
}

void test::TestAddrBook_CopyConstructor()
{
	AddrBook book1;
	AddrBook book2(book1);
	assert(book1.content != book2.content);
}

void test::TestAddrBook_Destructor()
{
	AddrBook * book = new AddrBook();
	CategorizedContact * contacts = book->content;
	delete book;
	bool successful = false;
	try
	{
		CategorizedContact contact = contacts[0];
		cerr << "Did not properly delete book->contacts." << endl;
	}
	catch (...)
	{
		successful = true;
	}
	assert(successful);
}
//make sure the contents of book1 is copied to book2, but the contents are not in the same location.
void test::TestAddrBook_Assignment0()
{
	AddrBook book1;
	AddrBook book2;
	book1 = book2;
	assert(book1.content != book2.content);
}
//make sure book1.content is deleted!
void test::TestAddrBook_Assignment1()
{
	AddrBook book1;
	CategorizedContact* contacts = book1.content;
	AddrBook book2;
	bool test = false;
	book1 = book2;
	try
	{
		CategorizedContact contact = contacts[0];
		cerr << "Did not properly delete book1.contacts during assignment operator." << endl;
	}
	catch (...)
	{
		test = true;
	}
	assert(test);
}

void test::TestAddrBook_AddContact()
{
	AddrBook yellowpages;
	yellowpages.AddContact(CategorizedContact());
	assert(yellowpages.GetUsed() == 1);
}

void test::TestAddrBook_RemoveContact()
{
	AddrBook yellowpages;
	yellowpages.AddContact(CategorizedContact());
	yellowpages.RemoveContact(CategorizedContact());
	assert(yellowpages.GetUsed() == 0);
}

void test::TestAddrBook_FindItem()
{
	AddrBook yellowpages;
	yellowpages.AddContact(CategorizedContact());
	assert(yellowpages.FindContact(CategorizedContact()) != -1);
}

void test::TestAddrBook_RemoveByIndex()
{
	AddrBook yellowpages;
	yellowpages.AddContact(CategorizedContact());
	yellowpages.RemoveByIndex(0);
	assert(yellowpages.GetUsed() == 0);
}

void test::TestAddrBook_GetUsed()
{
	AddrBook yellowpages;
	int desiredLength = 4;
	for (int i = 0; i < desiredLength;i++)
	{
		yellowpages.AddContact(CategorizedContact());
	}
	assert(yellowpages.GetUsed() == desiredLength);

}

void test::TestAddrBook_GetContact()
{
	AddrBook yellowPages;
	yellowPages.AddContact(CategorizedContact(Contact(), "foo"));
	assert(yellowPages.GetContact(0).GetCategory() == "foo");
}

void test::TestAddrBook_ReadFile()
{
	AddrBook yellowpages;
	ofstream ofs;
	CategorizedContact targetContact(Contact(Name("first2", "last2"), Address("street address2", "city2", "state2", "zip2"), "phone2", "email2", "bday2", "pic2"), "other");
	int index = 0;
	ofs.open("test.csv");
	if (!ofs)
	{
		cerr << "Could not open file test.csv to write." << endl;
		return;
	}
	ofs << "family,first,last,street address,city,state,zip,phone,email,bday,pic,\n"
		<< "other,first2,last2,street address2,city2,state2,zip2,phone2,email2,bday2,pic2,\n";
	ofs.close();
	yellowpages.ReadFile("test.csv");
	remove("test.csv");
	index = yellowpages.FindContact(targetContact);
	assert(index == 1);
}

void test::TestAddrBook_WriteFile()
{
	AddrBook yellowpages;
	ifstream ifs;
	CategorizedContact targetContact(Contact(Name("first2", "last2"), Address("street address2", "city2", "state2", "zip2"), "phone2", "email2", "bday2", "pic2"), "other");
	Field fld;
	yellowpages.AddContact(targetContact);
	yellowpages.WriteFile("test.csv");
	ifs.open("test.csv");
	getline(ifs, fld, '\n');
	ifs.close();
	remove("test.csv");
	assert(fld == "other,first2,last2,street address2,city2,state2,zip2,phone2,email2,bday2,pic2,");
}
