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
	void TestLinkList_AddEnd(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_AddBeginning(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Concat(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveFirst(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_RemoveNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeNode_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeAllNodes(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_FreeAllNodes_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);



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
		TestLinkList_AllocNode<T>(low, medium, high);
		TestLinkList_FindNode<T>(low, medium, high);
		TestLinkList_HasOnlyOneElement<T>(low);
		TestLinkList_AddAsc<T>(low, medium, high);
		TestLinkList_AddDesc<T>(low, medium, high);
		TestLinkList_AddEnd<T>(low, medium, high);
		TestLinkList_AddBeginning<T>(low, medium, high);
		TestLinkList_InsertValueAfterSpecifiedNode<T>(low, medium, high);
		TestLinkList_Concat<T>(low, medium, high);
		TestLinkList_RemoveFirst<T>(low, medium, high);
		TestLinkList_RemoveNode<T>(low, medium, high);
		TestLinkList_FreeNode<T>(low, medium, high);
		TestLinkList_FreeNode_leaks<T>(low, medium, high);
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
		AnnounceTests("LinkLIst<T> Add() function");
		//setup
		LinkList<T> list;
		bool emptyBefore = list.IsEmpty();
		//act
		list.Add(low());
		bool emptyAfter = list.IsEmpty();
		//assert
		assert(emptyBefore == true && emptyAfter == false);
	}

	template<class T>
	void TestLinkList_RemoveByItem(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_RemoveByItem");
	}

	template<class T>
	void TestLinkList_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_Deconstructor");
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
		ReportMissingTest("TestLinkList_PrintAll");
	}

	template<class T>
	void TestLinkList_AllocNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_AllocNode");
	}

	template<class T>
	void TestLinkList_FindNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_FindNode");
	}

	template<class T>
	void TestLinkList_HasOnlyOneElement(GeneratorCallback<T> randomGenerator)
	{
		ReportMissingTest("TestLinkList_HasOnlyOneElement");
	}

	template<class T>
	void TestLinkList_AddAsc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_AddAsc");
	}

	template<class T>
	void TestLinkList_AddDesc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_AddDesc");
	}

	template<class T>
	void TestLinkList_AddEnd(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_AddEnd");
	}

	template<class T>
	void TestLinkList_AddBeginning(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_AddBeginning");
	}

	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_InsertValueAfterSpecifiedNode");
	}

	template<class T>
	void TestLinkList_Concat(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_Concat");
	}

	template<class T>
	void TestLinkList_RemoveFirst(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_RemoveFirst");
	}

	template<class T>
	void TestLinkList_RemoveNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_RemoveNode");
	}

	template<class T>
	void TestLinkList_FreeNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_FreeNode");
	}

	template<class T>
	void TestLinkList_FreeNode_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_FreeNode_leaks");
	}

	template<class T>
	void TestLinkList_FreeAllNodes(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_FreeAllNodes");
	}

	template<class T>
	void TestLinkList_FreeAllNodes_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		ReportMissingTest("TestLinkList_FreeAllNodes_leaks");
	}

}


#endif
