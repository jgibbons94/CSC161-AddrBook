//AddrBook.h
//Written by Jesse Gibbons
#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H
#include <string>
#include "Contact.h"
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
		void AddContact(Contact itemToAdd);
		void RemoveContact(Contact itemToRemove);
		int FindContact(Contact itemToFind) const;
		void RemoveContactByIndex(int indexToRemove);
		void PrintAllContacts() const;

		// File I/O
		void ReadFile(Field fileName);
		void WriteFile(Field fileName) const;

		//not necessarily required, but used in this program
		void AddContactFromCommandPrompt();

	private:
		int used;
		Contact contacts[MAX_ADDRBOOK_SIZE];
	};

}
#endif