//ContactTests.cpp
//Created by Jesse Gibbons

#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

#include "Contact.h"
using namespace AddrBookLib;

#include "ContactTests.h"
#include "ComparisonTests.h"
#include "Tests.h"


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
	TestContact_ToCout();
	TestContact_ToOstream();
	TestContact_FromCin();
	TestContact_FromIstream();
	TestContact_AllComparison();

}

void test::TestContact_Constructor0()
{
	AnnounceTests("Contact Constructor 0");
	Contact contact;
	assert(
		(contact.GetFullName().GetFirstName() == "") && (contact.GetFullName().GetLastName() == "")
		&& (contact.GetFullAddress().GetStreetAddress() == "") && (contact.GetFullAddress().GetCity() == "") && (contact.GetFullAddress().GetState() == "") && (contact.GetFullAddress().GetZip() == "")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor1()
{
	AnnounceTests("Contact Constructor 1");
	Contact contact(Name("1", "2"));
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "") && (contact.GetFullAddress().GetCity() == "") && (contact.GetFullAddress().GetState() == "") && (contact.GetFullAddress().GetZip() == "")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor2()
{
	AnnounceTests("Contact Constructor 2");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"));
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor3()
{
	AnnounceTests("Contact Constructor 3");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor4()
{
	AnnounceTests("Contact Constructor 4");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor5()
{
	AnnounceTests("Contact Constructor 5");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "9") && (contact.GetPictureFile() == ""));
}

void test::TestContact_Constructor6()
{
	AnnounceTests("Contact Constructor 6");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	assert(
		(contact.GetFullName().GetFirstName() == "1") && (contact.GetFullName().GetLastName() == "2")
		&& (contact.GetFullAddress().GetStreetAddress() == "3") && (contact.GetFullAddress().GetCity() == "4") && (contact.GetFullAddress().GetState() == "5") && (contact.GetFullAddress().GetZip() == "6")
		&& (contact.GetPhone() == "7") && (contact.GetEmail() == "8") && (contact.GetBirthday() == "9") && (contact.GetPictureFile() == "10"));
}

void test::TestContact_GetFullName()
{
	AnnounceTests("Contact Get Full Name");
	Contact contact(Name("hello", "world"));
	assert((contact.GetFullName().GetFirstName() == "hello") && (contact.GetFullName().GetLastName() == "world"));
}

void test::TestContact_SetFullName()
{
	AnnounceTests("Contact Set Full Name");
	Contact contact;
	contact.SetFullName(Name("hello", "world"));
	assert((contact.GetFullName().GetFirstName() == "hello") && (contact.GetFullName().GetLastName() == "world"));
}

void test::TestContact_GetFullAddress()
{
	AnnounceTests("Contact Get Full Address");
	Contact contact(Name(), Address("1", "2", "3", "4"));
	assert((contact.GetFullAddress().GetStreetAddress() == "1") && (contact.GetFullAddress().GetCity() == "2") && (contact.GetFullAddress().GetState() == "3") && (contact.GetFullAddress().GetZip() == "4"));
}

void test::TestContact_SetFullAddress()
{
	AnnounceTests("Contact Set Full Address");
	Contact contact;
	contact.SetFullAddress(Address("1", "2", "3", "4"));
	assert((contact.GetFullAddress().GetStreetAddress() == "1") && (contact.GetFullAddress().GetCity() == "2") && (contact.GetFullAddress().GetState() == "3") && (contact.GetFullAddress().GetZip() == "4"));
}

void test::TestContact_GetPhone()
{
	AnnounceTests("Contact Get Phone");
	Contact contact(Name(), Address(), "phone");
	assert(contact.GetPhone() == "phone");
}

void test::TestContact_SetPhone()
{
	AnnounceTests("Contact Set Phone");
	Contact contact;
	contact.SetPhone("phone");
	assert(contact.GetPhone() == "phone");
}

void test::TestContact_GetEmail()
{
	AnnounceTests("Contact Get Email");
	Contact contact(Name(), Address(), "", "email");
	assert(contact.GetEmail() == "email");
}

void test::TestContact_SetEmail()
{
	AnnounceTests("Contact Set Email");
	Contact contact;
	contact.SetEmail("email");
	assert(contact.GetEmail() == "email");
}

void test::TestContact_GetBirthday()
{
	AnnounceTests("Contact Get Birthday");
	Contact contact(Name(), Address(), "", "", "Birthday");
	assert(contact.GetBirthday() == "Birthday");
}

void test::TestContact_SetBirthday()
{
	AnnounceTests("Contact Set Birthday");
	Contact contact;
	contact.SetBirthday("birthday");
	assert(contact.GetBirthday() == "birthday");
}

void test::TestContact_GetPictureFile()
{
	AnnounceTests("Contact Get Picture File");
	Contact contact(Name(), Address(), "", "", "", "picture");
	assert(contact.GetPictureFile() == "picture");
}

void test::TestContact_SetPictureFile()
{
	AnnounceTests("Contact Set Picture File");
	Contact contact;
	contact.SetPictureFile("/dev/null");
	assert(contact.GetPictureFile() == "/dev/null");
}

void test::TestContact_ToString()
{
	AnnounceTests("Contact To String");
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field actual = contact.ToString();
	Field expected = "\t    Name:\t2, 1\n\t Address:\t3\n\t         \t4, 5 6\n\t   Phone:\t7\n\t   Email:\t8\n\tBirthday:\t9\n\tPictFile:\t10\n";
	assert(expected == actual);
}

void test::TestContact_ToFileString()
{
	AnnounceTests("Contact To File String");
	Field expected = "1,2,3,4,5,6,7,8,9,10,";
	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field actual = contact.ToFileString();
	assert(expected == actual);
}

void test::TestContact_ToFileString1()
{
	AnnounceTests("Contact To File String 1");

	Contact contact(Name("1", "2"), Address("3", "4", "5", "6"), "7", "8", "9", "10");
	Field fld = contact.ToFileString('\t');
	assert(fld == "1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t");
}

void test::TestContact_ToCout()
{

	AnnounceTests("Contact To Cout");
	//setup
	//In theory we should be able to change cout by changing _Ptr_cout.
	//Keep a temporary pointer to the old cout.
	ostream* tmpCout = _Ptr_cout;
	//set the current pointer to a new ostringStream
	ostringstream * strOut = new ostringstream();
	_Ptr_cout = strOut;
	//set up what we will test
	Field actual;
	Name name("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact contact(name, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	Field expected = "\t    Name:\tPotter, Harry\n";
	expected += "\t Address:\tNumber 4 Privet Drive\n";
	expected += "\t         \tLittle Winging, England UK-50968\n";
	expected += "\t   Phone:\t555-427-7907\n";
	expected += "\t   Email:\tHarry@rowling.jk\n";
	expected += "\tBirthday:\tJuly 31 1980\n";
	expected += "\tPictFile:\t/dev/null\n";

	//act
	//*strOut should look like std::cout.
	*strOut << contact;
	actual = strOut->str();
	//cleanup
	delete strOut;
	strOut = 0;
	_Ptr_cout = tmpCout;
	//assert
	assert(expected == actual);
}

void test::TestContact_ToOstream()
{
	AnnounceTests("Contact To Ostream");

	//setup

	ostringstream out;
	//set up what we will test
	Field actual;
	Field expected = "Harry,Potter,Number 4 Privet Drive,Little Winging,England,UK-50968,555-427-7907,Harry@rowling.jk,July 31 1980,/dev/null,";
	Name name("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact contact(name, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	//act
	out << contact;
	actual = out.str();
	//assert
	assert(expected == actual);
}

void test::TestContact_FromCin()
{

	//setup
	istream* tmpCin = _Ptr_cin;

	//set the current pointer to a new ostringStream
	istringstream * strIn = new istringstream("Harry\nPotter\nNumber 4 Privet Drive\nLittle Winging\nEngland\nUK-50968\n555-427-7907\nHarry@rowling.jk\nJuly 31 1980\n/dev/null\n");
	_Ptr_cin = strIn;



	//set up what we will test
	Name nExpected("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact expected(nExpected, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	Contact actual;
	//act

	//*strOut should look like std::cout.

	*strIn >> actual;
	//cleanup
	delete strIn;
	strIn = 0;
	_Ptr_cin = tmpCin;


	//assert
	assert(expected == actual);

}

void test::TestContact_FromIstream()
{
	AnnounceTests("Contact From Istream");
	//setup
	istringstream in("Harry,Potter,Number 4 Privet Drive,Little Winging,England,UK-50968,555-427-7907,Harry@rowling.jk,July 31 1980,/dev/null,");
	Name nExpected("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact expected(nExpected, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");

	Contact actual;
	//act
	in >> actual;
	//assert
	assert(expected == actual);
}

void test::TestContact_AllComparison()
{
	AnnounceTests("Contact Comparison");
	Name na("Alice", "Andersen"), nb("Blake", "Buster"), nc("Catherine", "Coolidge");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact a(na, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null"),
			b(nb, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null"),
			c(nc, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	RunAllInEqTests(a, b, c);
}

