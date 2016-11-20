//AddressTests.cpp
//Created by Jesse Gibbons

#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;
#include "Tests.h"
#include "AddressTests.h"
#include "Address.h"
using namespace AddrBookLib;
#include "ComparisonTests.h"

void test::TestAddress()
{
	AnnounceTests("Address");
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
	TestAddress_AllComparison();
}

void test::TestAddress_Constructor0()
{
	AnnounceTests("Address Constructor 0");
	Address addr;
	assert((addr.GetStreetAddress() == "") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor1()
{
	AnnounceTests("Address Constructor 1");
	Address addr("Street");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor2()
{
	AnnounceTests("Address Constructor 2");
	Address addr("Street", "City");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor3()
{
	AnnounceTests("Address Constructor 3");
	Address addr("Street", "City", "State");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor4()
{
	AnnounceTests("Address Constructor 4");
	Address addr("Street", "City", "State", "Zip");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == "Zip"));
}

void test::TestAddress_GetStreetAddress()
{
	AnnounceTests("Address Get Street Address");
	Address addr("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_SetStreetAddress()
{
	AnnounceTests("Address Set Street Address");
	Address addr;
	addr.SetStreetAddress("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_GetCity()
{
	AnnounceTests("Address Get City");
	Address addr("", "City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_SetCity()
{
	AnnounceTests("Address Set City");
	Address addr;
	addr.SetCity("City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_GetState()
{
	AnnounceTests("Address Get State");
	Address addr("", "", "State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_SetState()
{
	AnnounceTests("Address Set");
	Address addr;
	addr.SetState("State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_GetZip()
{
	AnnounceTests("Address Get Zip");
	Address addr("", "", "", "Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_SetZip()
{
	AnnounceTests("Address Set Zip");
	Address addr;
	addr.SetZip("Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_ToString()
{
	AnnounceTests("Address ToString");
	Address addr("1", "2", "3", "4");
	Field expected = "\t Address:\t1\n\t         \t2, 3 4\n";
	Field actual = addr.ToString();
	assert(expected == actual);
}

void test::TestAddress_ToFileString()
{
	AnnounceTests("Address To File String");
	Field expected = "1,2,3,4,";
	Address addr("1", "2", "3", "4");
	Field actual = addr.ToFileString();
	assert(expected == actual);
}

void test::TestAddress_ToFileString1()
{
	AnnounceTests("Address To File String 1");
	Field expected = "1 2 3 4 ";
	Address addr("1", "2", "3", "4");
	Field actual = addr.ToFileString(' ');
	assert(expected == actual);
}

void test::TestAddress_ToCout()
{
	AnnounceTests("Address To Cout");
	//setup
	//In theory we should be able to change cout by changing _Ptr_cout.
	//Keep a temporary pointer to the old cout.
	ostream* tmpCout = _Ptr_cout;
	//set the current pointer to a new ostringStream
	ostringstream * strOut = new ostringstream();
	_Ptr_cout = strOut;
	//set up what we will test
	Field actual;
	Field expected = "\t Address:\tNumber 4 Privet Drive\n\t         \tLittle Winging, England UK-50968\n";
	Address addr("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
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
{
	AnnounceTests("Address To Ostream");
	//setup

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

	AnnounceTests("Address From Cin");
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
	AnnounceTests("Address From Istream");
	//setup
	istringstream in("Number 4 Privet Drive,Little Winging,England,UK-50968");
	Address expected("Number 4 Privet Drive", "Little Winging", "England", "UK-50968");
	Address actual;
	//act
	in >> actual;
	assert(expected == actual);
}

void test::TestAddress_AllComparison()
{
	AnnounceTests("Address From Comparison");
	Address a("321 Kaboom pkwy", "Middleton", "Nowhere", "00666"),
		b("8910 herewecome st", "here", "there", "12321"),
		c("The Burrow", "somewhere", "England", "UK-7678346");
	RunAllEqTests(a, b, c);
}
