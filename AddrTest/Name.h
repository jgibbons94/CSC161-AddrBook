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
		Overloaded logical operators
		Overloaded insertion operator (ostream <<)
		Overloaded extraction operator (istream >>)
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
		void ReadFromFile(std::istream & in);

		//operator overloads
		friend bool operator==(const Name & a, const Name & b);
		friend bool operator!=(const Name & a, const Name & b);
		friend bool operator>(const Name & a, const Name & b);
		friend bool operator>=(const Name & a, const Name & b);
		friend bool operator<(const Name & a, const Name & b);
		friend bool operator<=(const Name & a, const Name & b);
		
		// In the following, logic is applied to check if the streams are standard c++ streams defined in <iostream>
		friend istream& operator>>(istream & is, Name & name);
		friend ostream& operator<<(ostream& os, const Name& name);
	private:
		Field firstName;
		Field lastName;
	};

	bool operator==(const Name & a, const Name & b);
	bool operator!=(const Name & a, const Name & b);
	bool operator>(const Name & a, const Name & b);
	bool operator>=(const Name & a, const Name & b);
	bool operator<(const Name & a, const Name & b);
	bool operator<=(const Name & a, const Name & b);
	std::istream& operator>>(istream & is, Name & name);
	std::ostream& operator<<(ostream & os, const Name & name);
}
#endif
