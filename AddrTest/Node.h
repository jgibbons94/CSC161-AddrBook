#ifndef NODE_H
#define NODE_H
#include <iostream>

#ifdef NODE_TEST_FRIENDS
//we need to have this declared before making it a friend. TestNode_Constructor is actually defined elsewhere.
namespace test
{
	template<class T> void TestNodeConstructor(T sample);
}
#endif

namespace AddrBookLib
{
	//#include "NodeTests.h"
	template<class T>
	class Node
	{
	public:
		Node(T initialContent) { content = initialContent; }
		T content;
		Node<T>* next;

#ifdef NODE_TEST_FRIENDS
		friend extern void test::TestNodeConstructor(T sample);
#endif

	};
}
#endif //NODE_H
