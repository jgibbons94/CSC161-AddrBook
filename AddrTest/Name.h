//Name.h
//Written by Jesse Gibbons
#ifndef NAME_H
#define NAME_H
#include "Field.h"
namespace AddrBookLib
{
	/*
		Name class
		File names: Name.(h and cpp)
		Data members: firstName as Field and lastName as Field
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: Field ToString();
		ToFileString member function formatted for file: Field ToFileString();
		Implemented with a unique macro guard
	*/
	class Name
	{
	public:
		//	constructor
		Name(const Field & initialFirstName = "", const Field & initialLastName = "");

		//	get methods
		Field GetFirstName() const { return firstName; }
		Field GetLastName() const { return lastName; }
		//	set methods:
		void SetFirstName(const Field & newFirstName) { firstName = newFirstName; }
		void SetLastName(const Field & newLastName) { lastName = newLastName; }

		// member functions:
		// out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;
		//in
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	private:
		Field firstName;
		Field lastName;
	};

}
#endif
