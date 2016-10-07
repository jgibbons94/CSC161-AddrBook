//Address.h
//Written by Jesse Gibbons
#ifndef ADDRESS_H
#define ADDRESS_H
#include"Field.h"
namespace AddrBookLib
{
	/*
		Address class
		File names: Address.(h and cpp)
		Data members: streetAddress as string, city as string, state as string and zip as string
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: string ToString();
		ToFileString member function formatted for file: string ToFileString();
		ConsoleInput member function (extract from keyboard): void ConsoleInput();
		Implemented with a unique macro guard
*/
	class Address
	{
	public:

		//constructor:
		Address(Field initialStreetAddress = "", Field initialCity = "", Field initialState = "", Field initialZip = "");

		//Get methods:
		Field GetStreetAddress() const { return streetAddress; }
		Field GetCity() const { return city; }
		Field GetState() const { return state; }
		Field GetZip() const { return zip; }

		//Set methods:
		void SetStreetAddress(Field newStreetAddress) { streetAddress = newStreetAddress; }
		void SetCity(Field newCity) { city = newCity; }
		void SetState(Field newState) { state = newState; }
		void SetZip(Field newZip) { zip = newZip; }

		//Member functions:
		//out
		Field ToString(const Field & prefix = "") const;
		Field ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	private:
		Field streetAddress;
		Field city;
		Field state;
		Field zip;
	};

}
#endif