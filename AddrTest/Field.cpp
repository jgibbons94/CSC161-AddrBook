//Field.cpp
//Created by Jesse Gibbons
#include <fstream>
using namespace std;
#include "Field.h"
#include "AddrTest.h"
AddrBookLib::Field::Field(const char * str) : string(str)
{
}

AddrBookLib::Field::Field(const std::string & str) : string(str)
{
}

AddrBookLib::Field AddrBookLib::Field::ToUpper() const
{
	Field value(data());
	for (size_t i = 0; i < value.size();i++)
	{
		value[i] = toupper(value[i]);
	}
	return value;
}

AddrBookLib::Field AddrBookLib::Field::ToLower() const
{
	Field value(data());
	for (size_t i = 0; i < value.size();i++)
	{
		value[i] = tolower(value[i]);
	}
	return value;
}

std::istream & AddrBookLib::operator >> (std::istream & is, Field & field)
{
	if (IsStandardIstream(&is))
	{
		if (is.peek() == '\n')
			is.ignore();
		getline(is, field);
		return is;
	}
	if (is.peek() == '\n')
		is.ignore();
	getline(is, field, ',');
	return is;
}
