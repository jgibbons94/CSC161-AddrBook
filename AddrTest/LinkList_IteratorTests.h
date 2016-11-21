//LinkLIst_IteratorTests
//Written by Jesse Gibbons
#ifndef LINK_LIST_ITERATOR_TESTS
#define LINK_LIST_ITERATOR_TESTS
#ifndef LINK_LIST_TEST_FRIENDS
#define LINK_LIST_TEST_FRIENDS
#endif
#ifndef NODE_TEST_FRIENDS
#define NODE_TEST_FRIENDS
#endif
#include "RandomGenerators.h"
#include "LinkList.h"
#include "Node.h"
namespace test
{
	//iterator tests
	template<class T>
	void TestLinkList_Iterator(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_NextWithNull();
	template<class T>
	void TestLinkList_Iterator_NextNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_NextNotNull(GeneratorCallback<T> randomGenerator);

	template<class T>
	void TestLinkList_Iterator_Dereference(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_boolNull();
	template<class T>
	void TestLinkList_Iterator_boolNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_notNull();
	template<class T>
	void TestLinkList_Iterator_notNotNull(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator_Constructor(GeneratorCallback<T> randomGenerator);
	template<class T>
	void TestLinkList_Iterator(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkList<T> Iterator");
		TestLinkList_Iterator_NextWithNull<T>();
		TestLinkList_Iterator_NextNull<T>(randomGenerator);
		TestLinkList_Iterator_NextNotNull<T>(randomGenerator);
		TestLinkList_Iterator_Dereference<T>(randomGenerator);
		TestLinkList_Iterator_boolNull<T>();
		TestLinkList_Iterator_boolNotNull<T>(randomGenerator);
		TestLinkList_Iterator_notNull<T>();
		TestLinkList_Iterator_notNotNull<T>(randomGenerator);
		TestLinkList_Iterator_Constructor<T>(randomGenerator);
	}
	template<class T>
	void TestLinkList_Iterator_NextWithNull()
	{
		AnnounceTests("LinkList<T> Iterator Next where the current value is Null");
		//setup
		LinkList<T>::Iterator it(nullptr);
		bool failure = false;
		//act
		failure = it.Next();
		//assert
		assert(failure == false);
	}
	template<class T>
	void TestLinkList_Iterator_NextNull(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("Link List Iterator Next where the next value is null");
		//setup
		Node<T> n(randomGenerator());
		LinkList<T>::Iterator it(&n);
		bool failure = true;
		//act
		failure = it.Next();
		//assert
		assert(failure == false);
	}
	template<class T>
	void TestLinkList_Iterator_NextNotNull(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("Link List Iterator Next where the next value is null");
		//setup
		Node<T> a(randomGenerator());
		Node<T> b(randomGenerator());
		a.next = &b;
		LinkList<T>::Iterator it(&a);
		bool failure = false;
		//act
		failure = it.Next();
		//assert
		assert(failure == true);
	}
	template<class T>
	void TestLinkList_Iterator_Dereference(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkList<T> Iterator Dereference operator");
		//setup
		T value = randomGenerator();
		Node<T> myNode(value);
		LinkList<T>::Iterator it(&myNode);
		//act
		T actual = *it;
		//assert
		assert(actual == value);
	}
	template<class T>
	void TestLinkList_Iterator_boolNull()
	{
		AnnounceTests("LinkList<T> Iterator bool operator where content is null");
		//setup
		bool bit = false;
		LinkList<T>::Iterator it(nullptr);
		//act
		if (it)
		{
			bit = true;
		}
		//assert
		assert(bit == false);
	}
	template<class T>
	void TestLinkList_Iterator_boolNotNull(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkList<T> Iterator bool operator where content is not null");
		//setup
		bool bit = false;
		Node<T> myNode(randomGenerator());
		LinkList<T>::Iterator it(&myNode);
		//act
		if (it)
		{
			bit = true;
		}
		//assert
		assert(bit == true);
	}
	template<class T>
	void TestLinkList_Iterator_notNull()
	{
		AnnounceTests("LinkList<T> Iterator not operator where content is null");

		//setup
		LinkList<T>::Iterator it(nullptr);
		//act
		//assert
		assert(!it == true);
	}
	template<class T>
	void TestLinkList_Iterator_notNotNull(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkList<T> Iterator not operator where content is not null");

		//setup
		Node<T> myNode(randomGenerator());
		LinkList<T>::Iterator it(&myNode);
		//act
		//assert
		assert(!it == false);
	}
	template<class T>
	void TestLinkList_Iterator_Constructor(GeneratorCallback<T> randomGenerator)
	{
		AnnounceTests("LinkList<T> Iterator constructor");		//setup
		T value = randomGenerator();
		Node<T> myNode(value);
		LinkList<T>::Iterator it(&myNode);
		//act
		//assert
		assert(it.value->content == value);

	}
}

#endif
