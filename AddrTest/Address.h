//Address.h
//Written by Jesse Gibbons
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
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
		Address(std::string initialStreetAddress = "", std::string initialCity = "", std::string initialState = "", std::string initialZip = "");

		//Get methods:
		std::string GetStreetAddress() const { return streetAddress; }
		std::string GetCity() const { return city; }
		std::string GetState() const { return state; }
		std::string GetZip() const { return zip; }

		//Set methods:
		void SetStreetAddress(std::string newStreetAddress) { streetAddress = newStreetAddress; }
		void SetCity(std::string newCity) { city = newCity; }
		void SetState(std::string newState) { state = newState; }
		void SetZip(std::string newZip) { zip = newZip; }

		//Member functions:
		std::string ToString() const;
		std::string ToFileString(char delimeter = ',') const;
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	private:
		std::string streetAddress;
		std::string city;
		std::string state;
		std::string zip;
	};

}
#endif