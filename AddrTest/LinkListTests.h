#ifndef LINK_LIST_TESTS_H
#define LINK_LIST_TESTS_H
#include <cassert>
#include "Tests.h"
#ifndef LINK_LIST_TEST_FRIENDS
#define LINK_LIST_TEST_FRIENDS
#endif
#include "LinkList.h"
#include "Node.h"
namespace test
{
	template<class T>
	void TestLinkList();
	template<class T>
	void TestLinkList_Constructor();
	template<class T>
	void TestLinkList_CopyConstructor();
	template<class T>
	void TestLinkList_Destructor();
	template<class T>
	void TestLinkList_Destructor_Leaks();
	template<class T>
	void TestLinkList_Assignment();
	template<class T>
	void TestLinkList_Assignment_Leaks();
	template<class T>
	void TestLinkList_Add();
	template<class T>
	void TestLinkList_RemoveByItemNumber();
	template<class T>
	void TestLinkList_RemoveByItem();
	template<class T>
	void TestLinkList_CountItems();
	template<class T>
	void TestLinkList_ReadFile();
	template<class T>
	void TestLinkList_WriteFile();
	template<class T>
	void TestLinkList_PrintAll();
	template<class T>
	void TestLinkList_FindNode();
	template<class T>
	void TestLinkList_FindPreviousNode();
	template<class T>
	void TestLinkList_RemoveFirst();
	template<class T>
	void TestLinkList_RemoveNode();
	template<class T>
	void TestLinkList_AllocNode();
	template<class T>
	void TestLinkList_FreeAllNodes();

	template<class T>
	void TestLinkList()
	{
		TestLinkList_Constructor<T>();
		TestLinkList_CopyConstructor<T>();
		TestLinkList_Destructor<T>();
		TestLinkList_Destructor_Leaks<T>();
		TestLinkList_Assignment<T>();
		TestLinkList_Assignment_Leaks<T>();
		TestLinkList_Add<T>();
		TestLinkList_RemoveByItemNumber<T>();
		TestLinkList_RemoveByItem<T>();
		TestLinkList_CountItems<T>();
		TestLinkList_ReadFile<T>();
		TestLinkList_WriteFile<T>();
		TestLinkList_PrintAll<T>();
		TestLinkList_FindNode<T>();
		TestLinkList_FindPreviousNode<T>();
		TestLinkList_RemoveFirst<T>();
		TestLinkList_RemoveNode<T>();
		TestLinkList_AllocNode<T>();
		TestLinkList_FreeAllNodes<T>();
	}
	template<class T>

	void TestLinkList_Constructor()
	{
		//setup
		LinkList<T> myLinkLIst;
		//act
		//assert
		assert(myLinkLIst.first == nullptr);
	}

	template<class T>
	void TestLinkList_CopyConstructor()
	{
		ReportMissingTest("TestLinkList_AllocNode");
	}

	template<class T>

	void TestLinkList_Destructor()
	{
		ReportMissingTest("TestLinkList_Destructor");
	}

	template<class T>

	void TestLinkList_Destructor_Leaks()
	{
		ReportMissingTest("TestLinkList_Destructor_Leaks");
	}
	template<class T>

	void TestLinkList_Assignment()
	{
		ReportMissingTest("TestLinkList_Assignment");
	}
	template<class T>

	void TestLinkList_Assignment_Leaks()
	{
		ReportMissingTest("TestLinkList_Assignment_Leaks");
	}
	template<class T>

	void TestLinkList_Add()
	{
		ReportMissingTest("TestLinkList_Add");
	}
	template<class T>

	void TestLinkList_RemoveByItemNumber()
	{
		ReportMissingTest("TestLinkList_RemoveByItemNumber");
	}
	template<class T>

	void TestLinkList_RemoveByItem()
	{
		ReportMissingTest("TestLinkList_RemoveByItem");
	}
	template<class T>

	void TestLinkList_CountItems()
	{
		ReportMissingTest("TestLinkList_CountItems");
	}
	template<class T>

	void TestLinkList_ReadFile()
	{
		ReportMissingTest("TestLinkList_ReadFile");
	}
	template<class T>

	void TestLinkList_WriteFile()
	{
		ReportMissingTest("TestLinkList_WriteFile");
	}
	template<class T>

	void TestLinkList_PrintAll()
	{
		ReportMissingTest("TestLinkList_PrintAll");
	}
	template<class T>

	void TestLinkList_FindNode()
	{
		ReportMissingTest("TestLinkList_FindNode");
	}

	template<class T>
	void TestLinkList_FindPreviousNode()
	{
		ReportMissingTest("TestLinkList_FindPreviousNode");
	}

	template<class T>
	void TestLinkList_RemoveFirst()
	{
		ReportMissingTest("TestLinkList_RemoveFirst");
	}
	template<class T>
	void TestLinkList_RemoveNode()
	{
		ReportMissingTest("TestLinkList_AllocNode");
	}
	template<class T>

	void TestLinkList_AllocNode()
	{
		ReportMissingTest("TestLinkList_AllocNode");
	}
	template<class T>

	void TestLinkList_FreeAllNodes()
	{
		ReportMissingTest("TestLinkList_FreeAllNodes");
	}

}

#endif
