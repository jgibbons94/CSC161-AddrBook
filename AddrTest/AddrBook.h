//AddrBook.h
//Written by Jesse Gibbons
#ifndef ADDR_BOOK_H
#define ADDR_BOOK_H
#include <string>
#include "CategorizedContact.h"
#ifndef NO_TESTS
#include "AddrBookTests.h"
#endif // !NO_TESTS

namespace AddrBookLib
{
	/*
		Design and implement the AddrBook data structure class (collection class)
		A bag collection of CategorizedContact objects that uses a static array as the underlying data structure (set to fixed size of 5).
		Required member functions:
		void AddContact(Contact itemToAdd);
		void RemoveItem(Contact itemToRemove); -- implemented as RemoveContact
		int FindItem(Contact itemToFind); -- implemented as FindContact
		void RemoveByIndex(int indexToRemove);
		void PrintAllItems(); -- implemented as PrintAllContacts
		int GetUsed();
		void ReadFile(string fileName);
		void WriteFile(string fileName);
	*/
	class AddrBook
	{
	public:

		//constructor
		AddrBook(int initialSize = 2);
		AddrBook(const AddrBook & oldAddrBook);
		~AddrBook();
		
		
		// no Set methods

		// Get methods

		int GetUsed() const { return used; }

		// Member functions

		void AddContact(const CategorizedContact & itemToAdd);

		void RemoveContact(const CategorizedContact & itemToRemove);

		int FindContact(const CategorizedContact & itemToFind) const;

		void RemoveByIndex(int indexToRemove);

		CategorizedContact GetContact(int index) const;

		//console I/O

		void PrintAllContacts() const;

		void PrintByCategory(const Field & category) const;

		// File I/O

		void ReadFile(const string & fileName);

		void WriteFile(const string & fileName) const;

		//operator overlooads
		AddrBook & operator=(const AddrBook & newAddrBook);

	private:
		//the content of the container
		CategorizedContact * content;
		//the number of content used;
		int used;
		//the allocated size of content.
		int size;
		//increase the size of content using a slow 1:1 copy
		void alloc(int sizeIncrease);
		//release the current content and set it to the safe NULL value
		void free();

		//friend functions
		#ifndef NO_TESTS
		friend void test::TestAddrBook_CopyConstructor();
		friend void test::TestAddrBook_Destructor();
		friend void test::TestAddrBook_Assignment0();
		friend void test::TestAddrBook_Assignment1();
#endif
	};

}
#endif
