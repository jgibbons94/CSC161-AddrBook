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
	return "\t Address:\t" + streetAddress + "\n\t         \t" + city + ", " + state + ' ' + zip + '\n';
}

Field AddrBookLib::Address::ToFileString(char delimeter) const
{
	return streetAddress + delimeter + city + delimeter + state + delimeter + zip + delimeter;
}

//return true on success, false otherwise.
void AddrBookLib::Address::ReadFromFile(std::istream & fileIn)
{
	//get input in format: street address1,city1,state1,zip1,
	fileIn >> streetAddress;
	fileIn >> city;
	fileIn >> state;
	fileIn >> zip;
}

bool AddrBookLib::operator==(const Address & addr1, const Address & addr2)
{
	return (addr1.streetAddress == addr2.streetAddress)
		&& (addr1.city == addr2.city)
		&& (addr1.state == addr2.state)
		&& (addr1.zip == addr2.zip);
}

bool AddrBookLib::operator!=(const Address & addr1, const Address & addr2)
{
	return !(addr1 == addr2);
}

ostream & AddrBookLib::operator<<(ostream & os, const Address & addr)
{
	if (IsStandardOstream(&os))
	{
		os << addr.ToString();
		return os;
	}
	os << addr.ToFileString();
	return os;
}

istream & AddrBookLib::operator >> (istream & is, Address & addr)
{
	if (IsStandardIstream(&is))
	{
		cout << "\tPlease enter a street address: ";
		is >> addr.streetAddress;
		cout << "\tPlease enter a city: ";
		is >> addr.city;
		cout << "\tPlease enter a state: ";
		is >> addr.state;
		cout << "\tPlease enter a zip code: ";
		is >> addr.zip;
		return is;
	}
	addr.ReadFromFile(is);
	return is;
}
