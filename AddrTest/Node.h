#ifndef NODE_H
#define NODE_H
#include <iostream>
#ifdef NODE_TEST_FRIENDS
#include "RandomGenerators.h"
//we need to have this declared before making it a friend. TestNode_Constructor is actually defined elsewhere.
namespace test
{
	template<class T>
	void TestNode_Constructor(T sample);
	template<class T>
	void TestNode_Next(T first, T next);
	template<class T>
	void TestNode_Value(T firstValue, T nextValue);

	template<class T>
	void TestLinkList_Iterator_NextNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_NextNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_Dereference(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_Constructor(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_boolNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_notNotNull(GeneratorCallback<T> randomGenerator);


	template<class T>
	void TestLinkList_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestLinkList_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
}
#endif

namespace AddrBookLib
{
	template<class T>
	class LinkList;

	//#include "NodeTests.h"
	template<class T>
	class Node
	{
	private:
		Node(T initialContent) { content = initialContent; }
		T content;
		Node<T>* next;

#ifdef NODE_TEST_FRIENDS
		friend void test::TestNode_Constructor(T sample);
		friend void test::TestNode_Next(T first, T next);
		friend void test::TestNode_Value(T firstValue, T nextValue);
		friend void test::TestLinkList_Iterator_NextNull<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_Iterator_NextNotNull<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_Iterator_Dereference<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_Iterator_Constructor<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_Iterator_boolNotNull(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_Iterator_notNotNull<T>(GeneratorCallback<T> randomGenerator);
		friend void test::TestLinkList_CopyConstructor_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestLinkList_Assignment_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
#endif


#ifdef LINK_LIST_TEST_FRIENDS
#endif
			friend class LinkList<T>;

	};
}
#endif //NODE_H
