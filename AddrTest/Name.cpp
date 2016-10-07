//Name.cpp
//Written by Jesse Gibbons
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "Name.h"
#include "AddrTest.h"
using namespace AddrBookLib;

Name::Name(const Field &  initialFirstName, const Field & initialLastName)
{
	firstName = initialFirstName;
	lastName = initialLastName;
}

Field Name::ToString() const
{
	return lastName + ", " + firstName;
}

Field Name::ToFileString(char delimeter) const
{
	return firstName + delimeter + lastName;
}


bool AddrBookLib::Name::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	fileIn >> firstName;
	fileIn >> lastName;
	return retVal && !fileIn.fail();
}
