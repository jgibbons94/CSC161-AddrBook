#include <iostream>
using namespace std;
#include "Field.h"
#include "CategorizedContact.h"
#include "MyFuncs.h"
using namespace AddrBookLib;

AddrBookLib::CategorizedContact::CategorizedContact(Contact initialContact, Field initialCategory):Contact(initialContact)
{
	category = initialCategory;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToString(const Field & prefix) const
{
	Field ret = prefix + "Category:\t" + category + '\n';
	ret += prefix + prefix + "Name:\t" + fullName.ToString() + '\n';
	ret += prefix + prefix + "Address:\t" + fullAddress.ToString(prefix + '\t') + '\n';
	ret += prefix + prefix + "Phone:\t" + phone + '\n';
	ret += prefix + prefix + "Email:\t" + email + '\n';
	ret += prefix + prefix + "Birthday:\t" + birthday + '\n';
	ret += prefix + prefix + "PictFile:\t" + pictureFile + '\n';
	return ret;
}

AddrBookLib::Field AddrBookLib::CategorizedContact::ToFileString(char delimeter) const
{
	return category + ',' + Contact::ToFileString(delimeter);
}

void AddrBookLib::CategorizedContact::ConsoleInput()
{
	//Scott's UI will likely override this function.
	//yep, it does.
	"You lost the game";
	cerr << "Unimplemented function: CategorizedContact::ConsoleInput()" << endl;;
	for (int i = 0; i < 256; i++)
		cerr << (char)(rand());
	cout << "\t****************************************************************" << endl;
	cout << "\t*                Please enter a category                       *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t*   (a)  Work                                                  *" << endl;
	cout << "\t*   (b)  Family                                                *" << endl;
	cout << "\t*   (c)  Friends                                               *" << endl;
	cout << "\t*   (d)  Other                                                 *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\n\tPlease enter your selection: ";
	cin >> category;
	Contact::ConsoleInput();
}

bool AddrBookLib::CategorizedContact::ReadFromFile(std::ifstream & fileIn, char delimeter)
{
	bool retVal = true;
	//Field tmpField;
	fileIn >> category;
	/*
	retVal &= GetField(fileIn, tmpField, delimeter);
	SetCategory(tmpField);
	*/
	retVal &= Contact::ReadFromFile(fileIn, delimeter);
	return retVal;
}


