//Contact.cpp
//Written by Jesse Gibbons
#include <fstream>
using namespace std;
#include "Contact.h"
#include "MyFuncs.h"
using namespace AddrBookLib;

AddrBookLib::Contact::Contact(Name initialName, Address initialAddress, std::string initialPhone, std::string initialEmail, std::string initialBirthday, std::string initialPictureFile)
{
	fullName = initialName;
	fullAddress = initialAddress;
	phone = initialPhone;
	email = initialEmail;
	birthday = initialBirthday;
	pictureFile = initialPictureFile;
}

std::string AddrBookLib::Contact::ToString() const
{
	return fullName.ToString() + '\n'
		+ fullAddress.ToString() + '\n'
		+ phone + '\n'
		+ email + '\n'
		+ birthday + '\n'
		+ pictureFile + '\n';
}

std::string AddrBookLib::Contact::ToFileString(char delimeter) const
{
	return fullName.ToFileString(delimeter) + delimeter
		+ fullAddress.ToFileString(delimeter) + delimeter
		+ phone + delimeter
		+ email + delimeter
		+ birthday + delimeter
		+ pictureFile + delimeter;
}

void AddrBookLib::Contact::ConsoleInput()
{
	fullName.ConsoleInput();
	fullAddress.ConsoleInput();
	phone = Prompt("Please enter " + fullName.GetFirstName() + "'s phone number: ");
	email = Prompt("Please enter " + fullName.GetFirstName() + "'s email address: ");
	birthday = Prompt("Please enter " + fullName.GetFirstName() + "'s birthday: ");
	pictureFile = Prompt("Please enter the file location for " + fullName.GetFirstName() + "'s picture: ");
}

bool AddrBookLib::Contact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	string tmpField;
	//Using && skips the remainder of the function when retval is false. That is why it fails only once when the file has an incomplete final entry.
	retVal = retVal && fullName.ReadFromFile(fileIn, delimeter);
	retVal = retVal && fullAddress.ReadFromFile(fileIn, delimeter);
	//read the rest of the line in format: phone1, email1, bday1, picture file1,
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetPhone(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetEmail(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetBirthday(tmpField);
	retVal = retVal && GetField(fileIn, tmpField, delimeter);
	SetPictureFile(tmpField);
	return retVal;
}
