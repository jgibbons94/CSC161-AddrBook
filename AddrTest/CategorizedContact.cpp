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
	Field ret  = "Category:\t" + category + '\n';
	ret += Contact::ToString();
	return ret;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToFileString(char delimeter) const
{
	return category + delimeter + Contact::ToFileString(delimeter);
}

void AddrBookLib::CategorizedContact::ReadFromFile(std::ifstream & fileIn)
{
	//bool retVal = true;
	fileIn >> category;
	Contact::ReadFromFile(fileIn);
	//return retVal;
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
		/*os<< "Category:\t" << contact.category << endl;
		os << (Contact)(contact);*/
		os << contact.ToString();
		return os;
	}
	os << contact.ToFileString();
	//os <<	contact.category << ',' << (Contact)(contact);
	return os;
}
