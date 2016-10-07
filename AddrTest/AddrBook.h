//AddrBook.h
//Written by Jesse Gibbons
#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H
#include <string>
#include "CategorizedContact.h"
#define MAX_ADDRBOOK_SIZE (5)
namespace AddrBookLib
{
	/*
		Design and implement the AddrBook data structure class (collection class)
		A bag collection of Contact objects that uses a static array as the underlying data structure (set to fixed size of 5).
		Required member functions:
		void AddContact(Contact itemToAdd);
		void RemoveContact(Contact itemToRemove);
		int FindContact(Contact itemToFind);
		void RemoveContactByIndex(int indexToRemove);
		void PrintAllContacts();
		int GetUsed();
		void ReadFile(string fileName);
		void WriteFile(string fileName);
	*/
	class AddrBook
	{
	public:
		AddrBook();
		// no Set methods
		// Get methods
		int GetUsed() const { return used; }
		// Member functions
		void AddItem(CategorizedContact itemToAdd);
		void RemoveItem(CategorizedContact itemToRemove);
		int FindItem(CategorizedContact itemToFind) const;
		void RemoveByIndex(int indexToRemove);

		CategorizedContact GetItem(int index) const;
		//console I/O
		void PrintAllItems() const;
		void PrintByCategory(Field category) const;
		//not necessarily required, but used in this program
		void AddContactFromCommandPrompt();

		// File I/O
		void ReadFile(string fileName);
		void WriteFile(string fileName) const;

	private:
		int used;
		CategorizedContact contacts[MAX_ADDRBOOK_SIZE];
	};

}
#endif