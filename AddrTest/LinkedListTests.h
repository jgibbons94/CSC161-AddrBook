#ifndef LINKED_LIST_TESTS_H
#define LINKED_LIST_TESTS_H
namespace test
{
	template<class T>
	void TestLinkedList();
	template<class T>
	void TestLinkedList_Constructor();
	template<class T>
	void TestLinkedList_Destructor();
	template<class T>
	void TestLinkedList_Destructor_Leaks();
	template<class T>
	void TestLinkedList_Assignment();
	template<class T>
	void TestLinkedList_Assignment_Leaks();
	template<class T>
	void TestLinkedList_Add();
	template<class T>
	void TestLinkedList_RemoveByItemNumber();
	template<class T>
	void TestLinkedList_RemoveByItem();
	template<class T>
	void TestLinkedList_CountItems();
	template<class T>
	void TestLinkedList_ReadFile();
	template<class T>
	void TestLinkedList_WriteFile();
	template<class T>
	void TestLinkedList_PrintAll();
	template<class T>
	void TestLinkedList_FindNode();
	template<class T>
	void TestLinkedList_FindPreviousNode();
	template<class T>
	void TestLinkedList_RemoveFirst();
	template<class T>
	void TestLinkedList_AllocNode();
	template<class T>
	void TestLinkedList_FreeAllNodes();
	template<class T>
	void test::TestLinkedList()
	{
		TestLinkedList_Constructor<T>();
		TestLinkedList_Destructor<T>();
		TestLinkedList_Destructor_Leaks<T>();
		TestLinkedList_Assignment<T>();
		TestLinkedList_Assignment_Leaks<T>();
		TestLinkedList_Add<T>();
		TestLinkedList_RemoveByItemNumber<T>();
		TestLinkedList_RemoveByItem<T>();
		TestLinkedList_CountItems<T>();
		TestLinkedList_ReadFile<T>();
		TestLinkedList_WriteFile<T>();
		TestLinkedList_PrintAll<T>();
		TestLinkedList_FindNode<T>();
		TestLinkedList_FindPreviousNode<T>();
		TestLinkedList_RemoveFirst<T>();
		TestLinkedList_AllocNode<T>();
		TestLinkedList_FreeAllNodes<T>();
	}
	template<class T>

	void test::TestLinkedList_Constructor()
	{
		ReportMissingTest("TestLinkedList_Constructor");
	}
	template<class T>

	void test::TestLinkedList_Destructor()
	{
		ReportMissingTest("TestLinkedList_Destructor");
	}
	template<class T>

	void test::TestLinkedList_Destructor_Leaks()
	{
		ReportMissingTest("TestLinkedList_Destructor_Leaks");
	}
	template<class T>

	void test::TestLinkedList_Assignment()
	{
		ReportMissingTest("TestLinkedList_Assignment");
	}
	template<class T>

	void test::TestLinkedList_Assignment_Leaks()
	{
		ReportMissingTest("TestLinkedList_Assignment_Leaks");
	}
	template<class T>

	void test::TestLinkedList_Add()
	{
		ReportMissingTest("TestLinkedList_Add");
	}
	template<class T>

	void test::TestLinkedList_RemoveByItemNumber()
	{
		ReportMissingTest("TestLinkedList_RemoveByItemNumber");
	}
	template<class T>

	void test::TestLinkedList_RemoveByItem()
	{
		ReportMissingTest("TestLinkedList_RemoveByItem");
	}
	template<class T>

	void test::TestLinkedList_CountItems()
	{
		ReportMissingTest("TestLinkedList_CountItems");
	}
	template<class T>

	void test::TestLinkedList_ReadFile()
	{
		ReportMissingTest("TestLinkedList_ReadFile");
	}
	template<class T>

	void test::TestLinkedList_WriteFile()
	{
		ReportMissingTest("TestLinkedList_WriteFile");
	}
	template<class T>

	void test::TestLinkedList_PrintAll()
	{
		ReportMissingTest("TestLinkedList_PrintAll");
	}
	template<class T>

	void test::TestLinkedList_FindNode()
	{
		ReportMissingTest("TestLinkedList_FindNode");
	}

	template<class T>
	void test::TestLinkedList_FindPreviousNode()
	{
		ReportMissingTest("TestLinkedList_FindPreviousNode");
	}

	template<class T>
	void test::TestLinkedList_RemoveFirst()
	{
		ReportMissingTest("TestLinkedList_RemoveFirst");
	}
	template<class T>

	void test::TestLinkedList_AllocNode()
	{
		ReportMissingTest("TestLinkedList_AllocNode");
	}
	template<class T>

	void test::TestLinkedList_FreeAllNodes()
	{
		ReportMissingTest("TestLinkedList_FreeAllNodes");
	}

}

#endif
