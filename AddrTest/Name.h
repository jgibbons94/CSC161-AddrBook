//Name.h
//Written by Jesse Gibbons
#ifndef NAME_H
#define NAME_H
#include <string>
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
		Name(std::string initialFirstName = "", std::string initialLastName = "");
		//	get methods
		std::string GetFirstName() const { return firstName; }
		std::string GetLastName() const { return lastName; }
		//	set methods:
		void SetFirstName(std::string newFirstName) { firstName = newFirstName; }
		void SetLastName(std::string newLastName) { lastName = newLastName; }

		// member functions:
		// out
		std::string ToString() const;
		std::string ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	private:
		std::string firstName;
		std::string lastName;
	};

}
#endif