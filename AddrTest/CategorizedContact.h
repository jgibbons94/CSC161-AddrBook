//CategorizedContact.h
//Written by Jesse Gibbons
#ifndef CATEGORIZED_CONTACT_H
#define CATEGORIZED_CONTACT_H
#include <string>
#include "Contact.h"
namespace AddrBookLib
{
	class CategorizedContact :public Contact
	{
	public:
		//constructor:
		CategorizedContact(Contact initialContact = Contact(), Field initialCategory = "");

		//Get methods
		Field GetCategory() const { return category; }

		//Set methods
		void SetCategory(Field newCategory) { category = newCategory; }

		//Member functions:
		//out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');
	private:
		Field category;
	};
}


#endif