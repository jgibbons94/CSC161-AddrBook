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

void AddrBookLib::CategorizedContact::ReadFromFile(std::istream & fileIn)
{
	//bool retVal = true;
	fileIn >> category;
	Contact::ReadFromFile(fileIn);
	//return retVal;
}

istream & AddrBookLib::operator >> (istream & is, CategorizedContact & contact)
{
	if (IsStandardIstream(&is))
	{
		contact.category = GetCategoryFromUser(false, "Other",is);

		Contact * c = &contact;
		is >> *c;
		return is;
	}
	contact.ReadFromFile(is);
	return is;
	//is >> contact.category;
}

ostream & AddrBookLib::operator<<(ostream & os, const CategorizedContact & contact)
{
	if (IsStandardOstream(&os))
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
