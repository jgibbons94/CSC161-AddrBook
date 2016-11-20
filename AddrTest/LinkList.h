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
}
#endif
namespace AddrBookLib
{
//	template<class T> LinkList;
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
#endif

	};

	typedef LinkList<CategorizedContact> AddrBook;
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
		for (ptrTNode i = first; i != nullptr; i = i->next)
		{
			os << i->content << std::endl;
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
		for (cursor = this->first;cursor != nullptr;cursor cursor->next)
			if (cursor->content == dataIn)
				return cursor;
		return null;
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
		if (this->first = nullptr)
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