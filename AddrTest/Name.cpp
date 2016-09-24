//Name.cpp
//Written by Jesse Gibbons
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "Name.h"
#include "MyFuncs.h"
using namespace AddrBookLib;

Name::Name(string initialFirstName, string initialLastName)
{
	firstName = initialFirstName;
	lastName = initialLastName;
}

string Name::ToString() const
{
	return lastName + ", " + firstName;
}

string Name::ToFileString(char delimeter) const
{
	return firstName + delimeter + lastName;
}

void Name::ConsoleInput()
{
	firstName = Prompt("Enter a first name: ");
	lastName = Prompt("Enter " + firstName + "'s last name: ");
}

bool AddrBookLib::Name::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	string tmpField;
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetFirstName(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetLastName(tmpField);
	return retVal;
}
