//LinkList.h
//Written by Jesse Gibbons
#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include "Node.h"
#include "CategorizedContact.h"

#ifdef LINK_LIST_TEST_FRIENDS
namespace test
{
	template<class T>
	void TestLinkList_Constructor0_0();
	template<class T>
	void TestLinkList_Constructor0_1();
	template<class T>
	void TestLinkList_ConstructorFirst();
	template<class T>
	void TestLinkList_ConstructorLast();
	template<class T>
	void TestLinkList_ConstructorAsc();
	template<class T>
	void TestLinkList_ConstructorDesc();
	template<class T>
	void TestLinkList_CopyConstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Assignment(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestLinkList_RemoveByItemNumber(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveByItem(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);



	template<class T>
	void TestLinkList_AllocNode(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_FindNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_HasOnlyOneElement(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_AddAsc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_AddDesc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_AddEnd(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_AddBeginning(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Concat(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveFirst(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeNode(GeneratorCallback<T> RandomGenerator);
	template<class T>
	void TestLinkList_FreeAllNodes(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeAllNodes_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);



	//link list iterator tests
	template<class T>
	void TestLinkList_Iterator_NextWithNull();
	template<class T>
	void TestLinkList_Iterator_NextNull(GeneratorCallback<T> randomGenerator);

	template<class T>
	void TestLinkList_Iterator_NextNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_Dereference(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_boolNull();
	template<class T>
	void TestLinkList_Iterator_boolNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_notNull();
	template<class T>
	void TestLinkList_Iterator_notNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_Constructor(GeneratorCallback<T> randomGenerator);
}
#endif
namespace AddrBookLib
{
	/*
		LinkList Template Class - New Data Structure instead of AddrBook
		A LinkList is a collection data structure that is dynamic, storing Nodes.
		Only Node pointers will be created in LinkList - NO Node objects
		A LinkList has a first Node pointer and a last Node pointer
		Public Members
			Default Constructor
			Copy Constructor
			Assignment Operator
			Destructor
			Add(Type dataIn)
			RemoveByItemNumber(int itemNumber)
			RemoveByItem(Type dataToRemove)
			CountItems()
			ReadFile(string fileName)
			WriteFile(string fileName)
			PrintAll()
		Private Members
			Node* FindNode(Type dataIn)
			Node* FindPreviousNode(Type dataIn)
			RemoveFirst()
			RemoveNode(Node*)
			Node* AllocNode(Type dataIn)
			FreeAllNodes()
		Make sure all the member functions move links NOT data around when adding, removing.
		Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
	*/
	template<class T>
	class LinkList
	{
	public:
		typedef const T & crefT;
		typedef enum InsertOrder
		{
			FIRST = 0,//in goes on top
			LAST,//in goes on bottom
			ASCENDING, //sort ascending
			DESCENDING,//sort descending.
			STACK = FIRST,//in goes on top
			QUEUE = LAST,//in goes on bottom
		} LinkListInsertOrder;
		//Database operations:
		//CRUD - Create, Read, Update, Delete

		//C
		LinkList(LinkListInsertOrder initialInsertOrder = LinkListInsertOrder::LAST);
		LinkList(const LinkList<T> & oldLinkList);
		LinkList<T> & operator=(const LinkList<T> & oldLinkList);
		//R
		//Iterator is a helper class, so I'm nesting it in the LinkList class.
		class Iterator
		{
		public:
			//use this operator as though the programmer is dereferencing a pointer.
			//return node->value.
			//const to prevent manipulation.
			const T& operator*() const;
			//go to the next node.
			//return true if there is a next element in the list.
			//return false if there is not a next element in the list.
			bool Next();
			//true if value is not null.
			//use in if, while, do while, for statements
			operator bool() const;
			//short-hand check if value is null.
			//Effective for conditional checking.
			//might not be necessary with operator bool.
			bool operator!() const;
		private:
			Iterator(Node<T> * initialValue);
			Node<T>* value;

			friend class LinkList<T>;
#ifdef LINK_LIST_TEST_FRIENDS
			friend void test::TestLinkList_Iterator_NextWithNull<T>();
			friend void test::TestLinkList_Iterator_NextNull<T>(GeneratorCallback<T> randomGenerator);
			friend void test::TestLinkList_Iterator_NextNotNull<T>(GeneratorCallback<T> randomGenerator);
			friend void test::TestLinkList_Iterator_Dereference<T>(GeneratorCallback<T> randomGenerator);
			friend void test::TestLinkList_Iterator_boolNull<T>();
			friend void test::TestLinkList_Iterator_boolNotNull<T>(GeneratorCallback<T> randomGenerator);
			friend void test::TestLinkList_Iterator_notNull<T>();
			friend void test::TestLinkList_Iterator_notNotNull<T>(GeneratorCallback<T> randomGenerator);
			friend void test::TestLinkList_Iterator_Constructor<T>(GeneratorCallback<T> randomGenerator);
#endif
		};
		Iterator Begin() const;
		size_t CountItems() const;
		bool IsEmpty() const;
		//U
		void Add(crefT dataIn);
		//D
		void RemoveByItemNumber(int itemNumber);
		void RemoveByItem(crefT dataToRemove);
		~LinkList();

		//I/O
		void ReadFile(const std::string & fileName);
		void WriteFile(const std::string & fileName) const;
		void PrintAll(std::ostream & os = std::cout) const;



	private:
		//make things simpler.
		//TNode is Node<T>
		//ptrTNode is Node<T>*
		typedef Node<T> TNode, *ptrTNode;
		//CRUD - Create, Read, Update, Delete
		//C
		ptrTNode AllocNode(crefT dataIn);
		//R
		ptrTNode  FindNode(crefT dataIn) const;
		ptrTNode FindPreviousNode(crefT dataIn) const;
		bool HasOnlyOneElement() const;
		//U

		/*
			Bonus Points Opportunities:
			5 Points - Handle ascending and descending by implementing addAscending and addDescending
			The addAscending and addDescending member functions add they don't sort. You do NOT sort your list after you add at the end, you add the node in the correct position and move links around so that no sorting is necessary. Be sure to make your links work.
		*/

		//add in increasing order
		void AddAsc(crefT value);
		//add in decreasing order
		void AddDesc(crefT value);
		//add at the end of the list
		void AddEnd(crefT value);
		//add at the beginning of the list.
		void AddBeginning(crefT value);
		void InsertValueAfterSpecifiedNode(crefT value, ptrTNode beforeNode);
		//D
		void Concat(const LinkList<T> & oldLinkList);
		void RemoveFirst();
		void RemoveNode(ptrTNode nodeBefore);
		void FreeNode(ptrTNode NodeToDelete);
		void FreeAllNodes();



		ptrTNode first;
		ptrTNode last;
		//insertOrder is never changed in the AddrTest lifecycle.
		LinkListInsertOrder insertOrder;


#ifdef LINK_LIST_TEST_FRIENDS
		friend void test::TestLinkList_Constructor0_0<T>();
		friend void test::TestLinkList_Constructor0_1<T>();
		friend void test::TestLinkList_ConstructorFirst<T>();
		friend void test::TestLinkList_ConstructorLast<T>();
		friend void test::TestLinkList_ConstructorAsc<T>();
		friend void test::TestLinkList_ConstructorDesc<T>();
		friend void test::TestLinkList_CopyConstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_CopyConstructor_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_Assignment<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_Assignment_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_RemoveByItemNumber<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_RemoveByItem<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_Deconstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

		//private tests.
		friend void test::TestLinkList_AllocNode<T>(GeneratorCallback<T> RandomGenerator);
		friend void test::TestLinkList_FindNode<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_HasOnlyOneElement<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_AddAsc<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_AddDesc<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_AddEnd<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_AddBeginning<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_InsertValueAfterSpecifiedNode<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_Concat<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_RemoveFirst<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_RemoveNode<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_FreeNode<T>(GeneratorCallback<T> RandomGenerator);
		friend void test::TestLinkList_FreeAllNodes<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_FreeAllNodes_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
#endif

	};
	//This saves me the trouble of refactoring everything.
	//It's just like how std::ostream is defined as basic_ostream<char>
	//This way we can also have a wostream defined as basic_osteram<wchar>
	//typedef LinkList<CategorizedContact> AddrBook;
	template<class T>
	inline LinkList<T>::LinkList(LinkListInsertOrder initialInsertOrder)
	{
		first = nullptr;
		last = nullptr;
		this->insertOrder = initialInsertOrder;
	}
	template<class T>
	inline LinkList<T>::LinkList(const LinkList<T>& oldLinkList)
	{
		first = nullptr;
		last = nullptr;
		this->insertOrder = oldLinkList.insertOrder;
		this->Concat(oldLinkList);

	}
	template<class T>
	inline LinkList<T>&  LinkList<T>::operator=(const LinkList<T>& oldLinkList)
	{
		FreeAllNodes();
		insertOrder = oldLinkList.insertOrder;
		this->Concat(oldLinkList);
	}
	template<class T>
	inline LinkList<T>::~LinkList()
	{
		FreeAllNodes();
	}
	template<class T>
	inline void LinkList<T>::Add(crefT dataIn)
	{
		if (this->IsEmpty())
			AddBeginning(dataIn);
		else switch (this->insertOrder)
		{
		case ASCENDING:
			AddAsc(dataIn);
			break;
		case DESCENDING:
			AddDesc(dataIn);
			break;
		case LAST:
			//		case QUEUE:
			AddEnd(dataIn);
			break;
		case FIRST:
			//		case STACK:
		default:
			AddBeginning(dataIn);
			break;
		}
	}
	template<class T>
	inline void LinkList<T>::RemoveByItemNumber(int itemNumber)
	{
		int i = 1;
		ptrTNode cursor = nullptr;
		//it doesn't make sense to remove anything from an empty list
		if (this->IsEmpty())
			return;
		//The following condition must be true:
		//0 <= itemNumber < size

		//negative cardinal numbers make no sense.
		if (itemNumber < 0)
			return;
		if (itemNumber == 0)
		{
			RemoveFirst();
			return;
		}
		cursor = first;
		if (cursor == nullptr) return;
		//i is already 1
		for (; i < itemNumber; i++)
		{
			//We can do nothing after the last item in the list.
			if (cursor->next == nullptr)
				return;
			cursor = cursor->next;
		}
		if (cursor != nullptr)
			this->RemoveNode(cursor);
	}
	template<class T>
	inline void LinkList<T>::RemoveByItem(crefT dataToRemove)
	{
		ptrTNode cursor = nullptr;
		if (this->IsEmpty())
			return;
		if (first->content == dataToRemove)
		{
			RemoveFirst();
			return;
		}
		//avoid checking first again by starting with first->next.
		for (cursor = first->next; cursor != nullptr&&cursor->next != nullptr; cursor = cursor->next)
		{
			if (cursor->next->content == dataToRemove)
			{
				RemoveNode(cursor);
				return;
			}
		}
	}

	template<class T>
	typename LinkList<T>::Iterator LinkList<T>::Begin() const
	{
		return Iterator(this->first);
	}

	template<class T>
	inline size_t LinkList<T>::CountItems() const
	{
		size_t size = 0;
		ptrTNode cursor = nullptr;
		for (cursor = first;cursor != nullptr;cursor = cursor->next)
			size++;
		return size;
	}
	template<class T>
	inline void LinkList<T>::ReadFile(const std::string & fileName)
	{
		using namespace std;
		ifstream fileIn(fileName);
		T tmpItem;
		char delim = ',';
		if (!fileIn)
		{
			cerr << "Error opening file " << fileName << " to read." << endl << endl;
			fileIn.close();
			return;
		}
		fileIn >> tmpItem;
		while (!fileIn.fail())
		{
			Add(tmpItem);
			//read format fname1,lname1,street address1,city1,state1,zip1,phone1,email1,bday1,picture file1,
			fileIn >> tmpItem;
		}
		fileIn.close();
		return;
	}
	template<class T>
	inline void LinkList<T>::WriteFile(const std::string & fileName) const
	{
		using namespace std;
		ofstream outFile;
		outFile.open(fileName);
		if (!outFile)
		{
			cerr << "Error opening file for writing." << endl << endl;
			return;
		}

		// write to file

		for (ptrTNode i = first; i != nullptr; i = i->next)
		{
			outFile << i->content << endl;
		}

		outFile.close();

	}
	template<class T>
	inline void LinkList<T>::PrintAll(std::ostream & os) const
	{
		int counter = 1;
		for (ptrTNode i = first; i != nullptr; i = i->next)
		{
			os << counter++ << ": " << i->content << std::endl;
		}
	}
	template<class T>
	inline bool LinkList<T>::IsEmpty() const
	{
		//first==nullptr <==> last==nullptr unless we are adding nullptr.
		return this->first == nullptr && this->last == nullptr;
	}
	template<class T>
	inline void LinkList<T>::Concat(const LinkList<T>& oldLinkList)
	{
		if (this == &oldLinkList)
			return;

		for (ptrTNode cursor = oldLinkList.first; cursor != nullptr; cursor = cursor->next)
		{
			//if cursor is null, the entire for loop is skipped, so it's safe.
			Add(cursor->content);
		}
	}
	template<class T>
	inline Node<T>* LinkList<T>::FindNode(crefT dataIn) const
	{

		ptrTNode cursor = nullptr;
		if (this->IsEmpty())
			return nullptr;
		for (cursor = this->first;cursor != nullptr;cursor = cursor->next)
			if (cursor->content == dataIn)
				return cursor;
		return nullptr;
	}
	template<class T>
	inline Node<T>* LinkList<T>::FindPreviousNode(crefT dataIn) const
	{
		ptrTNode cursor = nullptr;
		if (this->IsEmpty())
			return nullptr;
		for (cursor = this->first; cursor != nullptr && cursor->next != nullptr; cursor = cursor->next)
			//the cursor before nullptr
			if (cursor->next->content == dataIn)
				return cursor;
		//null if not found, or this has a size of 0 or 1.
		return nullptr;
	}

	template<class T>
	inline void LinkList<T>::RemoveFirst()
	{
		if (this->first == nullptr) return;
		ptrTNode oldFirst = this->first;
		//if first->next == nullptr, first becomes nullptr.
		first = first->next;
		FreeNode(oldFirst);
		//if first is nullptr, that means the list is empty.
		if (first == nullptr)
			last = nullptr;

	}

	template<class T>
	inline void LinkList<T>::RemoveNode(ptrTNode previousNode)
	{
		ptrTNode tmpNode = nullptr;
		if (previousNode->next == nullptr)
			return;
		tmpNode = previousNode->next;
		previousNode->next = tmpNode->next;
		FreeNode(tmpNode);



	}
	template<class T>
	inline Node<T>* LinkList<T>::AllocNode(crefT dataIn)
	{
		ptrTNode myNewNode = new Node<T>(dataIn);
		return myNewNode;
	}
	template<class T>
	inline void LinkList<T>::FreeNode(ptrTNode nodeToDelete)
	{
		if (nodeToDelete != nullptr)
			delete nodeToDelete;
		nodeToDelete = nullptr;
	}
	template<class T>
	inline void LinkList<T>::FreeAllNodes()
	{
		while (this->first != nullptr)
			RemoveFirst();
	}

	template<class T>
	inline bool LinkList<T>::HasOnlyOneElement() const
	{
		return this->first == this->last;
	}

	//a, b, c
	//a <= b <= c <= d
	//value <= c
	//becomes
	//a <= b <= value <= c <= d
	template<class T>
	inline void LinkList<T>::AddAsc(crefT value)
	{
		ptrTNode cursor = nullptr;
		if (this->IsEmpty())
		{
			AddBeginning(value);
			return;
		}
		//stop before cursor is nullptr
		for (cursor = this->first; cursor != nullptr && cursor->next != nullptr; cursor = cursor->next)
		{
			if (cursor->next == nullptr)
			{
				AddEnd(value);
				return;
			}
			else if (value <= cursor->next->content)
			{
				InsertValueAfterSpecifiedNode(value, cursor);
				return;
			}
		}
	}
	template<class T>
	inline void LinkList<T>::AddDesc(crefT value)
	{
		ptrTNode cursor = nullptr;
		if (this->IsEmpty())
		{
			this->AddBeginning(value);
			return;
		}
		//stop before cursor is nullptr
		for (cursor = this->first; cursor != nullptr && cursor->next != nullptr; cursor = cursor->next)
		{
			if (cursor->next == nullptr)
			{
				AddEnd(value);
				return;
			}
			else if (value >= cursor->next->content)
			{
				InsertValueAfterSpecifiedNode(value, cursor);
				return;
			}
		}
	}
	template<class T>
	inline void LinkList<T>::AddEnd(crefT value)
	{
		ptrTNode valueNode = nullptr;
		if (this->IsEmpty())
		{
			AddBeginning(value);
			return;
		}
		valueNode = AllocNode(value);
		this->last->next = valueNode;
		this->last = valueNode;

	}
	template<class T>
	inline void LinkList<T>::AddBeginning(crefT value)
	{
		ptrTNode valueNode = AllocNode(value);
		//This doesn't change whether or not first is null.
		valueNode->next = first;
		first = valueNode;
		//we can't keep last as a nullptr.
		if (last == nullptr)
			last = valueNode;
	}
	template<class T>
	inline void LinkList<T>::InsertValueAfterSpecifiedNode(crefT value, ptrTNode beforeNode)
	{
		ptrTNode valueNode = nullptr;
		//valuenode and beforenode must not be null for this to work.
		//assert(beforeNode != nullptr);//<--this is a macro that might be empty. Better play it safe.
		if (beforeNode == nullptr)
		{
			std::cerr << "LinkList<T>::InsertValueAfterSpecifiedNode received a null pointer. Please tell the programmer fix it." << std::endl;
			return;
		}
		if (beforeNode == last)
		{
			AddEnd(value);
			return;
		}
		valueNode = AllocNode(value);
		valueNode->next = beforeNode->next;
		beforeNode->next = valueNode;

	}
	template<class T>
	inline const T & LinkList<T>::Iterator::operator*() const
	{
		assert(this->value != nullptr);
		return this->value->content;
	}
	template<class T>
	inline bool LinkList<T>::Iterator::Next()
	{
		if (this->value == nullptr)
			return false;
		this->value = this->value->next;
		return this->value != nullptr;
	}
	template<class T>
	inline LinkList<T>::Iterator::operator bool() const
	{
		return this->value != nullptr;
	}
	template<class T>
	inline bool LinkList<T>::Iterator::operator!() const
	{
		return this->value == nullptr;
	}
	template<class T>
	inline LinkList<T>::Iterator::Iterator(Node<T>* initialValue)
	{
		value = initialValue;
	}
}

#endif