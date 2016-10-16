//CategorizedContactTests.cpp
//Created by Jesse Gibbons

#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

#include "CategorizedContact.h"
using namespace AddrBookLib;
#include "Tests.h"
#include "CategorizedContactTests.h"

void test::TestCategorizedContact()
{
	TestCategorizedContact_Constructor0();
	TestCategorizedContact_Constructor1();
	TestCategorizedContact_Constructor2();
	TestCategorizedContact_GetCategory();
	TestCategorizedContact_SetCategory();
	TestCategorizedContact_ToString();
	TestCategorizedContact_ToFileString();
	TestCategorizedContact_ToFileString1();

	//operator<<

	TestCategorizedContact_ToCout();
	TestCategorizedContact_ToOstream();

	//operator>>

	TestCategorizedContact_FromCin();
	TestCategorizedContact_FromIstream();
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
	Field actual = contact.ToString();
	Field expected = "\tCategory:\tfamily\n\t    Name:\tSchneider, Julie\n\t Address:\t13300 W 6th Ave.\n\t         \tLakewood, Colorado 80228\n\t   Phone:\t303 - 914 - 6247\n\t   Email:\tjulie.schneider@rrcc.edu\n\tBirthday:\tFeb. 3\n\tPictFile:\tjulie.jpg\n";
	assert(actual == expected);
	//test::ReportMissingTest("TestCategorizedContact_ToString");
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

void test::TestCategorizedContact_ToCout()
{	
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
	CategorizedContact categorized(contact, "Other");
	Field expected = "\tCategory:\tOther\n";
	expected += "\t    Name:\tPotter, Harry\n";
	expected += "\t Address:\tNumber 4 Privet Drive\n";
	expected += "\t         \tLittle Winging, England UK-50968\n";
	expected += "\t   Phone:\t555-427-7907\n";
	expected += "\t   Email:\tHarry@rowling.jk\n";
	expected += "\tBirthday:\tJuly 31 1980\n";
	expected += "\tPictFile:\t/dev/null\n";

	//act
	//*strOut should look like std::cout.
	*strOut << categorized;
	actual = strOut->str();
	//cleanup
	delete strOut;
	strOut = 0;
	_Ptr_cout = tmpCout;
	//assert
	assert(expected == actual);
}

void test::TestCategorizedContact_ToOstream()
{
	//setup
	ostringstream out;
	
	//set up what we will test
	Field actual;
	Field expected = "Other,Harry,Potter,Number 4 Privet Drive,Little Winging,England,UK-50968,555-427-7907,Harry@rowling.jk,July 31 1980,/dev/null,";
	Name name("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact contact(name, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	CategorizedContact categorized(contact, "Other");
	//act
	out << categorized;
	actual = out.str();
	//assert
	assert(expected == actual);
}

void test::TestCategorizedContact_FromCin()
{

	//setup
	istream* tmpCin = _Ptr_cin;

	//set the current pointer to a new ostringStream
	istringstream * strIn = new istringstream("e\nHarry\nPotter\nNumber 4 Privet Drive\nLittle Winging\nEngland\nUK-50968\n555-427-7907\nHarry@rowling.jk\nJuly 31 1980\n/dev/null\n");
	_Ptr_cin = strIn;



	//set up what we will test
	Name nExpected("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact contact(nExpected, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	CategorizedContact expected(contact, "Other");
	CategorizedContact actual;
	//act

	//*strIn should look like std::cin.

	*strIn >> actual;
	//cleanup
	delete strIn;
	strIn = 0;
	_Ptr_cin = tmpCin;


	//assert
	assert(expected == actual);
}

void test::TestCategorizedContact_FromIstream()
{
	//setup
	istringstream in("Other,Harry,Potter,Number 4 Privet Drive,Little Winging,England,UK-50968,555-427-7907,Harry@rowling.jk,July 31 1980,/dev/null,");
	Name name("Harry", "Potter");
	Address address("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Contact contact(name, address, "555-427-7907", "Harry@rowling.jk", "July 31 1980", "/dev/null");
	CategorizedContact expected(contact, "Other");
	CategorizedContact actual;
	//act
	in >> actual;
	//assert
	assert(expected == actual);
}
