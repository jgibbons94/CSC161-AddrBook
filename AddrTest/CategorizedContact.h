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
		CategorizedContact(Contact initialContact = Contact(), std::string initialCategory = "");

		//Get methods
		std::string GetCategory() const { return category; }

		//Set methods
		void SetCategory(std::string newCategory) { category = newCategory; }

		//Member functions:
		//out
		std::string ToString() const;
		std::string ToFileString(char delimeter = ',') const;
		//in
		void ConsoleInput();
		bool ReadFromFile(std::ifstream & fileIn, char delimeter = ',');
	private:
		std::string category;
	};
}


#endif