//Field.cpp
//Created by Jesse Gibbons
#include "Field.h"
#include <fstream>
using namespace std;
AddrBookLib::Field::Field(const char * str) : string(str)
{
}

AddrBookLib::Field::Field(const std::string & str) : string(str)
{
}

AddrBookLib::Field AddrBookLib::Field::ToUpper() const
{
	Field value(data());
	for (int i = 0; i < value.size();i++)
	{
		value[i] = toupper(value[i]);
	}
	return value;
}

AddrBookLib::Field AddrBookLib::Field::ToLower() const
{
	Field value(data());
	for (int i = 0; i < value.size();i++)
	{
		value[i] = tolower(value[i]);
	}
	return value;
}

std::istream & AddrBookLib::operator >> (std::istream & is, Field & field)
{
	if (&is == _Ptr_cin)
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

/*std::ifstream & AddrBookLib::operator >> (std::ifstream & ifs, Field & field)
{
	if (ifs.peek() == '\n')
		ifs.ignore();
	getline(ifs, field, ',');
	return ifs;
}*/
