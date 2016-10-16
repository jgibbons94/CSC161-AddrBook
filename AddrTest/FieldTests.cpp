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

#include "FieldTests.h"
void test::TestField()
{
	TestField_Constructor0();
	TestField_ConstructorString();
	TestField_ConstructrCharPtr();
	TestField_Shift_Istream();
	TestField_Shift_Ifstream();
}

void test::TestField_Constructor0()
{
	Field fld;
	assert(fld == "");
}

void test::TestField_ConstructrCharPtr()
{
	Field fld("char");
	assert(fld == "char");
}

void test::TestField_ConstructorString()
{
	string str = "str";
	Field fld(str);
	assert(fld == "str");
}

void test::TestField_Shift_Istream()
{
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
