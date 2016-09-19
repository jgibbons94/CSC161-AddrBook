#include "Contact.h"
using namespace AddrBook;

AddrBook::Contact::Contact(Name initialName, Address initialAddress, std::string initialPhone, std::string initialEmail, std::string initialBirthday, std::string initialPictureFile)
{
	fullName = initialName;
	fullAddress = initialAddress;
	phone = initialPhone;
	email = initialEmail;
	birthday = initialBirthday;
	pictureFile = initialPictureFile;
}

std::string AddrBook::Contact::ToString() const
{
	return fullName.ToString() + '\n'
		+ fullAddress.ToString() + '\n'
		+ phone + '\n'
		+ email + '\n'
		+ birthday + '\n'
		+ pictureFile + '\n';
}

std::string AddrBook::Contact::ToFileString(char delimeter) const
{
	return fullName.ToFileString(delimeter) + delimeter
		+ fullAddress.ToFileString(delimeter) + delimeter
		+ phone + delimeter
		+ email + delimeter
		+ birthday + delimeter
		+ pictureFile;
}

std::string AddrBook::Contact::ConsoleInput()
{
	fullName.ConsoleInput();
	fullAddress.ConsoleInput();

}
