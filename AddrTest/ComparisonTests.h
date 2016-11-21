//ComparisonTests.h
//template functions to test comparison operators ==, !=, >, >=, < <=
//Written by Jesse Gibbons
#ifndef COMPARISON_TESTS_H
#define COMPARISON_TESTS_H
#include <cassert>
namespace test
{
	void TestTemplateInEqTests();

	//This template test is for all classes that override all comparison operators.
	template<class T> void RunAllInEqTests(const T& lesser, const T& middle, const T& greater);

	//This template test is for all classes that only override operator== and operator!=
	template<class T> void RunAllEqTests(const T& lesser, const T& middle, const T& greater);

	/*
	These following template tests check the specified inequality operator overloads.
	Use them as a shortcut for testing all operator overloads.
	*/

	//test that middle==middle, lesser==lesser, greater==greater, !(middle==lesser), etc.
	template<class T> void TestAllEq(const T& lesser, const T& middle, const T& greater);

	//test middle!=lesser, middle!=greater, !(middle!=middle), etc.
	template<class T> void TestAllNEq(const T& lesser, const T& middle, const T& greater);

	//test !(greater > greater), greater > middle, greater > lesser, middle > lesser, !(middle < greater), etc.
	template<class T> void TestAllGt(const T& lesser, const T& middle, const T& greater);

	//test greater >= greater, greater >= middle, greater >= lesser, !(middle >= greater)
	template<class T> void TestAllGtE(const T& lesser, const T& middle, const T& greater);

	//test lesser < middle, lesser < greater, !(lesser < lesser), middle < greater, etc.
	template<class T> void TestAllLt(const T& lesser, const T& middle, const T& greater);

	//Test lesser <= lesser, lesser <= middle, lesser <= greater, etc.
	template<class T> void TestAllLtE(const T& lesser, const T& middle, const T& greater);

	/*
	These following tests check the specified overloaded operator
	The tests beginning with N test that the specified overloaded operator is false.
	*/

	//Test a == b
	template<class T> void TestEq(const T& a, const T& b);

	//test ! (a == b)
	template<class T> void NTestEq(const T& a, const T& b);

	//test a != b
	template<class T> void TestNEq(const T& a, const T& b);

	//test ! (a != b)
	template<class T> void NTestNEq(const T& a, const T& b);

	//test a > b
	template<class T> void TestGt(const T& a, const T& b);

	//test ! (a > b)
	template<class T> void NTestGt(const T& a, const T& b);

	//test a >= b
	template<class T>void TestGtE(const T& a, const T& b);

	//test ! (a >= b)
	template<class T> void NTestGtE(const T& a, const T& b);

	//test a < b
	template<class T> void TestLt(const T& a, const T& b);

	//test ! (a < b)
	template<class T> void NTestLt(const T& a, const T& b);

	//test a <= b
	template<class T> void TestLtE(const T& a, const T& b);

	//test ! (a <= b)
	template<class T> void NTestLtE(const T& a, const T& b);


	template<class T>
	inline void RunAllInEqTests(const T & lesser, const T & middle, const T & greater)
	{
		RunAllEqTests(lesser, middle, greater);
		TestAllGt(lesser, middle, greater);
		TestAllGt(lesser, middle, greater);
		TestAllLt(lesser, middle, greater);
		TestAllLtE(lesser, middle, greater);
	}

	template<class T>
	inline void RunAllEqTests(const T & lesser, const T & middle, const T & greater)
	{
		TestAllEq(lesser, middle, greater);
		TestAllNEq(lesser, middle, greater);
	}

	template<class T>
	inline void TestAllEq(const T & lesser, const T & middle, const T & greater)
	{
		TestEq(lesser, lesser);
		NTestEq(lesser, middle);
		NTestEq(lesser, greater);

		TestEq(middle, middle);
		NTestEq(middle, lesser);
		NTestEq(middle, greater);

		TestEq(greater, greater);
		NTestEq(greater, lesser);
		NTestEq(greater, middle);
	}

	template<class T>
	void TestAllNEq(const T & lesser, const T & middle, const T & greater)
	{
		NTestNEq(lesser, lesser);
		TestNEq(lesser, middle);
		TestNEq(lesser, greater);

		TestNEq(middle, lesser);
		NTestNEq(middle, middle);
		TestNEq(middle, greater);

		TestNEq(greater, lesser);
		TestNEq(greater, middle);
		NTestNEq(greater, greater);
	}

	template<class T>
	void TestAllGt(const T & lesser, const T & middle, const T & greater)
	{
		NTestGt(lesser, lesser);
		NTestGt(lesser, middle);
		NTestGt(lesser, greater);

		TestGt(middle, lesser);
		NTestGt(middle, middle);
		NTestGt(middle, greater);

		TestGt(greater, lesser);
		TestGt(greater, middle);
		NTestGt(greater, greater);
	}

	template<class T>
	void TestAllGtE(const T & lesser, const T & middle, const T & greater)
	{
		TestGtE(lesser, lesser);
		NTestGtE(lesser, middle);
		NTestGtE(lesser, greater);

		TestGte(middle, lesser);
		TestGte(middle, middle);
		NTestGt(middle, greater);

		TestGtE(greater, lesser);
		TestGtE(greater, middle);
		TestGtE(greater, greater);
	}

	template<class T>
	void TestAllLt(const T & lesser, const T & middle, const T & greater)
	{
		NTestLt(lesser, lesser);
		TestLt(lesser, middle);
		TestLt(lesser, greater);

		NTestLt(middle, lesser);
		NTestLt(middle, middle);
		TestLt(middle, greater);

		NTestLt(greater, lesser);
		NTestLt(greater, greater);
		NTestLt(greater, greater);
	}

	template<class T>
	void TestAllLtE(const T & lesser, const T & middle, const T & greater)
	{
		TestLtE(lesser, lesser);
		TestLtE(lesser, middle);
		TestLtE(lesser, greater);

		NTestLtE(middle, lesser);
		TestLtE(middle, middle);
		TestLtE(middle, greater);

		NTestLtE(greater, lesser);
		NTestLtE(greater, middle);
		TestLtE(greater, greater);
	}

	template<class T>
	void TestEq(const T & a, const T & b)
	{
		assert(a == b);
	}

	template<class T>
	void NTestEq(const T & a, const T & b)
	{
		assert(!(a == b));
	}

	template<class T>
	void TestNEq(const T & a, const T & b)
	{
		assert(a != b);
	}

	template<class T>
	void NTestNEq(const T & a, const T & b)
	{
		assert(!(a != b));
	}

	template<class T>
	void TestGt(const T & a, const T & b)
	{
		assert(a > b);
	}

	template<class T>
	void NTestGt(const T & a, const T & b)
	{
		assert(!(a > b));
	}

	template<class T>
	void TestGtE(const T & a, const T & b)
	{
		assert(a >= b);
	}

	template<class T>
	void NTestGtE(const T & a, const T & b)
	{
		assert(!(a >= b));
	}

	template<class T>
	void TestLt(const T & a, const T & b)
	{
		assert(a < b);
	}

	template<class T>
	void NTestLt(const T & a, const T & b)
	{
		assert(!(a < b));
	}

	template<class T>
	void TestLtE(const T & a, const T & b)
	{
		assert(a <= b);
	}

	template<class T>
	void NTestLtE(const T & a, const T & b)
	{
		assert(!(a <= b));
	}

}


#endif
