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

/*
ToString()
Member function formatted for output window.
Example:
Gibbons, Jesse
*/
string Name::ToString() const
{
	return lastName + ", " + firstName;
}

/*
ToFileString()
Member function formatted for file
Example:
Jesse,Gibbons
*/
string Name::ToFileString(char delimeter) const
{
	return firstName + delimeter + lastName;
}

/*
ConsoleInput
member function (extract from keyboard): void ConsoleInput();
Prompts for white-space delimited input from the user and stores it in the object.
Asks for the first name first, then the last name.
*/
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
