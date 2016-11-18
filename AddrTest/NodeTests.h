#ifndef NODE_TESTS_H
#define NODE_TESTS_H
#include <cassert>
#include <iostream>
#include "Tests.h"

#ifndef NODE_TEST_FRIENDS
#define NODE_TEST_FRIENDS
#endif

#include "Node.h"

namespace test
{
	template<class T>
	void TestNode(T sample);

	template<class T>
	void TestNode_Constructor(T sample);

	template<class T>
	void TestNode_Next();

	template<class T>
	void TestNode_Value(T sample);

	template<class T>
	void TestNode(T sample)
	{
		TestNode_Constructor<T>(sample);
		TestNode_Value<T>(sample);
		TestNode_Next<T>();
	}

	template<class T>
	void TestNode_Constructor(T sample)
	{
		//set up
		AddrBookLib::Node<T> myNode(sample);
		//test
		assert(myNode.content == sample);
	}

	template<class T>
	void TestNode_Next()
	{
		ReportMissingTest("TestNodeNext<T>");
	}

	template<class T>
	void TestNode_Value(T sample)
	{
		ReportMissingTest("TestNodeValue<T>");
	}
}
#endif