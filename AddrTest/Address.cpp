#include "Address.h"
#include <iostream>


AddrBook::Address::Address(std::string initialStreetAddress, std::string initialCity, std::string initialState, std::string initialZip)
{
	streetAddress = initialStreetAddress;
	city = initialCity;
	state = initialState;
	zip = initialZip;
}

std::string AddrBook::Address::ToString() const
{
	return streetAddress + '\n' + city + ", " + state + ' ' + zip;
}

std::string AddrBook::Address::ToFileString(char delimeter) const
{
	return streetAddress + delimeter + city + delimeter + state + delimeter + zip;
}

std::string AddrBook::Address::ConsoleInput() 
{
	using namespace std;
	cout << "Please enter a street address: ";
	cin >> streetAddress;
	cout << "Please enter a city: ";
	cin >> city;
	cout << "Please enter a state: ";
	cin >> zip;
	cout << "Please enter a zip code: ";
	cin >> zip;
	return std::string();
}
