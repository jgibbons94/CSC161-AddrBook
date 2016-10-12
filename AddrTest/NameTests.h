//NameTests.h
//Written by Jesse Gibbons
#ifndef NAME_TESTS_H
#define NAME_TESTS_H
namespace test
{
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
	void TestName_ToCout();
	void TestName_ToOstream();
	void TestName_FromCin();
	void TestName_FromIstream();
	//comparison tests:
	//0: A <  B
	//1: A == B
	//2: A  > B
	void TestName_equality0();
	void TestName_equality1();
	void TestName_equality2();
	void TestName_inequality0();
	void TestName_inequality1();
	void TestName_inequality2();
	void TestName_gt0();
	void TestName_gt1();
	void TestName_gt2();
	void TestName_gte0();
	void TestName_gte1();
	void TestName_gte2();
	void TestName_lt0();
	void TestName_lt1();
	void TestName_lt2();
	void TestName_lte0();
	void TestName_lte1();
	void TestName_lte2();
}
#endif