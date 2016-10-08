//Test.h
//Written by Jesse Gibbons
#ifndef TESTS_H
#define TESTS_H
namespace test
{
	// behind the scenes rigorous tests
	// main() calls these tests and exits if NO_TESTS is not defined.

	void TestAll();

	// AddrBook class
	void TestAddrBook();
	void TestAddrBook_AddContact();
	void TestAddrBook_RemoveContact();
	void TestAddrBook_FindItem();
	void TestAddrBook_RemoveByIndex();
	void TestAddrBook_GetUsed();
	void TestAddrBook_GetContact();
	void TestAddrBook_ReadFile();
	void TestAddrBook_WriteFile();

	//Address class
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


	// CategorizedContact class
	void TestCategorizedContact();
	void TestCategorizedContact_Constructor0();
	void TestCategorizedContact_Constructor1();
	void TestCategorizedContact_Constructor2();
	void TestCategorizedContact_GetCategory();
	void TestCategorizedContact_SetCategory();
	void TestCategorizedContact_ToString();
	void TestCategorizedContact_ToFileString();
	void TestCategorizedContact_ToFileString1();

	//Contact class
	void TestContact();
	void TestContact_Constructor0();
	void TestContact_Constructor1();
	void TestContact_Constructor2();
	void TestContact_Constructor3();
	void TestContact_Constructor4();
	void TestContact_Constructor5();
	void TestContact_Constructor6();
	void TestContact_GetFullName();
	void TestContact_SetFullName();
	void TestContact_GetFullAddress();
	void TestContact_SetFullAddress();
	void TestContact_GetPhone();
	void TestContact_SetPhone();
	void TestContact_GetEmail();
	void TestContact_SetEmail();
	void TestContact_GetBirthday();
	void TestContact_SetBirthday();
	void TestContact_GetPictureFile();
	void TestContact_SetPictureFile();
	void TestContact_ToString();
	void TestContact_ToFileString();
	void TestContact_ToFileString1();

	//Field class
	void TestField();
	void TestField_Constructor0();
	void TestField_ConstructorString();
	void TestField_ConstructrCharPtr();
	void TestField_Shift_Istream();
	void TestField_Shift_Ifstream();

	//Name class
	void TestName();
	void TestName_Constructor0();
	void TestName_Constructor1();
	void TestName_Constructor2();
	void TestName_GetFirstName();
	void TestName_SetFirstName();
	void TestName_GetLastName();
	void TestName_SetLastName();
	void TestName_ToString();
	void TestName_ToFileString();
	void TestName_ToFileString1();
}
#endif //TESTS_H
