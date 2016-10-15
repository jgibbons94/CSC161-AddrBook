//Address.cpp
//Written by Jesse Gibbons
#include <iostream>
using namespace std;

#include "Address.h"
#include "AddrTest.h"
using namespace AddrBookLib;

AddrBookLib::Address::Address(const Field & initialStreetAddress, const Field & initialCity, const Field & initialState, const Field & initialZip)
{
	streetAddress = initialStreetAddress;
	city = initialCity;
	state = initialState;
	zip = initialZip;
}

Field AddrBookLib::Address::ToString() const
{
	return "\t Address:\t" + streetAddress + "\n\t         \t" + city + ", " + state + ' ' + zip+'\n';
}

Field AddrBookLib::Address::ToFileString(char delimeter) const
{
	return streetAddress + delimeter + city + delimeter + state + delimeter + zip+delimeter;
}

//return true on success, false otherwise.
void AddrBookLib::Address::ReadFromFile(std::istream & fileIn)
{
	//get input in format: street address1,city1,state1,zip1,
	//bool retVal = true;
	fileIn >> streetAddress;
	fileIn >> city;
	fileIn >> state;
	fileIn >> zip;
	//return retVal && !fileIn.fail();
}

bool AddrBookLib::operator==(const Address & addr1, const Address & addr2)
{
	return (addr1.streetAddress == addr2.streetAddress)
		&& (addr1.city == addr2.city)
		&& (addr1.state == addr2.state)
		&& (addr1.zip == addr2.zip);
}

ostream & AddrBookLib::operator<<(ostream & os, const Address & addr)
{
	if (IsStandardOstream(&os))
	{
		//os << "Address:\t" << addr.streetAddress << "\n         \t" << addr.city << ", " << addr.state << " " << addr.zip << endl;
		os << addr.ToString();
		return os;
	}
	//os << addr.streetAddress << ',' << addr.city << ',' << addr.state << ',' << addr.zip << ',';
	os << addr.ToFileString();
	return os;
}

istream & AddrBookLib::operator >> (istream & is, Address & addr)
{
	if (IsStandardIstream(&is))
	{
		cout << "\tPlease enter a street address: " << endl;
		is >> addr.streetAddress;
		cout << "\tPlease enter a city: " << endl;
		is >> addr.city;
		cout << "\tPlease enter a state: " << endl;
		is >> addr.state;
		cout << "\tPlease enter a zip code: " << endl;
		is >> addr.zip;
		return is;
	}
	addr.ReadFromFile(is);
	return is;
}
