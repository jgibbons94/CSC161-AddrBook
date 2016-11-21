//NameTests.cpp
//Created by Jesse Gibbons
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Name.h"
using namespace AddrBookLib;

#include "Tests.h"
#include "NameTests.h"
#include "ComparisonTests.h"

void test::TestName()
{

	AnnounceTests("Name");
	TestName_Constructor0();
	TestName_Constructor1();
	TestName_Constructor2();
	TestName_GetFirstName();
	TestName_SetFirstName();
	TestName_GetLastName();
	TestName_SetLastName();
	TestName_ToString();
	TestName_ToFileString();
	TestName_ToFileString1();
	TestName_ToCout();
	TestName_ToOstream();
	TestName_FromCin();
	TestName_FromIstream();
	TestName_AllComparison();


	//TestName_equality0();
	//TestName_equality1();
	//TestName_equality2();
	//TestName_inequality0();
	//TestName_inequality1();
	//TestName_inequality2();
	//TestName_gt0();
	//TestName_gt1();
	//TestName_gt2();
	//TestName_gte0();
	//TestName_gte1();
	//TestName_gte2();
	//TestName_lt0();
	//TestName_lt1();
	//TestName_lt2();
	//TestName_lte0();
	//TestName_lte1();
	//TestName_lte2();
}

void test::TestName_Constructor0()
{
	AnnounceTests("Name constructor 0");
	Name name1;
	Name name2;
	name2.SetFirstName("");
	name2.SetFirstName("");
	assert(name1 == name2);
}

void test::TestName_Constructor1()
{
	AnnounceTests("Name constructor 1");
	Name name1("foo");
	Name name2;
	name2.SetFirstName("foo");
	name2.SetLastName("");
	assert(name1 == name2);
}

void test::TestName_Constructor2()
{
	AnnounceTests("Name Constructor 2");
	Name name1("foo", "bar");
	Name name2;
	name2.SetFirstName("foo");
	name2.SetLastName("bar");
	assert(name1 == name2);
}

void test::TestName_GetFirstName()
{
	AnnounceTests("Name Get First Name");
	Name name("foo");
	assert((name.GetFirstName() == "foo"));
}

void test::TestName_SetFirstName()
{
	AnnounceTests("Name Set First Name");
	Name name;
	name.SetFirstName("foo");
	assert(name.GetFirstName() == "foo");
}

void test::TestName_GetLastName()
{
	AnnounceTests("Name Get Last Name");
	Name name("", "bar");
	assert((name.GetLastName() == "bar"));
}

void test::TestName_SetLastName()
{
	AnnounceTests("Name Set Last Name");
	Name name;
	name.SetLastName("bar");
	assert(name.GetLastName() == "bar");
}

void test::TestName_ToString()
{
	AnnounceTests("Name To String");
	Name name("foo", "bar");
	assert(name.ToString() == "\t    Name:\tbar, foo\n");
}

void test::TestName_ToFileString()
{
	AnnounceTests("Name To File String");
	Name name("foo", "bar");
	assert(name.ToFileString() == "foo,bar,");
}

void test::TestName_ToFileString1()
{
	AnnounceTests("Name To File String 1");
	Name name("foo", "bar");
	assert(name.ToFileString(' ') == "foo bar ");
}

void test::TestName_ToCout()
{
	AnnounceTests("Name To Cout");
	//setup
	//In theory we should be able to change cout by changing _Ptr_cout.
	//Keep a temporary pointer to the old cout.
	ostream* tmpCout = _Ptr_cout;
	//set the current pointer to a new ostringStream
	ostringstream * strOut = new ostringstream();
	_Ptr_cout = strOut;
	//set up what we will test
	Field actual;
	Field expected = "\t    Name:\tPotter, Harry\n";
	Name aName("Harry", "Potter");
	//act
	//*strOut should look like std::cout.
	*strOut << aName;
	actual = strOut->str();
	//cleanup
	delete strOut;
	strOut = 0;
	_Ptr_cout = tmpCout;
	//assert
	assert(expected == actual);
}

void test::TestName_ToOstream()
{

	AnnounceTests("Name To Ostream");
	//setup

	ostringstream out;
	//set up what we will test
	Field actual;
	Field expected = "Harry,Potter,";
	Name aName("Harry", "Potter");
	//act
	out << aName;
	actual = out.str();
	//assert
	assert(expected == actual);
}

void test::TestName_FromCin()
{
	AnnounceTests("Name From Cin");

	//setup
	istream* tmpCin = _Ptr_cin;

	//set the current pointer to a new ostringStream
	istringstream * strIn = new istringstream("Harry\nPotter");
	_Ptr_cin = strIn;



	//set up what we will test
	Name expected("Harry", "Potter");
	Name actual;
	//act

	//*strOut should look like std::cout.

	*strIn >> actual;
	//cleanup
	delete strIn;
	strIn = 0;
	_Ptr_cin = tmpCin;


	//assert
	assert(expected == actual);

}

void test::TestName_FromIstream()
{
	AnnounceTests("Name From Cin");
	//setup
	istringstream in("Harry,Potter");
	Name expected("Harry", "Potter");
	Name actual;
	//act
	in >> actual;
	//assert
	assert(expected == actual);
}

void test::TestName_AllComparison()
{
	AnnounceTests("Name comparisons");
	Name a("Alice", "Andersen"), b("Blake", "Buster"), c("Catherine", "Coolidge");
	RunAllInEqTests(a, b, c);
}

//void test::TestName_equality0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert(!(a == b));
//}
//
//void test::TestName_equality1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(a == b);
//}
//
//void test::TestName_equality2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(!(a == b));
//}
//
//void test::TestName_inequality0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert(a != b);
//}
//
//void test::TestName_inequality1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(!(a != b));
//}
//
//void test::TestName_inequality2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(a != b);
//}
//
//void test::TestName_gt0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert(!(a > b));
//}
//
//void test::TestName_gt1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(!(a > b));
//}
//
//void test::TestName_gt2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(a > b);
//}
//
//void test::TestName_gte0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert(!(a >= b));
//}
//
//void test::TestName_gte1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(a >= b);
//}
//
//void test::TestName_gte2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(a >= b);
//}
//
//void test::TestName_lt0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert(a < b);
//}
//
//void test::TestName_lt1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(!(a < b));
//}
//
//void test::TestName_lt2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(!(a < b));
//}
//
//void test::TestName_lte0()
//{
//	Name a("Alice", "Andersen"), b("Blake", "Buster");
//	assert((a <= b));
//}
//
//void test::TestName_lte1()
//{
//	Name a("Blake", "Buster"), b("Blake", "Buster");
//	assert(a <= b);
//}
//
//void test::TestName_lte2()
//{
//	Name a("Catherine", "Coolidge"), b("Blake", "Buster");
//	assert(!(a <= b));
//}
//
