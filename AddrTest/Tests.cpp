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
//#include "AddrBookTests.h"
#include "ComparisonTests.h"
#include "NodeTests.h"
//#include "LinkListTests.h"
#include "BinTreeTests.h"
using namespace test;

#include "Field.h"
#include "Field.h"
#include "Address.h"
#include "Contact.h"
#include "CategorizedContact.h"
//#include "AddrBook.h"
using namespace AddrBookLib;

void test::TestAll()
{
	AnnounceTests("All");
	//make sure template tests work
	TestTemplateInEqTests();


	TestField();
	TestName();
	TestAddress();
	TestContact();
	TestCategorizedContact();
	TestNode<int>(3, 100);
	TestNode<std::string>("This is a test string", "This is a second string.");
	TestBinTree<int>(GenerateLowRandomNumber, GenerateMediumRandomNumber, GenerateHighRandomNumber);
	TestBinTree<string>(GenerateLowRandomString, GenerateMediumRandomString, GenerateHighRandomString);
	TestBinTree<CategorizedContact>(GenerateLowRandomCategorizedContact, GenerateMediumRandomCategorizedContact, GenerateHighRandomCategorizedContact);
	//	TestAddrBook();
}
