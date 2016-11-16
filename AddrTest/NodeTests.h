#ifndef NODE_TESTS_H
#define NODE_TESTS_H
#include "Tests.h"
namespace test
{
	template<class T>
	void TestNode(T sample);

	template<class T>
	void TestNodeConstructor();

	template<class T>
	void TestNodeNext();

	template<class T>
	void TestNodeValue(T sample);

	template<class T>
	void TestNode(T sample)
	{
		TestNodeConstructor<T>();
		TestNodeValue<T>(sample);
		TestNodeNext<T>();
	}

	template<class T>
	void TestNodeConstructor()
	{
		ReportMissingTest("TestNodeConstructor<T>");
	}

	template<class T>
	void TestNodeNext()
	{
		ReportMissingTest("TestNodeNext<T>");
	}

	template<class T>
	void TestNodeValue(T sample)
	{
		ReportMissingTest("TestNodeValue<T>");
	}
}
#endif