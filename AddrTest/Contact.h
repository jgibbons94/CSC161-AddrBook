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
		Data members: fullName as Name object, fullAddress as Address object, phone as string, email as string, birthday as string and pictureFile as string
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: string ToString();
		ToFileString member function formatted for file: string ToFileString();
		ConsoleInput member function (extract from keyboard): void ConsoleInput();
		Implemented with a unique macro guard

		changes for project 2:
		The Contact class should still utilize composition so that it has a Name object and Address object. Change the access mode of the data members to protected for all data members.
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
		Field ToString(const Field & prefix) const;
		Field ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

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