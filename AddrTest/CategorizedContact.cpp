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

AddrBookLib::Field AddrBookLib::CategorizedContact::ToString(const Field & prefix) const
{
	Field ret = prefix + "Category:\t" + category + '\n';
	ret += prefix + prefix + "Name:\t\t" + fullName.ToString() + '\n';
	ret += prefix + prefix + "Address:\t" + fullAddress.ToString(prefix + '\t') + '\n';
	ret += prefix + prefix + "Phone:\t\t" + phone + '\n';
	ret += prefix + prefix + "Email:\t\t" + email + '\n';
	ret += prefix + prefix + "Birthday:\t" + birthday + '\n';
	ret += prefix + prefix + "PictFile:\t" + pictureFile + '\n';
	return ret;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToFileString(char delimeter) const
{
	return category + ',' + Contact::ToFileString(delimeter);
}

bool AddrBookLib::CategorizedContact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	fileIn >> category;
	retVal &= Contact::ReadFromFile(fileIn, delimeter);
	return retVal;
}
