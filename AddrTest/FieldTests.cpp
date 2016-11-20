//FieldTests.cpp
//Created by Jesse Gibbons

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include "Field.h"
using namespace AddrBookLib;
#include "Tests.h"
#include "FieldTests.h"
#include "ComparisonTests.h"
void test::TestField()
{
	AnnounceTests("Field");
	TestField_Constructor0();
	TestField_ConstructorString();
	TestField_ConstructrCharPtr();
	TestField_Shift_Istream();
	TestField_Shift_Ifstream();
	TestField_AllComparison();
}

void test::TestField_Constructor0()
{
	AnnounceTests("Field constructor 0");
	Field fld;
	assert(fld == "");
}

void test::TestField_ConstructrCharPtr()
{
	AnnounceTests("Field constructor with character pointer");
	Field fld("char");
	assert(fld == "char");
}

void test::TestField_ConstructorString()
{
	AnnounceTests("Field constructor with string");
	string str = "str";
	Field fld(str);
	assert(fld == "str");
}

void test::TestField_Shift_Istream()
{
	AnnounceTests("Field istream shift");
	Field fld;
	istringstream iss("line 1 \n line 2 ");
	istream * tmpIn = _Ptr_cin;
	_Ptr_cin = &iss;
	iss >> fld;
	_Ptr_cin = tmpIn;
	assert(fld == "line 1 ");
}

void test::TestField_Shift_Ifstream()
{
	AnnounceTests("Field ifstream shift");
	Field fld;
	ofstream ofs;
	ifstream ifs;
	ofs.open("test.csv");
	if (!ofs)
	{
		cerr << "Could not open file test.csv to write." << endl;
		return;
	}
	ofs << "item1,item2";
	ofs.close();
	ifs.open("test.csv");
	if (!ifs)
	{
		cerr << "Could not open file test.csv to read." << endl;
		return;
	}
	ifs >> fld;
	ifs.close();
	remove("test.csv");
	assert(fld == "item1");

}

void test::TestField_AllComparison()
{
	AnnounceTests("Field comparison");
	Field a("Alice"),
		b("Bob"),
		c("Catherine");
	RunAllInEqTests(a, b, c);
}
