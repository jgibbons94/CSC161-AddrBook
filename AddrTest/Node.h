#ifndef NODE_H
#define NODE_H
#include <iostream>
#ifdef NODE_TEST_FRIENDS
//we need to have this declared before making it a friend. TestNode_Constructor is actually defined elsewhere.
namespace test
{
	template<class T>
	void TestNode_Constructor(T sample);

	template<class T>
	void TestNode_Next(T first, T next);

	template<class T>
	void TestNode_Value(T firstValue, T nextValue);
}
#endif
#ifdef LINK_LIST_TEST_FRIENDS
namespace test
{
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
#endif


#ifdef LINK_LIST_TEST_FRIENDS
#endif
		friend class LinkList<T>;

	};
}
#endif //NODE_H
