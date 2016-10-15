//CategorizedContact.h
//Written by Jesse Gibbons
#ifndef CATEGORIZED_CONTACT_H
#define CATEGORIZED_CONTACT_H
#include <string>
#include "Contact.h"
namespace AddrBookLib
{
	/*
		CategprozedContact class
		File names: CategorizedContact.(h and cpp)
		Public Single Inheritance with Contact
		Data member: category as Field
		Private data and public get and set member functions
		Default constructors and constructors that take parameters
		ToString member function formatted for output window: string ToString();
		ToFileString member function formatted for file: string ToFileString();
		Implemented with a unique macro guard
	*/
	class CategorizedContact :public Contact
	{
	public:
		//constructor:
		CategorizedContact(const Contact & initialContact = Contact(), const Field & initialCategory = "");

		//Get methods
		Field GetCategory() const { return category; }

		//Set methods
		void SetCategory(const Field & newCategory) { category = newCategory; }

		//Member functions:
		//out
		Field ToString() const;
		Field ToFileString(char delimeter = ',') const;
		//in
		void ReadFromFile(std::istream & fileIn);
		// precondition: fileIn is a valid ifstream
		// postcondition: the fields of this contact object are read from a file.
		// returns false if the ifstream is not valid by the end of the function
		// returns true otherwise
		friend istream& operator>> (istream& is, CategorizedContact& contact);
		friend ostream& operator<< (ostream& os, const CategorizedContact& contact);

	private:
		Field category;
	};
}


#endif
