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

Field AddrBookLib::Address::ToString(const Field & prefix) const
{
	return streetAddress + '\n' + prefix + "\t\t" + city + ", " + state + ' ' + zip;
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
