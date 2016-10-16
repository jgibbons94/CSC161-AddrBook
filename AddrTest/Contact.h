//Contact.h
//Written by Jesse Gibbons
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <fstream>
#include "Name.h"
#include "Address.h"
namespace AddrBookLib
{
	/*
		Contact class
		File names: Contact.(h and cpp)
		Data members: fullName as Name object, fullAddress as Address object, phone as Field, email as Field, birthday as Field and pictureFile as Field
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: Field ToString();
		ToFileString member function formatted for file: Field ToFileString();
		Implemented with a unique macro guard
		Overloaded logical operators
		Overloaded insertion operator (ostream <<)
		Overloaded extraction operator (istream >>)
	*/
	class Contact
	{
	public:

		//constructor:
		Contact(const Name & initialName = Name(), const Address & initialAddress = Address(), const Field & initialPhone = "", const Field & initialEmail = "", const Field & initialBirthday = "", const Field & initialPictureFile = "");

		//Get methods:
		Name GetFullName() const { return fullName; }
		Address GetFullAddress() const { return fullAddress; }
		Field GetPhone() const { return phone; }
		Field GetEmail() const { return email; }
		Field GetBirthday() const { return birthday; }
		Field GetPictureFile() const { return pictureFile; }

		//Set methods:
		void SetFullName(const Name & newName) { fullName = newName; }
		void SetFullAddress(const Address & newAddress) { fullAddress = newAddress; }
		void SetPhone(const Field & newPhone) { phone = newPhone; }
		void SetEmail(const Field & newEmail) { email = newEmail; }
		void SetBirthday(const Field & newBirthday) { birthday = newBirthday; }
		void SetPictureFile(const Field & newPicFile) { pictureFile = newPicFile; }

		//Member functions:

		//out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;

		//in
		void ReadFromFile(std::istream & fileIn);
		// precondition: fileIn is a valid ifstream
		// postcondition: the fields of this contact object are read from a file.
		// returns false if the ifstream is not valid by the end of the function
		// returns true otherwise


		//operator overloads
		friend bool operator==(const Contact & a, const Contact & b);
		friend bool operator!=(const Contact & a, const Contact & b);
		friend bool operator>(const Contact & a, const Contact & b);
		friend bool operator>=(const Contact & a, const Contact & b);
		friend bool operator<(const Contact & a, const Contact & b);
		friend bool operator<=(const Contact & a, const Contact & b);
		friend istream& operator>> (istream & is, Contact & contact);
		friend ostream& operator<<(ostream& os, const Contact & contact);

	protected:
		Name fullName;
		Address fullAddress;
		Field phone;
		Field email;
		Field birthday;
		Field pictureFile;
	};

}
#endif
