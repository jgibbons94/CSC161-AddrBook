#include "Field.h"
#include <fstream>
using namespace std;
AddrBookLib::Field::Field(const char * str) : string(str)
{
}

AddrBookLib::Field::Field(const std::string & str) : string(str)
{
}

std::istream & AddrBookLib::operator >> (std::istream & is, Field & field)
{
	if (is.peek() == '\n')
		is.ignore();
	return getline(is, field);
}

std::ifstream & AddrBookLib::operator >> (std::ifstream & ifs, Field & field)
{
	if (ifs.peek() == '\n')
		ifs.ignore();
	getline(ifs, field, ',');
	return ifs;
}
