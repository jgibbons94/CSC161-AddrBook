//Address.h
//Written by Jesse Gibbons
#ifndef ADDRESS_H
#define ADDRESS_H
#include"Field.h"
#include <iostream>
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
		Overloaded logical equality operators
		Overloaded insertion operator (ostream <<)
		Overloaded extraction operator (istream >>)
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
		void ReadFromFile(std::istream & fileIn);

		friend bool operator==(const Address& addr1, const Address& addr2);
		friend bool operator!=(const Address& addr1, const Address& addr2);

		// In the following, logic is applied to check if the streams are standard c++ streams defined in <iostream>
		friend ostream& operator<<(ostream& os, const Address& addr);
		friend istream& operator>>(istream& is, Address& addr);

	private:
		Field streetAddress;
		Field city;
		Field state;
		Field zip;
	};

}
#endif
