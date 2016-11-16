//Tests.h
//Written by Jesse Gibbons
#ifndef TESTS_H
#define TESTS_H
#include <string>
#include <iostream>
namespace test
{
	// behind the scenes rigorous tests
	// main() calls these tests and exits if RUN_TESTS is not defined.

	void TestAll();

	inline void ReportMissingTest(std::string functionName)
	{
		std::cerr << "Test not yet implemented: " << functionName << "()" << std::endl;
	}

}
#endif //TESTS_H
