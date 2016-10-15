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
	return "\tAddress :\t" + streetAddress + "\n\t       \t" + city + ", " + state + ' ' + zip;
}

Field AddrBookLib::Address::ToFileString(char delimeter) const
{
	return streetAddress + delimeter + city + delimeter + state + delimeter + zip;
}

//return true on success, false otherwise.
bool AddrBookLib::Address::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	//get input in format: street address1,city1,state1,zip1,
	bool retVal = true;
	fileIn >> streetAddress;
	fileIn >> city;
	fileIn >> state;
	fileIn >> zip;
	return retVal && !fileIn.fail();
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
	if (&os == _Ptr_cout)
	{
		os << "Address:\t" << addr.streetAddress << "\n         \t" << addr.city << ", " << addr.state << " " << addr.zip << endl;
		return os;
	}
	os << addr.streetAddress << ',' << addr.city << ',' << addr.state << ',' << addr.zip << ',';
	return os;
}

istream & AddrBookLib::operator >> (istream & is, Address & addr)
{
	if (&is == _Ptr_cin)
	{
		cout << "Please enter a street address: " << endl;
		is >> addr.streetAddress;
		cout << "Please enter a city: " << endl;
		is >> addr.city;
		cout << "Please enter a state: " << endl;
		is >> addr.state;
		cout << "Please enter a zip code: " << endl;
		is >> addr.zip;
		return is;
	}
	is >> addr.streetAddress;
	is >> addr.city;
	is >> addr.state;
	is >> addr.zip;
	return is;
}
