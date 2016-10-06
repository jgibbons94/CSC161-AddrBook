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
		Contact(Name initialName = Name(), Address initialAddress = Address(), std::string initialPhone = "", std::string initialEmail = "", std::string initialBirthday = "", std::string initialPictureFile = "");

		//Get methods:
		Name GetFullName() const { return fullName; }
		Address GetFullAddress() const { return fullAddress; }
		std::string GetPhone() const { return phone; }
		std::string GetEmail() const { return email; }
		std::string GetBirthday() const { return birthday; }
		std::string GetPictureFile() const { return pictureFile; }

		//Set methods:
		void SetFullName(Name newName) { fullName = newName; }
		void SetFullAddress(Address newAddress) { fullAddress = newAddress; }
		void SetPhone(std::string newPhone) { phone = newPhone; }
		void SetEmail(std::string newEmail) { email = newEmail; }
		void SetBirthday(std::string newBirthday) { birthday = newBirthday; }
		void SetPictureFile(std::string newPicFile) { pictureFile = newPicFile; }

		//Member functions:
		//out
		std::string ToString() const;
		std::string ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');

	protected:
		Name fullName;
		Address fullAddress;
		std::string phone;
		std::string email;
		std::string birthday;
		std::string pictureFile;
	};

}
#endif