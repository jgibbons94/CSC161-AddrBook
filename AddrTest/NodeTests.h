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
	void TestNode(T sample1, T sample2);

	template<class T>
	void TestNode_Constructor(T sample);

	template<class T>
	void TestNode_Next(T first, T next);

	template<class T>
	void TestNode_Value(T firstValue, T nextValue);

	template<class T>
	void TestNode(T sample1, T sample2)
	{
		AnnounceTests("Node<T>");
		TestNode_Constructor<T>(sample1);
		TestNode_Value<T>(sample1, sample2);
		TestNode_Next<T>(sample1, sample2);
	}

	template<class T>
	void TestNode_Constructor(T sample)
	{
		AnnounceTests("Node<T> Constructor");
		//set up
		AddrBookLib::Node<T> myNode(sample);
		//act
		//assert
		assert(myNode.content == sample);
	}

	template<class T>
	void TestNode_Next(T first, T next)
	{
		AnnounceTests("Node<T> Next");
		//setup
		AddrBookLib::Node<T> firstNode(first);
		AddrBookLib::Node<T> nextNode(next);
		//act
		firstNode.next = &nextNode;
		//assert
		assert(firstNode.next->content==next);
	}

	template<class T>
	void TestNode_Value(T firstValue, T nextValue)
	{
		AnnounceTests("Node<T> Value");
		//setup
		AddrBookLib::Node<T> myNode(firstValue);
		//act
		myNode.content = nextValue;
		//assert
		assert(myNode.content == nextValue);
	}
}
#endif
