//Address.cpp
//Written by Jesse Gibbons
#include <iostream>
using namespace std;

#include "Address.h"
#include "MyFuncs.h"
using namespace AddrBookLib;

AddrBookLib::Address::Address(Field initialStreetAddress, Field initialCity, Field initialState, Field initialZip)
{
	streetAddress = initialStreetAddress;
	city = initialCity;
	state = initialState;
	zip = initialZip;
}

Field AddrBookLib::Address::ToString() const
{
	return streetAddress + '\n' + city + ", " + state + ' ' + zip;
}

Field AddrBookLib::Address::ToFileString(char delimeter) const
{
	return streetAddress + delimeter + city + delimeter + state + delimeter + zip;
}

void AddrBookLib::Address::ConsoleInput()
{
	streetAddress = Prompt("Please enter a street address: ");
	city = Prompt("Please enter a city: ");
	state = Prompt("Please enter a state: ");
	zip = Prompt("Please enter a zip code: ");
}

//return true on success, false otherwise.
bool AddrBookLib::Address::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	//get input in format: street address1,city1,state1,zip1,
	bool retVal = true;
	Field tmpField;
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetStreetAddress(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetCity(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetState(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetZip(tmpField);
	return retVal;
}
