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
		Data members: streetAddress as Field, city as Field, state as Field and zip as Field
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: Field ToString();
		ToFileString member function formatted for file: Field ToFileString();
		Implemented with a unique macro guard
*/
	class Address
	{
	public:

		//constructor:
		Address(const Field & initialStreetAddress = "", const Field & initialCity = "", const Field & initialState = "", const Field & initialZip = "");

		//Get methods:
		Field GetStreetAddress() const { return streetAddress; }
		Field GetCity() const { return city; }
		Field GetState() const { return state; }
		Field GetZip() const { return zip; }

		//Set methods:
		void SetStreetAddress(const Field & newStreetAddress) { streetAddress = newStreetAddress; }
		void SetCity(const Field & newCity) { city = newCity; }
		void SetState(const Field & newState) { state = newState; }
		void SetZip(const Field & newZip) { zip = newZip; }

		//Member functions:

		//out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;

		//in
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');
		// precondition: fileIn is a valid ifstream
		// postcondition: the fields of this contact object are read from a file.
		// returns false if the ifstream is not valid by the end of the function
		// returns true otherwise

	private:
		Field streetAddress;
		Field city;
		Field state;
		Field zip;
	};

}
#endif
