//CategorizedContactTests.h
//Written by Jesse Gibbons
#ifndef CATEGORIZED_CONTACT_TESTS_H
#define CATEGORIZED_CONTACT_TESTS_H
namespace test
{
	void TestCategorizedContact();
	void TestCategorizedContact_Constructor0();
	void TestCategorizedContact_Constructor1();
	void TestCategorizedContact_Constructor2();
	void TestCategorizedContact_GetCategory();
	void TestCategorizedContact_SetCategory();
	void TestCategorizedContact_ToString();
	void TestCategorizedContact_ToFileString();
	void TestCategorizedContact_ToFileString1();

	//operator<<

	void TestCategorizedContact_ToCout();
	void TestCategorizedContact_ToOstream();

	//operator>>

	void TestCategorizedContact_FromCin();
	void TestCategorizedContact_FromIstream();

	void TestCategorizedContact_AllComparison();
}
#endif