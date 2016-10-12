#include <cassert>
using namespace std;

#include "Contact.h"
using namespace AddrBookLib;

#include "ContactTests.h"
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
