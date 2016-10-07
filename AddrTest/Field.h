//Contact.h
//Written by Jesse Gibbons
#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <iostream>
namespace AddrBookLib
{
	/*
	Field class
		File names : Field.(h and cpp)
		Public Single Inheritance with String
		Data members : None
		Default constructor, Constructor(const char *), Constructor(string &)
		Input stream operator fpr extraction
		InFile stream operators for extraction
		Implemented with a unique macro guard
	*/
	class Field : public std::string
	{
	public:

		Field(const char* str = "");

		Field(const std::string & str);

	};

	std::istream & operator >> (std::istream & is, Field & field);
	//precondition: is is a valid istream
	//postcondition: the value in field is written to is

	std::ifstream & operator >> (std::ifstream & ifs, Field & field);
	//precondition: ifs is a valid ifstream
	//postcondition: the value in field is written to ifs
}
#endif
