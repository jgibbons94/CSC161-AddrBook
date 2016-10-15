//CategorizedContact.cpp
//Created by Jesse Gibbons
#include <iostream>
using namespace std;
#include "Field.h"
#include "CategorizedContact.h"
#include "AddrTest.h"
using namespace AddrBookLib;

AddrBookLib::CategorizedContact::CategorizedContact(const Contact & initialContact, const Field & initialCategory) :Contact(initialContact)
{
	category = initialCategory;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToString() const
{
	Field ret  = "\t Category:\t" + category + '\n';
	      ret += "\t    Name :\t" + fullName.ToString() + '\n';
	      ret += fullAddress.ToString() + '\n';
	      ret += "\t   Phone :\t" + phone + '\n';
          ret += "\t   Email :\t" + email + '\n';
          ret += "\tBirthday :\t" + birthday + '\n';
          ret += "\tPictFile :\t" + pictureFile + '\n';
	return ret;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToFileString(char delimeter) const
{
	return category + delimeter + Contact::ToFileString(delimeter);
}

bool AddrBookLib::CategorizedContact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	fileIn >> category;
	retVal &= Contact::ReadFromFile(fileIn, delimeter);
	return retVal;
}

istream & AddrBookLib::operator >> (istream & is, CategorizedContact & contact)
{
	if (&is == _Ptr_cin)

		contact.category = GetCategoryFromUser(false, is);

	else
		is >> contact.category;
		Contact * c = &contact;
		is >> *c;
		return is;
}

ostream & AddrBookLib::operator<<(ostream & os, const CategorizedContact & contact)
{
	if (&os == _Ptr_cout)
	{
		os<< "Category:\t" << contact.category << endl;
		os << (Contact)(contact);
		return os;
	}
	os <<	contact.category << ',' << (Contact)(contact);
	return os;
}
