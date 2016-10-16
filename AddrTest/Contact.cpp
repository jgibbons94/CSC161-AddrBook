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

Field AddrBookLib::Contact::ToString() const
{
	return fullName.ToString()
		+ fullAddress.ToString()
		+ "\t   Phone:\t"+phone + '\n'
		+ "\t   Email:\t"+ email + '\n'
		+ "\tBirthday:\t"+birthday + '\n'
		+ "\tPictFile:\t"+pictureFile + '\n';
}

Field AddrBookLib::Contact::ToFileString(char delimeter) const
{
	return fullName.ToFileString(delimeter)
		+ fullAddress.ToFileString(delimeter)
		+ phone + delimeter
		+ email + delimeter
		+ birthday + delimeter
		+ pictureFile + delimeter;
}

void AddrBookLib::Contact::ReadFromFile(std::istream & fileIn)
{
	fullName.ReadFromFile(fileIn);
	fullAddress.ReadFromFile(fileIn);
	fileIn >> phone;
	fileIn >> email;
	fileIn >> birthday;
	fileIn >> pictureFile;
}

bool AddrBookLib::operator==(const Contact & a, const Contact & b)
{
	return (a.fullName == b.fullName);
}

bool AddrBookLib::operator!=(const Contact & a, const Contact & b)
{
	return !(a == b);
}

bool AddrBookLib::operator>(const Contact & a, const Contact & b)
{
	return (a.fullName > b.fullName);
}

bool AddrBookLib::operator>=(const Contact & a, const Contact & b)
{
	return (a > b) || (a == b);
}

bool AddrBookLib::operator<(const Contact & a, const Contact & b)
{
	return (b > a);
}

bool AddrBookLib::operator<=(const Contact & a, const Contact & b)
{
	return (a < b) || (a == b);
}

istream & AddrBookLib::operator >> (istream & is, Contact & contact)
{
	if (IsStandardIstream(&is))
	{
		is >> contact.fullName;
		is >> contact.fullAddress;
		cout << "\tPlease enter a phone number: ";
		is >> contact.phone;
		cout << "\tPlease enter an email address: ";
		is >> contact.email;
		cout << "\tPlease enter a birthday: ";
		is >> contact.birthday;
		cout << "\tPlease enter a picture file: ";
		is >> contact.pictureFile;
		return is;
	}
	contact.ReadFromFile(is);
	return is;
}

ostream & AddrBookLib::operator<<(ostream & os, const Contact & contact)
{
	if (IsStandardOstream(&os))
	{
		os << contact.ToString();
		return os;
	}
	os << contact.ToFileString();
	return os;
}
