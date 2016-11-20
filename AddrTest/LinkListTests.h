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
	void TestLinkList_ConstructorAsc1();
	template<class T>
	void TestLinkList_ConstructorDesc();
	template<class T>
	void TestLinkList_CopyConstructor();
	template<class T>
	void TestLinkList_CopyConstructor_leaks();
	template<class T>
	void TestLinkList_Assignment();
	template<class T>
	void TestLinkList_Assignment_leaks();

	template<class T>
	void TestLinkList_Begin();
	template<class T>
	void TestLinkList_CountItems();
	template<class T>
	void TestLinkList_IsEmpty();
	template<class T>
	void TestLinkList_Add();
	template<class T>
	void TestLinkList_RemoveByItemNumber();
	template<class T>
	void TestLinkList_RemoveByItem();
	template<class T>
	void TestLinkList_Deconstructor();

	template<class T>
	void TestLinkList_ReadFile();
	template<class T>
	void TestLinkList_WriteFile();
	template<class T>
	void TestLinkList_PrintAll();

	//private functions
	template<class T>
	void TestLinkList_AllocNode();
	template<class T>
	void TestLinkList_FindNode();
	template<class T>
	void TestLinkList_HasOnlyOneElement();
	template<class T>
	void TestLinkList_AddAsc();
	template<class T>
	void TestLinkList_AddDesc();
	template<class T>
	void TestLinkList_AddEnd();
	template<class T>
	void TestLinkList_AddBeginning();
	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode();
	template<class T>
	void TestLinkList_Concat();
	template<class T>
	void TestLinkList_RemoveFirst();
	template<class T>
	void TestLinkList_RemoveNode();
	template<class T>
	void TestLinkList_FreeNode();
	template<class T>
	void TestLinkList_FreeNode_leaks();
	template<class T>
	void TestLinkList_FreeAllNodes();
	template<class T>
	void TestLinkList_FreeAllNodes_leaks();



	template<class T>
	void TestLinkList(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		TestLinkList_Constructor0_0<T>();
		TestLinkList_Constructor0_1<T>();
		TestLinkList_ConstructorFirst<T>();
		TestLinkList_ConstructorLast<T>();
		TestLinkList_ConstructorAsc1<T>();
		TestLinkList_ConstructorDesc<T>();
		TestLinkList_CopyConstructor<T>();
		TestLinkList_CopyConstructor_leaks<T>();
		TestLinkList_Assignment<T>();
		TestLinkList_Assignment_leaks<T>();
		TestLinkList_Assignment<T>();
		TestLinkList_Begin<T>();
		TestLinkList_CountItems<T>();
		TestLinkList_IsEmpty<T>();
		TestLinkList_Add<T>();
		TestLinkList_RemoveByItemNumber<T>();
		TestLinkList_RemoveByItem<T>();
		TestLinkList_Deconstructor<T>();
		TestLinkList_ReadFile<T>();
		TestLinkList_WriteFile<T>();
		TestLinkList_PrintAll<T>();
		//private functions
		TestLinkList_AllocNode<T>();
		TestLinkList_FindNode<T>();
		TestLinkList_HasOnlyOneElement<T>();
		TestLinkList_AddAsc<T>();
		TestLinkList_AddDesc<T>();
		TestLinkList_AddEnd<T>();
		TestLinkList_AddBeginning<T>();
		TestLinkList_InsertValueAfterSpecifiedNode<T>();
		TestLinkList_Concat<T>();
		TestLinkList_RemoveFirst<T>();
		TestLinkList_RemoveNode<T>();
		TestLinkList_FreeNode<T>();
		TestLinkList_FreeNode_leaks<T>();
		TestLinkList_FreeAllNodes<T>();
		TestLinkList_FreeAllNodes_leaks<T>();
		TestLinkList_Iterator<T>();
	}

	template<class T>
	void TestLinkList_Constructor0_0()
	{
		LinkList<T> ll;
		assert(ll.first == nullptr);
	}
	template<class T>
	void TestLinkList_Constructor0_1()
	{
		LinkList<T> ll;
		assert(ll.last == nullptr);
	}

	template<class T>
	void TestLinkList_ConstructorFirst()
	{
		ReportMissingTest("TestLinkList_ConstructorFirst");
	}

	template<class T>
	void TestLinkList_ConstructorLast()
	{
		ReportMissingTest("TestLinkList_ConstructorLast");
	}

	template<class T>
	void TestLinkList_ConstructorAsc1()
	{
		ReportMissingTest("TestLinkList_ConstructorAsc1");
	}

	template<class T>
	void TestLinkList_ConstructorDesc()
	{
		ReportMissingTest("TestLinkList_ConstructorDesc");
	}

	template<class T>
	void TestLinkList_CopyConstructor()
	{
		ReportMissingTest("TestLinkList_CopyConstructor");
	}

	template<class T>
	void TestLinkList_CopyConstructor_leaks()
	{
		ReportMissingTest("TestLinkList_CopyConstructor_leaks");
	}

	template<class T>
	void TestLinkList_Assignment()
	{
		ReportMissingTest("TestLinkList_Assignment");
	}

	template<class T>
	void TestLinkList_Assignment_leaks()
	{
		ReportMissingTest("TestLinkList_Assignment_leaks");
	}

	template<class T>
	void TestLinkList_Begin()
	{
		ReportMissingTest("TestLinkList_Begin");
	}

	template<class T>
	void TestLinkList_CountItems()
	{
		ReportMissingTest("TestLinkList_CountItems");
	}

	template<class T>
	void TestLinkList_IsEmpty()
	{
		ReportMissingTest("TestLinkList_IsEmpty");
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
	void TestLinkList_Deconstructor()
	{
		ReportMissingTest("TestLinkList_Deconstructor");
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
	void TestLinkList_AllocNode()
	{
		ReportMissingTest("TestLinkList_AllocNode");
	}

	template<class T>
	void TestLinkList_FindNode()
	{
		ReportMissingTest("TestLinkList_FindNode");
	}

	template<class T>
	void TestLinkList_HasOnlyOneElement()
	{
		ReportMissingTest("TestLinkList_HasOnlyOneElement");
	}

	template<class T>
	void TestLinkList_AddAsc()
	{
		ReportMissingTest("TestLinkList_AddAsc");
	}

	template<class T>
	void TestLinkList_AddDesc()
	{
		ReportMissingTest("TestLinkList_AddDesc");
	}

	template<class T>
	void TestLinkList_AddEnd()
	{
		ReportMissingTest("TestLinkList_AddEnd");
	}

	template<class T>
	void TestLinkList_AddBeginning()
	{
		ReportMissingTest("TestLinkList_AddBeginning");
	}

	template<class T>
	void TestLinkList_InsertValueAfterSpecifiedNode()
	{
		ReportMissingTest("TestLinkList_InsertValueAfterSpecifiedNode");
	}

	template<class T>
	void TestLinkList_Concat()
	{
		ReportMissingTest("TestLinkList_Concat");
	}

	template<class T>
	void TestLinkList_RemoveFirst()
	{
		ReportMissingTest("TestLinkList_RemoveFirst");
	}

	template<class T>
	void TestLinkList_RemoveNode()
	{
		ReportMissingTest("TestLinkList_RemoveNode");
	}

	template<class T>
	void TestLinkList_FreeNode()
	{
		ReportMissingTest("TestLinkList_FreeNode");
	}

	template<class T>
	void TestLinkList_FreeNode_leaks()
	{
		ReportMissingTest("TestLinkList_FreeNode_leaks");
	}

	template<class T>
	void TestLinkList_FreeAllNodes()
	{
		ReportMissingTest("TestLinkList_FreeAllNodes");
	}

	template<class T>
	void TestLinkList_FreeAllNodes_leaks()
	{
		ReportMissingTest("TestLinkList_FreeAllNodes_leaks");
	}

}


#endif
