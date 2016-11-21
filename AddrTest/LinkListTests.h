#ifndef LINK_LIST_TESTS_H
#define LINK_LIST_TESTS_H
#include <cassert>
#include "Tests.h"
#include "LinkList_IteratorTests.h"
#ifndef LINK_LIST_TEST_FRIENDS
#define LINK_LIST_TEST_FRIENDS
#endif
#include "LinkList.h"
#include "Node.h"
#include "RandomGenerators.h"
namespace test
{

	template<class T>
	void TestLinkList(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestLinkList_Constructor0_0();
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
	void TestLinkList_Begin(GeneratorCallback<T> RandomGenerator);
	template<class T>
	void TestLinkList_CountItems(GeneratorCallback<T> RandomGenerator);
	template<class T>
	void TestLinkList_IsEmpty();
	template<class T>
	void TestLinkList_Add(GeneratorCallback<T> RandomGenerator);
	template<class T>
	void TestLinkList_RemoveByItemNumber(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveByItem(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestLinkList_ReadFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_WriteFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_PrintAll(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	//private functions

	template<class T>
	void TestLinkList_AllocNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
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


	//helper

	template<class T>
	void TestLinkList(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T>");
		TestLinkList_Constructor0_0<T>();
		TestLinkList_Constructor0_1<T>();
		TestLinkList_ConstructorFirst<T>();
		TestLinkList_ConstructorLast<T>();
		TestLinkList_ConstructorAsc<T>();
		TestLinkList_ConstructorDesc<T>();
		TestLinkList_CopyConstructor<T>(low, medium, high);
		TestLinkList_CopyConstructor_leaks<T>(low, medium, high);
		TestLinkList_Assignment<T>(low, medium, high);
		TestLinkList_Assignment_leaks<T>(low, medium, high);
		TestLinkList_Begin<T>(medium);
		TestLinkList_CountItems<T>(high);
		TestLinkList_IsEmpty<T>();
		TestLinkList_Add<T>(low);
		TestLinkList_RemoveByItemNumber<T>(low, medium, high);
		TestLinkList_RemoveByItem<T>(low, medium, high);
		TestLinkList_Deconstructor<T>(low, medium, high);
		TestLinkList_ReadFile<T>(low, medium, high);
		TestLinkList_WriteFile<T>(low, medium, high);
		TestLinkList_PrintAll<T>(low, medium, high);
		//private functions
		TestLinkList_AllocNode<T>(high);
		TestLinkList_FindNode<T>(low, medium, high);
		TestLinkList_HasOnlyOneElement<T>(low);
		TestLinkList_AddAsc<T>(low, medium, high);
		TestLinkList_AddDesc<T>(low, medium, high);
		TestLinkList_AddEnd<T>(medium);
		TestLinkList_AddBeginning<T>(medium);
		TestLinkList_InsertValueAfterSpecifiedNode<T>(low, medium, high);
		TestLinkList_Concat<T>(low, medium, high);
		TestLinkList_RemoveFirst<T>(low, medium, high);
		TestLinkList_RemoveNode<T>(low, medium, high);
		TestLinkList_FreeNode<T>(high);
		TestLinkList_FreeAllNodes<T>(low, medium, high);
		TestLinkList_FreeAllNodes_leaks<T>(low, medium, high);

		TestLinkList_Iterator<T>(low);
	}

	template<class T>
	void TestLinkList_Constructor0_0()
	{
		AnnounceTests("LinkList<T> constructor 0 0");
		LinkList<T> ll;
		assert(ll.first == nullptr);
	}
	template<class T>
	void TestLinkList_Constructor0_1()
	{
		AnnounceTests("LinkList<T> Constructor 0 1");
		LinkList<T> ll;
		assert(ll.last == nullptr);
	}

	template<class T>
	void TestLinkList_ConstructorFirst()
	{
		AnnounceTests("LinkList<T> Constructor that inserts all new elements into first's place");
		LinkList<T> ll(LinkList<T>::FIRST);
		assert(ll.insertOrder == ll.FIRST);
	}

	template<class T>
	void TestLinkList_ConstructorLast()
	{
		AnnounceTests("LinkList<T> Constructor that inserts all new elements into lasts's place");
		LinkList<T> ll(LinkList<T>::LAST);
		assert(ll.insertOrder == ll.LAST);
	}

	template<class T>
	void TestLinkList_ConstructorAsc()
	{
		AnnounceTests("LinkList<T> Constructor that inserts all new elements in ascending order");
		LinkList<T> ll(LinkList<T>::ASCENDING);
		assert(ll.insertOrder == ll.ASCENDING);
	}

	template<class T>
	void TestLinkList_ConstructorDesc()
	{
		AnnounceTests("LinkList<T> Constructor that inserts all new elements in descending order");
		LinkList<T> ll(LinkList<T>::DESCENDING);
		assert(ll.insertOrder == ll.DESCENDING);
	}

	template<class T>
	void TestLinkList_CopyConstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T> copy constructor");
		//setup
		bool passed = true;
		LinkList<T> a;
		for (int i = 0; i < 10; i++)
		{
			a.Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			a.Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			a.Add(high());
		}
		//act
		LinkList<T> b(a);
		LinkList<T>::Iterator iteratorA = a.Begin(), iteratorB = b.Begin();
		while (iteratorA && iteratorB)
		{
			if (*iteratorA != *iteratorB)
				passed = false;
			iteratorA.Next();
			iteratorB.Next();
		}
		if (!iteratorA ^ !iteratorB)
			passed = false;
		assert(passed == true);

	}

	template<class T>
	void TestLinkList_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T> copy constructor leak check");
		//setup
		bool passed1 = false, passed2 = true, passed3 = false;
		LinkList<T>* a = new LinkList<T>();
		Node<T>* kept;
		for (int i = 0; i < 10; i++)
		{
			a->Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			a->Add(medium());
		}
		kept = a->last;
		T keptExpected = kept->content;
		for (int i = 0; i < 10; i++)
		{
			a->Add(high());
		}

		//act
		LinkList<T> b(*a);
		delete a;
		try
		{
			T t = kept->content;
			if (t == keptExpected)
				cerr << "Memory leak alert in copy constructor." << endl;
			else
				passed1 = true;
		}
		catch (...)
		{
			passed1 = true;
		}
		int count = 0;
		try
		{
			for (LinkList<T>::Iterator it = b.Begin(); it; it.Next())
			{
				count++;
			}
		}
		catch (...)
		{
			cerr << "There appears to be a memory leak in the copy constructor after " << count << "iterations." << endl;
			passed2 = false;
		}
		passed3 = (count == 30);
		assert(passed1 == true && passed2 == true && passed3 == true);
	}

	template<class T>
	void TestLinkList_Assignment(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T> Assignment operator");
		//setup
		bool passed = true;
		LinkList<T> a;
		for (int i = 0; i < 10; i++)
		{
			a.Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			a.Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			a.Add(high());
		}
		//act
		LinkList<T> b = a;
		LinkList<T>::Iterator iteratorA = a.Begin(), iteratorB = b.Begin();
		while (iteratorA && iteratorB)
		{
			if (*iteratorA != *iteratorB)
				passed = false;
			iteratorA.Next();
			iteratorB.Next();
		}
		if (!iteratorA ^ !iteratorB)
			passed = false;
		assert(passed == true);

	}

	template<class T>
	void TestLinkList_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T> Assignemnt operator leak check");
		//setup
		bool passed1 = false, passed2 = true, passed3 = false;
		LinkList<T>* a = new LinkList<T>();
		Node<T>* kept;
		for (int i = 0; i < 10; i++)
		{
			a->Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			a->Add(medium());
		}
		kept = a->last;
		T keptExpected = kept->content;
		for (int i = 0; i < 10; i++)
		{
			a->Add(high());
		}

		//act
		LinkList<T> b = *a;
		delete a;
		try
		{
			T t = kept->content;
			if (t == keptExpected)
				cerr << "Memory leak alert in assignment operator." << endl;
			else
				passed1 = true;
		}
		catch (...)
		{
			passed1 = true;
		}
		int count = 0;
		try
		{
			for (LinkList<T>::Iterator it = b.Begin(); it; it.Next())
			{
				count++;
			}
		}
		catch (...)
		{
			cerr << "There appears to be a memory leak in the assignment operator after " << count << "iterations." << endl;
			passed2 = false;
		}
		passed3 = (count == 30);
		assert(passed1 == true && passed2 == true && passed3 == true);
	}

	template<class T>
	void TestLinkList_Begin(GeneratorCallback<T> RandomGenerator)
	{
		AnnounceTests("LinkList<T> Begin() function");
		//setup
		LinkList<T> list;
		T value = RandomGenerator();
		list.Add(value);
		//act
		LinkList<T>::Iterator it = list.Begin();
		//assert
		assert(*it == value);

	}

	template<class T>
	void TestLinkList_CountItems(GeneratorCallback<T> RandomGenerator)
	{
		AnnounceTests("LinkList<T> CountItems() function");
		//setup
		int size = GenerateHighRandomNumber();
		int count = 0;
		LinkList<T> list;
		//act
		for (int i = 0; i < size; i++)
		{
			list.Add(RandomGenerator());
		}
		count = static_cast<int>(list.CountItems());
		//assert
		assert(count == size);

	}

	template<class T>
	void TestLinkList_IsEmpty()
	{
		AnnounceTests("LinkList<T> IsEmpty() function");
		//setup
		LinkList<T> list;
		//act
		bool empty = list.IsEmpty();
		//assert
		assert(empty == true);
	}

	template<class T>
	void TestLinkList_Add(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkLIst<T> Add() function");
		//setup
		LinkList<T> list;
		bool emptyBefore = list.IsEmpty();
		//act
		list.Add(randomGenerator());
		bool emptyAfter = list.IsEmpty();
		//assert
		assert(emptyBefore == true && emptyAfter == false);
	}

	template<class T>
	void TestLinkList_RemoveByItemNumber(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("Link List remove by number test");
		//setup
		LinkList<T> list;
		for (int i = 0; i < 10;i++)
		{
			list.Add(low());
		}
		T removeValue = medium();
		for (int i = 0; i < 10; i++)
		{
			list.Add(high());
		}
		//act
		list.RemoveByItemNumber(10);
		auto actualLocation = list.FindNode(removeValue);
		//assert
		assert(actualLocation == nullptr);
	}

	template<class T>
	void TestLinkList_RemoveByItem(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("Link List remove by item test");
		//setup
		LinkList<T> list;
		for (int i = 0; i < 10;i++)
		{
			list.Add(low());
		}
		T removeValue = medium();
		for (int i = 0; i < 10; i++)
		{
			list.Add(high());
		}
		//act
		list.RemoveByItem(removeValue);
		auto actualLocation = list.FindNode(removeValue);
		//assert
		assert(actualLocation == nullptr);
	}

	template<class T>
	void TestLinkList_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T>  destructor");
		//setup
		bool passed1 = false, passed2 = true, passed3 = false;
		LinkList<T>* a = new LinkList<T>();
		Node<T>* kept;
		for (int i = 0; i < 10; i++)
		{
			a->Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			a->Add(medium());
		}
		kept = a->last;
		T keptExpected = kept->content;
		for (int i = 0; i < 10; i++)
		{
			a->Add(high());
		}

		//act
		delete a;
		try
		{
			T t = kept->content;
			if (t == keptExpected)
				cerr << "Memory leak alert in deconstructor." << endl;
			else
				passed1 = true;
		}
		catch (...)
		{
			passed1 = true;
		}
		assert(passed1 == true);

	}

	template<class T>
	void TestLinkList_ReadFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		//setup
		AnnounceTests("LinkList<T> Read file");
		LinkList<T> checker, reader;

		ofstream ofs;
		bool identical = true;
		//act
		ofs.open("test.csv");
		if (!ofs)
		{
			cerr << "Could not open file test.csv to write." << endl;
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			T value = low();
			checker.Add(value);
			ofs << value << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			T value = medium();
			checker.Add(value);
			ofs << value << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			T value = high();
			checker.Add(value);
			ofs << value << endl;
		}
		ofs.close();
		reader.ReadFile("test.csv");
		remove("test.csv");
		int iterations = 0;
		LinkList<T>::Iterator iteratorR = reader.Begin(), iteratorC = checker.Begin();
		while (iteratorR && iteratorC && identical)
		{
			if (*iteratorR != *iteratorC)
				identical = false;
			iteratorR.Next();
			iteratorC.Next();
		}
		if (iteratorR ^ iteratorC)
			identical = false;
		//assert
		assert(identical == true);
	}

	template<class T>
	void TestLinkList_WriteFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		string expected;
		string actual;
		AnnounceTests("LinkList<T> Read file");
		//setup
		LinkList<T> list;
		stringstream checkStream;
		ifstream ifs;
		//act
		for (int i = 0; i < 10; i++)
		{
			T value = low();
			checkStream << value << endl;
			list.Add(value);
		}
		for (int i = 0; i < 10; i++)
		{
			T value = medium();
			checkStream << value << endl;
			list.Add(value);
		}
		for (int i = 0; i < 10; i++)
		{
			T value = high();
			checkStream << value << endl;
			list.Add(value);
		}
		getline(checkStream, expected, '\t');
		list.WriteFile("test.csv");
		ifs.open("test.csv");
		if (!ifs)
		{
			cerr << "Could not open file test.csv to read." << endl;
			return;
		}
		getline(ifs, actual, '\t');
		ifs.close();
		remove("test.csv");
		//assert
		assert(expected == actual);
	}

	template<class T>
	void TestLinkList_PrintAll(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList Print All");
		//prepare
		ostringstream printTo, checkStream;

		ostream* tmpCout = _Ptr_cout;
		//set the current pointer to a new ostringStream
		_Ptr_cout = &checkStream;
		string expected, actual;
		int counter = 1;
		bool passed = true;
		LinkList<T> a;
		//act
		for (int i = 0; i < 10; i++)
		{
			T value = low();
			a.Add(value);
			checkStream << counter++ << ": " << value << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			T value = medium();
			a.Add(value);
			checkStream << counter++ << ": " << value << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			T value = high();
			a.Add(value);
			checkStream << counter++ << ": " << value << endl;
		}
		expected = checkStream.str();
		_Ptr_cout = &printTo;
		a.PrintAll(printTo);

		actual = printTo.str();

		//assert
		assert(actual == expected);
		_Ptr_cout = tmpCout;

	}

	template<class T>
	void TestLinkList_AllocNode(GeneratorCallback<T> randomGenerator)
	{
		LinkList<T> list;
		T expectedContent = randomGenerator();
		Node<T> * myNode = list.AllocNode(expectedContent);
		assert(myNode->content == expectedContent);
		if (myNode != nullptr)
			delete myNode;
	}

	template<class T>
	void TestLinkList_FindNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list;
		T valueToFind = medium();
		Node<T>* found = nullptr;
		for (int i = 0; i < 10; i++)
			list.Add(low());
		list.Add(valueToFind);
		for (int i = 0; i < 10; i++)
			list.Add(high());
		found = list.FindNode(valueToFind);
		assert(found->content == valueToFind);

	}

	template<class T>
	void TestLinkList_HasOnlyOneElement(GeneratorCallback<T> randomGenerator)
	{
		LinkList<T> list;
		T singleElement = randomGenerator();
		list.Add(singleElement);
		bool hasOnlyOneElement = list.HasOnlyOneElement();
		assert(hasOnlyOneElement == true);

	}

	template<class T>
	void TestLinkList_AddAsc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		T previous = low(), current = low();
		bool pass = true;
		LinkList<T> list;
		for (int i = 0; i < 10; i++)
			list.AddAsc(low());
		for (int i = 0; i < 10; i++)
			list.AddAsc(medium());
		for (int i = 0; i < 10; i++)
			list.AddAsc(high());
		LinkList<T>::Iterator it = list.Begin();
		previous = *it;
		for (it.Next(); it; it.Next())
		{
			current = *it;
			if (current < previous)
				pass = false;
		}
		assert(pass == true);
	}

	template<class T>
	void TestLinkList_AddDesc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		T previous = low(), current = low();
		bool pass = true;
		LinkList<T> list;
		for (int i = 0; i < 10; i++)
			list.AddDesc(low());
		for (int i = 0; i < 10; i++)
			list.AddDesc(medium());
		for (int i = 0; i < 10; i++)
			list.AddDesc(high());
		LinkList<T>::Iterator it = list.Begin();
		previous = *it;

		for (it.Next(); it; it.Next())
		{
			current = *it;
			if (current > previous)
				pass = false;
		}
		assert(pass == true);
	}

	template<class T>
	void TestLinkList_AddEnd(GeneratorCallback<T> randomGenerator)
	{
		LinkList<T> list;
		T expected = randomGenerator();
		for (int i = 0; i < 10; i++)
			list.Add(randomGenerator());
		list.AddEnd(expected);
		Node<T>* myNode = list.last;
		assert(myNode->content == expected);
	}

	template<class T>
	void TestLinkList_AddBeginning(GeneratorCallback<T> randomGenerator)
	{
		LinkList<T> list;
		T expected = randomGenerator();
		for (int i = 0; i < 10; i++)
			list.Add(randomGenerator());
		list.AddBeginning(expected);
		Node<T>* myNode = list.first;
		assert(myNode->content == expected);
	}

	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list;
		Node<T>* before = nullptr;
		T myValue = medium();
		for (int i = 0; i < 10; i++)
			list.Add(low());
		for (int i = 0; i < 10; i++)
			list.Add(medium());
		for (int i = 0; i < 10; i++)
			list.Add(high());
		before = list.first;

		list.InsertValueAfterSpecifiedNode(myValue, before);
		LinkList<T>::Iterator it = list.Begin();
		it.Next();

		assert(*it == myValue);
	}

	template<class T>
	void TestLinkList_Concat(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list1, list2;
		for (int i = 0; i < 10; i++)
			list1.Add(low());
		for (int i = 0; i < 10; i++)
			list1.Add(medium());
		for (int i = 0; i < 10; i++)
			list1.Add(high());
		size_t list1Size = list1.CountItems();

		for (int i = 0; i < 10; i++)
			list2.Add(low());
		for (int i = 0; i < 10; i++)
			list2.Add(medium());
		for (int i = 0; i < 10; i++)
			list2.Add(high());
		size_t list2Size = list2.CountItems();

		list2.Concat(list1);
		size_t list2NewSize = list2.CountItems();
		assert(list2NewSize == (list1Size + list2Size));
	}

	template<class T>
	void TestLinkList_RemoveFirst(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list;
		T first = low();
		T second = medium();
		list.Add(first);
		list.Add(second);
		for (int i = 0; i < 10; i++)
			list.Add(low());
		for (int i = 0; i < 10; i++)
			list.Add(medium());
		for (int i = 0; i < 10; i++)
			list.Add(high());
		list.RemoveFirst();
		LinkList<T>::Iterator newFirst = list.Begin();
		assert(*newFirst == second);
	}

	template<class T>
	void TestLinkList_RemoveNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list;
		T first = low();
		T second = medium();
		T third = high();
		list.Add(first);
		list.Add(second);
		list.Add(third);
		for (int i = 0; i < 10; i++)
			list.Add(low());
		for (int i = 0; i < 10; i++)
			list.Add(medium());
		for (int i = 0; i < 10; i++)
			list.Add(high());
		Node<T> * nodeBeforeNodeToRemove = list.first;
		list.RemoveNode(nodeBeforeNodeToRemove);
		LinkList<T>::Iterator newSecond = list.Begin();
		newSecond.Next();
		assert(*newSecond == third);
	}

	template<class T>
	void TestLinkList_FreeNode(GeneratorCallback<T> RandomGenerator)
	{
		T keptExpected = RandomGenerator();
		T keptActual = keptExpected;
		Node<T> * myNode = new Node<T>(keptExpected);
		LinkList<T> list;
		bool pass = false;
		list.FreeNode(myNode);
		try
		{
			keptActual = myNode->content;
			if (keptActual == keptExpected)
				cerr << "Memory leak alert in copy constructor." << endl;
			else
				pass = true;
		}
		catch (...)
		{
			pass = true;
		}
		assert(pass == true);
	}

	template<class T>
	void TestLinkList_FreeAllNodes(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		LinkList<T> list;
		size_t listSize = 0;
		for (int i = 0; i < 10; i++)
			list.Add(low());
		for (int i = 0; i < 10; i++)
			list.Add(medium());
		for (int i = 0; i < 10; i++)
			list.Add(high());
		list.FreeAllNodes();
		listSize = list.CountItems();
		assert(listSize == 0);

	}

	template<class T>
	void TestLinkList_FreeAllNodes_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		Node<T>* keptExpected = nullptr;
		Node<T>* keptActual = nullptr;
		Node<T> * myNode = nullptr;
		LinkList<T> list;
		for (int i = 0; i < 10; i++)
			list.Add(low());
		list.Add(low());
		myNode = list.last;
		list.Add(medium());
		keptExpected = myNode->next;
		for (int i = 0; i < 10; i++)
			list.Add(medium());
		for (int i = 0; i < 10; i++)
			list.Add(high());
		bool pass = false;
		list.FreeAllNodes();
		try
		{
			keptActual = myNode->next;
			if (keptActual == keptExpected)
				cerr << "Memory leak alert in copy constructor." << endl;
			else
				pass = true;
		}
		catch (...)
		{
			pass = true;
		}
		assert(pass == true);
	}


}


#endif
