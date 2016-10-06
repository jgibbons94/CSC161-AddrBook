#include <iostream>
using namespace std;
#include "CategorizedContact.h"
#include "MyFuncs.h"

AddrBookLib::CategorizedContact::CategorizedContact(Contact initialContact, std::string initialCategory):Contact(initialContact)
{
	category = initialCategory;
}

std::string AddrBookLib::CategorizedContact::ToString() const
{
	string ret = "Category: " + category + '\n';
	ret += "Name: " + fullName.ToString() + '\n';
	ret += "Address: " + fullAddress.ToString() + '\n';
	ret += "Phone: " + phone + '\n';
	ret += "Email: " + email + '\n';
	ret += "Birthday: " + birthday + '\n';
	ret += "PictFile: " + pictureFile + '\n';
	return ret;
}

std::string AddrBookLib::CategorizedContact::ToFileString(char delimeter) const
{
	return category + ',' + Contact::ToFileString(delimeter);
}

void AddrBookLib::CategorizedContact::ConsoleInput()
{
	//Scott's UI will likely override this function.
	cerr << "Unimplemented function: CategorizedContact::ConsoleInput()" << endl;;
	for (int i = 0; i < 256; i++)
		cerr << (char)(rand());
}

bool AddrBookLib::CategorizedContact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	string tmpField;

	retVal &= GetField(fileIn, tmpField, delimeter);
	SetCategory(tmpField);
	retVal &= Contact::ReadFromFile(fileIn, delimeter);
	return retVal;
}


