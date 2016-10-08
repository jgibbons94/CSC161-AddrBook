//Tests.cpp
//Created by Jesse Gibbons
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include "Tests.h"
using namespace test;

#include "Field.h"
#include "Field.h"
#include "Address.h"
#include "Contact.h"
#include "CategorizedContact.h"
#include "AddrBook.h"
using namespace AddrBookLib;

void test::TestAll()
{
	TestField();
	TestName();
	TestAddress();
	TestContact();
	TestCategorizedContact();
	TestAddrBook();
}

void test::TestAddrBook()
{
	TestAddrBook_AddContact();
	TestAddrBook_RemoveContact();
	TestAddrBook_FindItem();
	TestAddrBook_RemoveByIndex();
	TestAddrBook_GetUsed();
	TestAddrBook_GetContact();
	TestAddrBook_ReadFile();
	TestAddrBook_WriteFile();
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

void test::TestAddress()
{
	TestAddress_Constructor0();
	TestAddress_Constructor1();
	TestAddress_Constructor2();
	TestAddress_Constructor3();
	TestAddress_Constructor4();
	TestAddress_GetStreetAddress();
	TestAddress_SetStreetAddress();
	TestAddress_GetCity();
	TestAddress_SetCity();
	TestAddress_GetState();
	TestAddress_SetState();
	TestAddress_GetZip();
	TestAddress_SetZip();
	TestAddress_ToString();
	TestAddress_ToFileString();
	TestAddress_ToFileString1();
}

void test::TestAddress_Constructor0()
{
	Address addr;
	assert((addr.GetStreetAddress() == "") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor1()
{
	Address addr("Street");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor2()
{
	Address addr("Street", "City");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor3()
{
	Address addr("Street", "City", "State");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor4()
{
	Address addr("Street", "City", "State", "Zip");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == "Zip"));
}

void test::TestAddress_GetStreetAddress()
{
	Address addr("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_SetStreetAddress()
{
	Address addr;
	addr.SetStreetAddress("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_GetCity()
{
	Address addr("", "City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_SetCity()
{
	Address addr;
	addr.SetCity("City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_GetState()
{
	Address addr("", "", "State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_SetState()
{
	Address addr;
	addr.SetState("State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_GetZip()
{
	Address addr("", "", "", "Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_SetZip()
{
	Address addr;
	addr.SetZip("Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_ToString()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToString();
	assert(fld == "1\n\t\t\t2, 3 4");
}


void test::TestAddress_ToFileString()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToFileString();
	assert(fld == "1,2,3,4");
}

void test::TestAddress_ToFileString1()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToFileString(' ');
	assert(fld == "1 2 3 4");
}

void test::TestCategorizedContact()
{
	TestCategorizedContact_Constructor0();
	TestCategorizedContact_Constructor1();
	TestCategorizedContact_Constructor2();
	TestCategorizedContact_SetCategory();
	TestCategorizedContact_GetCategory();
	TestCategorizedContact_ToString();
	TestCategorizedContact_ToFileString();
	TestCategorizedContact_ToFileString1();
}

void test::TestCategorizedContact_Constructor0()
{
	CategorizedContact contact;
	assert(
		(contact.GetFullName().GetFirstName() == "") && (contact.GetFullName().GetLastName() == "")
		&& (contact.GetFullAddress().GetStreetAddress() == "") && (contact.GetFullAddress().GetCity() == "") && (contact.GetFullAddress().GetState() == "") && (contact.GetFullAddress().GetZip() == "")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == "") && (contact.GetCategory() == ""));
}

void test::TestCategorizedContact_Constructor1()
{
	CategorizedContact contact(Contact(Name("first2", "last2"), Address("street address2", "city2", "state2", "zip2"), "phone2", "email2", "bday2", "pic2"));
	assert((contact.GetFullName().GetFirstName() == "first2") && (contact.GetFullName().GetLastName() == "last2")
		&& (contact.GetFullAddress().GetStreetAddress() == "street address2") && (contact.GetFullAddress().GetCity() == "city2") && (contact.GetFullAddress().GetState() == "state2") && (contact.GetFullAddress().GetZip() == "zip2")
		&& (contact.GetPhone() == "phone2") && (contact.GetEmail() == "email2") && (contact.GetBirthday() == "bday2") && (contact.GetPictureFile() == "pic2")
		&& (contact.GetCategory() == ""));
}

void test::TestCategorizedContact_Constructor2()
{
	CategorizedContact contact(Contact(Name("first2", "last2"), Address("street address2", "city2", "state2", "zip2"), "phone2", "email2", "bday2", "pic2"), "other");
	assert(
		(contact.GetFullName().GetFirstName() == "first2")
		&& (contact.GetFullName().GetLastName() == "last2")
		&& (contact.GetFullAddress().GetStreetAddress() == "street address2")
		&& (contact.GetFullAddress().GetCity() == "city2")
		&& (contact.GetFullAddress().GetState() == "state2")
		&& (contact.GetFullAddress().GetZip() == "zip2")
		&& (contact.GetPhone() == "phone2")
		&& (contact.GetEmail() == "email2")
		&& (contact.GetBirthday() == "bday2")
		&& (contact.GetPictureFile() == "pic2")
		&& (contact.GetCategory() == "other"));
}

void test::TestCategorizedContact_GetCategory()
{
	CategorizedContact contact(Contact(), "foo");
	assert(contact.GetCategory() == "foo");
}

void test::TestCategorizedContact_SetCategory()
{
	CategorizedContact contact;
	contact.SetCategory("foo");
	assert(contact.GetCategory() == "foo");
}

void test::TestCategorizedContact_ToString()
{
	CategorizedContact contact(Contact(Name("Julie", "Schneider"), Address("13300 W 6th Ave.", "Lakewood", "Colorado", "80228"), "303 - 914 - 6247", "julie.schneider@rrcc.edu", "Feb. 3", "julie.jpg"), "family");
	Field fld = contact.ToString();
	Field expectedField = "\t Category:\tfamily\n\t    Name :\tSchneider, Julie\n\t Address :\t13300 W 6th Ave.\n\t\t\tLakewood, Colorado 80228\n\t   Phone :\t303 - 914 - 6247\n\t   Email :\tjulie.schneider@rrcc.edu\n\tBirthday :\tFeb. 3\n\tPictFile :\tjulie.jpg\n";
	assert(fld == expectedField);
}

void test::TestCategorizedContact_ToFileString()
{
	CategorizedContact contact(Contact(Name("first", "last"), Address("street address", "city", "state", "zip"), "phone", "email", "bday", "pic"), "other");
	assert(contact.ToFileString() == "other,first,last,street address,city,state,zip,phone,email,bday,pic,");
}

void test::TestCategorizedContact_ToFileString1()
{
	CategorizedContact contact(Contact(Name("first", "last"), Address("street address", "city", "state", "zip"), "phone", "email", "bday", "pic"), "other");
	Field testedField = contact.ToFileString(' ');
	assert(testedField == "other first last street address city state zip phone email bday pic ");
}

void test::TestContact()
{
	TestContact_Constructor0();
	TestContact_Constructor1();
	TestContact_Constructor2();
	TestContact_Constructor3();
	TestContact_Constructor4();
	TestContact_Constructor5();
	TestContact_Constructor6();
	TestContact_GetFullName();
	TestContact_SetFullName();
	TestContact_GetFullAddress();
	TestContact_SetFullAddress();
	TestContact_GetPhone();
	TestContact_SetPhone();
	TestContact_GetEmail();
	TestContact_SetEmail();
	TestContact_GetBirthday();
	TestContact_SetBirthday();
	TestContact_GetPictureFile();
	TestContact_SetPictureFile();
	TestContact_ToString();
	TestContact_ToFileString();
	TestContact_ToFileString1();
}

void test::TestContact_Constructor0()
{
	Contact contact;
	assert(
		(contact.GetFullName().GetFirstName() == "") && (contact.GetFullName().GetLastName() == "")
		&& (contact.GetFullAddress().GetStreetAddress() == "") && (contact.GetFullAddress().GetCity() == "") && (contact.GetFullAddress().GetState() == "") && (contact.GetFullAddress().GetZip() == "")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor1()
{
	Contact contact(Name("1", "2"));
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "") && (contact.GetFullAddress().GetCity() == "") && (contact.GetFullAddress().GetState() == "") && (contact.GetFullAddress().GetZip() == "")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor2()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"));
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor3()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor4()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor5()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "9") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor6()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "9") && (contact.GetPictureFile() == "10"));
}

void test::TestContact_GetFullName()
{
	Contact contact(Name("hello", "world"));
	assert((contact.GetFullName().GetFirstName() == "hello") && (contact.GetFullName().GetLastName() == "world"));
}

void test::TestContact_SetFullName()
{
	Contact contact;
	contact.SetFullName(Name("hello", "world"));
	assert((contact.GetFullName().GetFirstName() == "hello") && (contact.GetFullName().GetLastName() == "world"));
}

void test::TestContact_GetFullAddress()
{
	Contact contact(Name(), Address("1", "2", "3", "4"));
	assert((contact.GetFullAddress().GetStreetAddress() == "1") && (contact.GetFullAddress().GetCity() == "2") && (contact.GetFullAddress().GetState() == "3") && (contact.GetFullAddress().GetZip() == "4"));
}

void test::TestContact_SetFullAddress()
{
	Contact contact;
	contact.SetFullAddress(Address("1", "2", "3", "4"));
	assert((contact.GetFullAddress().GetStreetAddress() == "1") && (contact.GetFullAddress().GetCity() == "2") && (contact.GetFullAddress().GetState() == "3") && (contact.GetFullAddress().GetZip() == "4"));
}

void test::TestContact_GetPhone()
{
	Contact contact(Name(), Address(), "phone");
	assert(contact.GetPhone() == "phone");
}

void test::TestContact_SetPhone()
{
	Contact contact;
	contact.SetPhone("phone");
	assert(contact.GetPhone() == "phone");
}

void test::TestContact_GetEmail()
{
	Contact contact(Name(), Address(), "", "email");
	assert(contact.GetEmail() == "email");
}

void test::TestContact_SetEmail()
{
	Contact contact;
	contact.SetEmail("email");
	assert(contact.GetEmail() == "email");
}

void test::TestContact_GetBirthday()
{
	Contact contact(Name(), Address(), "", "", "Birthday");
	assert(contact.GetBirthday() == "Birthday");
}

void test::TestContact_SetBirthday()
{
	Contact contact;
	contact.SetBirthday("birthday");
	assert(contact.GetBirthday() == "birthday");
}

void test::TestContact_GetPictureFile()
{
	Contact contact(Name(), Address(), "", "", "", "picture");
	assert(contact.GetPictureFile() == "picture");
}

void test::TestContact_SetPictureFile()
{
	Contact contact;
	contact.SetPictureFile("/dev/null");
	assert(contact.GetPictureFile() == "/dev/null");
}

void test::TestContact_ToString()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field fld = contact.ToString();
	assert(fld == "2, 1\n3\n\t\t\t4, 5 6\n7\n8\n9\n10\n");
}

void test::TestContact_ToFileString()
{
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field fld = contact.ToFileString();
	assert(fld == "1,2,3,4,5,6,7,8,9,10,");
}

void test::TestContact_ToFileString1()
{

	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field fld = contact.ToFileString('\t');
	assert(fld == "1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t");
}

void test::TestField()
{
	TestField_Constructor0();
	TestField_ConstructorString();
	TestField_ConstructrCharPtr();
	TestField_Shift_Istream();
	TestField_Shift_Ifstream();
}

void test::TestField_Constructor0()
{
	Field fld;
	assert(fld == "");
}

void test::TestField_ConstructrCharPtr()
{
	Field fld("char");
	assert(fld == "char");
}

void test::TestField_ConstructorString()
{
	string str = "str";
	Field fld(str);
	assert(fld == "str");
}

void test::TestField_Shift_Istream()
{
	Field fld;
	istringstream iss("line 1 \n line 2 ");
	iss >> fld;
	assert(fld == "line 1 ");
}

void test::TestField_Shift_Ifstream()
{
	Field fld;
	ofstream ofs;
	ifstream ifs;
	ofs.open("test.csv");
	if (!ofs)
	{
		cerr << "Could not open file test.csv to write." << endl;
		return;
	}
	ofs << "item1,item2";
	ofs.close();
	ifs.open("test.csv");
	if (!ifs)
	{
		cerr << "Could not open file test.csv to read." << endl;
		return;
	}
	ifs >> fld;
	ifs.close();
	remove("test.csv");
	assert(fld == "item1");

}

void test::TestName()
{
	TestName_Constructor0();
	TestName_Constructor1();
	TestName_Constructor2();
	TestName_GetFirstName();
	TestName_SetFirstName();
	TestName_GetLastName();
	TestName_SetLastName();
	TestName_ToString();
	TestName_ToFileString();
	TestName_ToFileString1();
}

void test::TestName_Constructor0()
{
	Name name;
	assert((name.GetFirstName() == "") && (name.GetLastName() == ""));
}

void test::TestName_Constructor1()
{
	Name name("foo");
	assert((name.GetFirstName() == "foo") && (name.GetLastName() == ""));
}

void test::TestName_Constructor2()
{
	Name name("foo", "bar");
	assert((name.GetFirstName() == "foo") && (name.GetLastName() == "bar"));
}

void test::TestName_GetFirstName()
{
	Name name("foo");
	assert((name.GetFirstName() == "foo"));
}

void test::TestName_SetFirstName()
{
	Name name;
	name.SetFirstName("foo");
	assert(name.GetFirstName() == "foo");
}

void test::TestName_GetLastName()
{
	Name name("", "bar");
	assert((name.GetLastName() == "bar"));
}

void test::TestName_SetLastName()
{
	Name name;
	name.SetLastName("bar");
	assert(name.GetLastName() == "bar");
}

void test::TestName_ToString()
{
	Name name("foo", "bar");
	assert(name.ToString() == "bar, foo");
}

void test::TestName_ToFileString()
{
	Name name("foo", "bar");
	assert(name.ToFileString() == "foo,bar");
}
void test::TestName_ToFileString1()
{
	Name name("foo", "bar");
	assert(name.ToFileString(' ') == "foo bar");
}