#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <iostream>
namespace AddrBookLib
{
	class Field : public std::string
	{
	public:
		Field(const char* str = "");
		Field(const std::string & str);
	};
	std::istream & operator>> (std::istream & is, Field & field);
	std::ifstream & operator>> (std::ifstream & ifs, Field & field);
}
#endif