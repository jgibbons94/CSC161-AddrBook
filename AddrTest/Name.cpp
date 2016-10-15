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

istream & AddrBookLib::operator >> (istream & is, Name & name)
{
	// TODO: insert return statement here
	if (&is == _Ptr_cin)
	{
		cout << "Please enter a first name: " << endl;
		is >> name.firstName;
		cout << "Pleae enter a last name: " << endl;
		is >> name.lastName;
		return is;
	}
	is >> name.lastName;
	is >> name.firstName;
	return is;
}

std::ostream & AddrBookLib::operator<<(ostream & os, const Name & name)
{
	// TODO: insert return statement here
	if (&os == _Ptr_cout)
	{
		os <<"Name:\t" << name.lastName << ", " << name.firstName<<endl;
		return os;
	}
	os << name.firstName << ',' << name.lastName << ',';
	return os;
}


