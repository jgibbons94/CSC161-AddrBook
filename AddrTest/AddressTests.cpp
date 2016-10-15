#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;
#include "Tests.h"
#include "AddressTests.h"
#include "Address.h"
using namespace AddrBookLib;
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
	TestAddress_ToCout();
	TestAddress_ToOstream();
	TestAddress_FromCin();
	TestAddress_FromIstream();
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
	Field expectedField = "\tAddress :\t1\n\t       \t2, 3 4";
	Field fld = addr.ToString();
	assert(fld == expectedField);
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

void test::TestAddress_ToCout()
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
	Field expected = "Address:\tNumber 4 Privet Drive\n         \tLittle Winging, England UK-50968\n";
	Address addr("Number 4 Privet Drive","Little Winging","England","UK-50968");
	//act
	//*strOut should look like std::cout.
	*strOut << addr;
	actual = strOut->str();
	//cleanup
	delete strOut;
	strOut = 0;
	_Ptr_cout = tmpCout;
	//assert
	assert(expected == actual);
}

void test::TestAddress_ToOstream()
{	//setup

	ostringstream out;
	//set up what we will test
	Field actual;
	Field expected = "Number 4 Privet Drive,Little Winging,England,UK-50968,";
	Address addr("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	//act
	out << addr;
	actual = out.str();
	//assert
	assert(expected == actual);
}

void test::TestAddress_FromCin()
{

	//setup
	istream* tmpCin = _Ptr_cin;

	//set the current pointer to a new ostringStream
	istringstream * strIn = new istringstream("Number 4 Privet Drive\nLittle Winging\nEngland\nUK-50968");
	_Ptr_cin = strIn;



	//set up what we will test
	Address expected("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Address actual;
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

void test::TestAddress_FromIstream()
{
	//setup
	istringstream in("Number 4 Privet Drive,Little Winging,England,UK-50968");
	Address expected("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Address actual;
	//act
	in >> actual;
	//assert(expected == actual);
}
