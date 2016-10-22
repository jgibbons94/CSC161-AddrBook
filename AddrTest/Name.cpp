//Name.cpp
//Written by Jesse Gibbons
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "Name.h"
#include "Field.h"
#include "AddrTest.h"
using namespace AddrBookLib;

Name::Name(const Field &  initialFirstName, const Field & initialLastName)
{
	firstName = initialFirstName;
	lastName = initialLastName;
}

Field Name::ToString() const
{
	return "\t    Name:\t" + lastName + ", " + firstName + '\n';
}

Field Name::ToFileString(char delimeter) const
{
	return firstName + delimeter + lastName + delimeter;
}

void AddrBookLib::Name::ReadFromFile(std::istream & fileIn)
{
	fileIn >> firstName;
	fileIn >> lastName;
}

bool AddrBookLib::operator==(const Name & a, const Name & b)
{
	return (a.firstName == b.firstName) && (a.lastName == b.lastName);
}

bool AddrBookLib::operator!=(const Name & a, const Name & b)
{
	return !(a == b);
}

bool AddrBookLib::operator>(const Name & a, const Name & b)
{
	Field fieldA = a.lastName.ToUpper() + " " + a.firstName.ToUpper();
	Field fieldB = b.lastName.ToUpper() + " " + b.firstName.ToUpper();
	return (a.lastName > b.lastName);
}

bool AddrBookLib::operator>=(const Name & a, const Name & b)
{
	return (a > b) || (a == b);
}

bool AddrBookLib::operator<(const Name & a, const Name & b)
{
	return !(a >= b);
}

bool AddrBookLib::operator<=(const Name & a, const Name & b)
{
	return !(a > b);
}

istream & AddrBookLib::operator>>(istream & is, Name & name)
{
	if (IsStandardIstream(&is))
	{
		cout << "\tPlease enter a first name: ";
		is >> name.firstName;
		cout << "\tPlease enter a last name: ";
		is >> name.lastName;
		return is;
	}
	is >> name.firstName;
	is >> name.lastName;
	return is;
}

std::ostream & AddrBookLib::operator<<(ostream & os, const Name & name)
{
	if (IsStandardOstream(&os))
	{
		os << name.ToString();
		return os;
	}
	os << name.ToFileString();
	return os;
}
