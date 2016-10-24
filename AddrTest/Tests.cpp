//Tests.cpp
//Created by Jesse Gibbons
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "Tests.h"
#include "FieldTests.h"
#include "NameTests.h"
#include "AddressTests.h"
#include "ContactTests.h"
#include "CategorizedContactTests.h"
#include "AddrBookTests.h"
#include "ComparisonTests.h"
using namespace test;

#include "Field.h"
#include "Field.h"
#include "Address.h"
#include "Contact.h"
#include "CategorizedContact.h"
#include "AddrBook.h"
using namespace AddrBookLib;

void test::TestAll()
{
	//make sure template tests work
	TestTemplateInEqTests();


	TestField();
	TestName();
	TestAddress();
	TestContact();
	TestCategorizedContact();
	TestAddrBook();
}
