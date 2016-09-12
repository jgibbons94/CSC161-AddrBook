#ifndef NAME_H
#define NAME_H
#include <string>
namespace AddrBook
{
	/*
		Class Name
		Represents the Name in an address book.
	*/
	class Name
	{
	public:
		//	constructor
		Name(std::string initialFirstName= "", std::string initialLastName="");
		//	get methods
		std::string GetFirstName() const { return firstName; }
		std::string GetLastName() const { return lastName; }
		//	set methods:
		std::string SetFirstName(std::string newFirstName) { firstName = newFirstName; }
		std::string SetLastName(std::string newLastName) { lastName = newLastName; }

		//member functions:
		std::string ToString() const;
		std::string ToFileString() const;
		void ConsoleInput();
	private:
		std::string firstName;
		std::string lastName;
	};

}
#endif