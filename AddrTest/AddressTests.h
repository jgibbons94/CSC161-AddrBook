//AddressTests.h
//Written by Jesse Gibbons
#ifndef ADDRESS_TESTS_H
#define ADDRESS_TESTS_H
namespace test
{
	void TestAddress();
	void TestAddress_Constructor0();
	void TestAddress_Constructor1();
	void TestAddress_Constructor2();
	void TestAddress_Constructor3();
	void TestAddress_Constructor4();
	
	void TestAddress_GetStreetAddress();
	void TestAddress_SetStreetAddress();
	
	void TestAddress_GetCity();
	void TestAddress_SetCity();
	
	void TestAddress_GetState();
	void TestAddress_SetState();
	
	void TestAddress_GetZip();
	void TestAddress_SetZip();
	
	void TestAddress_ToString();

	void TestAddress_ToFileString();
	void TestAddress_ToFileString1();

	//operator<<

	void TestAddress_ToCout();
	void TestAddress_ToOstream();

	//operator>>

	void TestAddress_FromCin();
	void TestAddress_FromIstream();
}
#endif