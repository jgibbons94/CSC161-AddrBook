#include <cassert>
using namespace std;
#include "AddressTests.h"
#include "Address.h"
using namespace AddrBookLib;
void test::TestAddress()
{
	TestAddress_Constructor0();
	TestAddress_Constructor1();
	TestAddress_Constructor2();
	TestAddress_Constructor3();
	TestAddress_Constructor4();
	TestAddress_GetStreetAddress();
	TestAddress_SetStreetAddress();
	TestAddress_GetCity();
	TestAddress_SetCity();
	TestAddress_GetState();
	TestAddress_SetState();
	TestAddress_GetZip();
	TestAddress_SetZip();
	TestAddress_ToString();
	TestAddress_ToFileString();
	TestAddress_ToFileString1();
}

void test::TestAddress_Constructor0()
{
	Address addr;
	assert((addr.GetStreetAddress() == "") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor1()
{
	Address addr("Street");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor2()
{
	Address addr("Street", "City");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor3()
{
	Address addr("Street", "City", "State");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == ""));
}

void test::TestAddress_Constructor4()
{
	Address addr("Street", "City", "State", "Zip");
	assert((addr.GetStreetAddress() == "Street") && (addr.GetCity() == "City") && (addr.GetState() == "State") && (addr.GetZip() == "Zip"));
}

void test::TestAddress_GetStreetAddress()
{
	Address addr("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_SetStreetAddress()
{
	Address addr;
	addr.SetStreetAddress("Street");
	assert(addr.GetStreetAddress() == "Street");
}

void test::TestAddress_GetCity()
{
	Address addr("", "City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_SetCity()
{
	Address addr;
	addr.SetCity("City");
	assert(addr.GetCity() == "City");
}

void test::TestAddress_GetState()
{
	Address addr("", "", "State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_SetState()
{
	Address addr;
	addr.SetState("State");
	assert(addr.GetState() == "State");
}

void test::TestAddress_GetZip()
{
	Address addr("", "", "", "Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_SetZip()
{
	Address addr;
	addr.SetZip("Zip");
	assert(addr.GetZip() == "Zip");
}

void test::TestAddress_ToString()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToString();
	assert(fld == "1\n\t\t\t2, 3 4");
}

void test::TestAddress_ToFileString()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToFileString();
	assert(fld == "1,2,3,4");
}

void test::TestAddress_ToFileString1()
{
	Address addr("1", "2", "3", "4");
	Field fld = addr.ToFileString(' ');
	assert(fld == "1 2 3 4");
}
