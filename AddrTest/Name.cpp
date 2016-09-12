#include <string>
#include <iostream>
using namespace std;
#include "Name.h"
using namespace AddrBook;

Name::Name(string initialFirstName, string initialLastName)
{
	firstName = initialFirstName;
	lastName = initialLastName;
}

/*
ToString()
Member function formatted for output window.
Example:
Gibbons, Jesse
*/
string Name::ToString() const
{
	return lastName + ", " + firstName;
}

/*
ToFileString()
Member function formatted for file
Example:
Jesse,Gibbons
*/
string Name::ToFileString() const
{
	return firstName + "," + lastName;
}

/*
ConsoleInput 
member function (extract from keyboard): void ConsoleInput();
Prompts for white-space delimited input from the user and stores it in the object.
Asks for the first name first, then the last name.
*/
void Name::ConsoleInput()
{
	cout << "Enter a first name: ";
	cin >> firstName;
	cout << "Enter a last name: ";
	cin >> lastName;
}
