#ifndef LINK_LIST_ITERATOR_TESTS
#define LINK_LIST_ITERATOR_TESTS

namespace test
{
	//iterator tests
	template<class T>
	void TestLinkList_Iterator();
	template<class T>
	void TestLinkList_Iterator_Next();
	template<class T>
	void TestLinkList_Iterator_Dereference();
	template<class T>
	void TestLinkList_Iterator_bool();
	template<class T>
	void TestLinkList_Iterator_not();
	template<class T>
	void TestLinkList_Iterator_Constructor();
	template<class T>
	void TestLinkList_Iterator()
	{
		
		 TestLinkList_Iterator_Next<T>();
		
		 TestLinkList_Iterator_Dereference<T>();
		
		 TestLinkList_Iterator_bool<T>();
		
		 TestLinkList_Iterator_not<T>();
		
		 TestLinkList_Iterator_Constructor<T>();
	}
	template<class T>
	void TestLinkList_Iterator_Next()
	{
		ReportMissingTest("TestLinkList_Iterator_Next");
	}
	template<class T>
	void TestLinkList_Iterator_Dereference()
	{
		ReportMissingTest("TestLinkList_Iterator_Dereference");
	}
	template<class T>
	void TestLinkList_Iterator_bool()
	{
		ReportMissingTest("TestLinkList_Iterator_bool");
	}
	template<class T>
	void TestLinkList_Iterator_not()
	{
		ReportMissingTest("TestLinkList_Iterator_not");
	}
	template<class T>
	void TestLinkList_Iterator_Constructor()
	{
		ReportMissingTest("TestLinkList_Iterator_Constructor");
	}
}

#endif
