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
	return "    "+fullName.ToString()
		+ " "+fullAddress.ToString()
		+ "   Phone:\t"+phone + '\n'
		+ "   Email:\t"+ email + '\n'
		+ "Birthday:\t"+birthday + '\n'
		+ "PictFile:\t"+pictureFile + '\n';
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

bool AddrBookLib::operator==(const Contact & a, const Contact & b)
{
	return (a.fullName == b.fullName)
		&& (a.fullAddress == b.fullAddress)
		&& (a.phone == b.phone)
		&& (a.email == b.email)
		&& (a.birthday == b.birthday)
		&& (a.pictureFile == b.pictureFile);
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
	is >> contact.fullName;
	is >> contact.fullAddress;
	if (&is == _Ptr_cin)
	{
		cout << "Please enter a phone number: " << endl;
		is >> contact.phone;
		cout << "Please enter an email address: " << endl;
		is >> contact.email;
		cout << "Please enter a birthday: " << endl;
		is >> contact.birthday;
		cout << "Please enter a picture file: " << endl;
		is >> contact.pictureFile;
		return is;
	}
	is >> contact.phone;
	is >> contact.email;
	is >> contact.birthday;
	is >> contact.pictureFile;
	return is;
}

ostream & AddrBookLib::operator<<(ostream & os, const Contact & contact)
{
	if (&os == _Ptr_cout)
	{
		os << contact.ToString();
		/*os << "    " << contact.fullName;
		os << " " << contact.fullAddress;
		os <<"  "<< "Number:\t" << contact.phone << endl;
		os <<"   "<<"Email:\t" << contact.email << endl;
		os << "Birthday:\t" << contact.birthday << endl;
		os << "PictFile:\t" << contact.pictureFile << endl;*/
		return os;
	}
	//os << contact.fullName << contact.fullAddress << contact.phone << ',' << contact.email << ',' << contact.birthday << ',' << contact.pictureFile << ',';
	os << contact.ToFileString();
	return os;
}
