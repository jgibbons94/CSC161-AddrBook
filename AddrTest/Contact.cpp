//Contact.cpp
//Written by Jesse Gibbons
#include <fstream>
using namespace std;
#include "Contact.h"
#include "AddrTest.h"
using namespace AddrBookLib;

AddrBookLib::Contact::Contact(const Name & initialName, const Address & initialAddress, const Field & initialPhone, const Field & initialEmail, const Field & initialBirthday, const Field & initialPictureFile)
{
	fullName = initialName;
	fullAddress = initialAddress;
	phone = initialPhone;
	email = initialEmail;
	birthday = initialBirthday;
	pictureFile = initialPictureFile;
}

//required but not used
Field AddrBookLib::Contact::ToString() const
{
	return fullName.ToString() + '\n'
		+ fullAddress.ToString() + '\n'
		+ phone + '\n'
		+ email + '\n'
		+ birthday + '\n'
		+ pictureFile + '\n';
}

Field AddrBookLib::Contact::ToFileString(char delimeter) const
{
	return fullName.ToFileString(delimeter) + delimeter
		+ fullAddress.ToFileString(delimeter) + delimeter
		+ phone + delimeter
		+ email + delimeter
		+ birthday + delimeter
		+ pictureFile + delimeter;
}

bool AddrBookLib::Contact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	//Using && skips the remainder of the function when retval is false. That is why it fails only once when the file has an incomplete final entry.
	retVal = retVal && fullName.ReadFromFile(fileIn, delimeter);
	retVal = retVal && fullAddress.ReadFromFile(fileIn, delimeter);
	//read the rest of the line in format: phone1, email1, bday1, picture file1,
	fileIn >> phone;
	fileIn >> email;
	fileIn >> birthday;
	fileIn >> pictureFile;
	return retVal && !fileIn.fail();
}
