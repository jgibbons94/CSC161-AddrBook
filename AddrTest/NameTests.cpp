#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Name.h"
using namespace AddrBookLib;

#include "NameTests.h"

void test::TestName()
{
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
	TestName_equality0();
	TestName_equality1();
	TestName_equality2();
	TestName_inequality0();
	TestName_inequality1();
	TestName_inequality2();
	TestName_gt0();
	TestName_gt1();
	TestName_gt2();
	TestName_gte0();
	TestName_gte1();
	TestName_gte2();
	TestName_lt0();
	TestName_lt1();
	TestName_lt2();
	TestName_lte0();
	TestName_lte1();
	TestName_lte2();
}

void test::TestName_Constructor0()
{
	Name name;
	assert((name.GetFirstName() == "") && (name.GetLastName() == ""));
}

void test::TestName_Constructor1()
{
	Name name("foo");
	assert((name.GetFirstName() == "foo") && (name.GetLastName() == ""));
}

void test::TestName_Constructor2()
{
	Name name("foo", "bar");
	assert((name.GetFirstName() == "foo") && (name.GetLastName() == "bar"));
}

void test::TestName_GetFirstName()
{
	Name name("foo");
	assert((name.GetFirstName() == "foo"));
}

void test::TestName_SetFirstName()
{
	Name name;
	name.SetFirstName("foo");
	assert(name.GetFirstName() == "foo");
}

void test::TestName_GetLastName()
{
	Name name("", "bar");
	assert((name.GetLastName() == "bar"));
}

void test::TestName_SetLastName()
{
	Name name;
	name.SetLastName("bar");
	assert(name.GetLastName() == "bar");
}

void test::TestName_ToString()
{
	Name name("foo", "bar");
	assert(name.ToString() == "bar, foo");
}

void test::TestName_ToFileString()
{
	Name name("foo", "bar");
	assert(name.ToFileString() == "foo,bar");
}

void test::TestName_ToFileString1()
{
	Name name("foo", "bar");
	assert(name.ToFileString(' ') == "foo bar");
}

void test::TestName_ToCout()
{
	//setup
	//In theory we should be able to change cout by changing _Ptr_cout.
	//Keep a temporary pointer to the old cout.
	ostream* tmpCout = _Ptr_cout;
	//set the current pointer to a new ostringStream
	ostringstream * strOut = new ostringstream();
	_Ptr_cout = strOut;
	//set up what we will test
	Field actual;
	Field expected = "Harry Potter";
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
{	//setup

	ostringstream out;
	//set up what we will test
	Field actual;
	Field expected = "Potter,Harry,";
	Name aName("Harry", "Potter");
	//act
	out << aName;
	actual = out.str();
	//assert
	assert(expected == actual);
}

void test::TestName_FromCin()
{

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
	//setup
	istringstream in("Potter,Harry");
	Name expected("Harry", "Potter");
	Name actual;
	//act
	in >> actual;
	//assert
	assert(expected == actual);
}

void test::TestName_equality0()
{
	cerr << "Unimplemented test: TestName_equality0()" << endl;
}

void test::TestName_equality1()
{
	cerr << "Unimplemented test: TestName_equality1()" << endl;
}

void test::TestName_equality2()
{
	cerr << "Unimplemented test: TestName_equality2()" << endl;
}

void test::TestName_inequality0()
{
	cerr << "Unimplemented test: TestName_inequality0()" << endl;
}

void test::TestName_inequality1()
{
	cerr << "Unimplemented test: TestName_inequality1()" << endl;
}

void test::TestName_inequality2()
{
	cerr << "Unimplemented test: TestName_inequality2()" << endl;
}

void test::TestName_gt0()
{
	cerr << "Unimplemented test: TestName_gt0()" << endl;
}

void test::TestName_gt1()
{
	cerr << "Unimplemented test: TestName_gt1()" << endl;
}

void test::TestName_gt2()
{
	cerr << "Unimplemented test: TestName_gt2()" << endl;
}

void test::TestName_gte0()
{
	cerr << "Unimplemented test: TestName_gte0()" << endl;
}

void test::TestName_gte1()
{
	cerr << "Unimplemented test: TestName_gte1()" << endl;
}

void test::TestName_gte2()
{
	cerr << "Unimplemented test: TestName_gte2()" << endl;
}

void test::TestName_lt0()
{
	cerr << "Unimplemented test: TestName_lt0()" << endl;
}

void test::TestName_lt1()
{
	cerr << "Unimplemented test: TestName_lt1()" << endl;
}

void test::TestName_lt2()
{
	cerr << "Unimplemented test: TestName_lt2()" << endl;
}

void test::TestName_lte0()
{
	cerr << "Unimplemented test: TestName_lte0()" << endl;
}

void test::TestName_lte1()
{
	cerr << "Unimplemented test: TestName_lte1()" << endl;
}

void test::TestName_lte2()
{
	cerr << "Unimplemented test: TestName_lte2()" << endl;
}
