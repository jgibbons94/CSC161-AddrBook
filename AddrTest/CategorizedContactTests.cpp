#include <cassert>
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
	Field expectedField = "\t Category:\tfamily\n\t    Name :\tSchneider, Julie\n\tAddress :\t13300 W 6th Ave.\n\t       \tLakewood, Colorado 80228\n\t   Phone :\t303 - 914 - 6247\n\t   Email :\tjulie.schneider@rrcc.edu\n\tBirthday :\tFeb. 3\n\tPictFile :\tjulie.jpg\n";
	assert(fld == expectedField);
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
