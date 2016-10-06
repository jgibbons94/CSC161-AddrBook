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
		Data members: firstName as string and lastName as string
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: string ToString();
		ToFileString member function formatted for file: string ToFileString();
		<strike>ConsoleInput member function (extract from keyboard): void ConsoleInput();</strike>
		Implemented with a unique macro guard
	*/
	class Name
	{
	public:
		//	constructor
		Name(Field initialFirstName = "", Field initialLastName = "");
		//	get methods
		Field GetFirstName() const { return firstName; }
		Field GetLastName() const { return lastName; }
		//	set methods:
		void SetFirstName(Field newFirstName) { firstName = newFirstName; }
		void SetLastName(Field newLastName) { lastName = newLastName; }

		// member functions:
		// out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	private:
		Field firstName;
		Field lastName;
	};

}
#endif