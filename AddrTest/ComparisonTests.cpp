//ComparisonTests.cpp
//Written by Jesse Gibbons
#include "ComparisonTests.h"
#include "Tests.h"
void test::TestTemplateInEqTests()
{
	AnnounceTests("Template Inequality Tests");
	RunAllInEqTests(1, 2, 3);
	RunAllInEqTests(1u, 2u, 3u);
	RunAllInEqTests(1l, 2l, 3l);
	RunAllInEqTests(1ul, 2ul, 3ul);
	RunAllInEqTests(1ll, 2ll, 3ll);
	RunAllInEqTests(1ull, 2ull, 3ull);
	RunAllInEqTests('11', '22', '33');
	RunAllInEqTests('1', '2', '3');

}
