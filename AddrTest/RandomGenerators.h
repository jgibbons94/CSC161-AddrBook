#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR
#include <string>

#include "CategorizedContact.h"

namespace test
{
	template<class T> using GeneratorCallback = T(*)() ;
	int GenerateLowRandomNumber();
	int GenerateMediumRandomNumber();
	int GenerateHighRandomNumber();

	std::string GenerateLowRandomString();
	std::string GenerateMediumRandomString();
	std::string GenerateHighRandomString();

	AddrBookLib::CategorizedContact GenerateLowRandomCategorizedContact();
	AddrBookLib::CategorizedContact GenerateMediumRandomCategorizedContact();
	AddrBookLib::CategorizedContact GenerateHighRandomCategorizedContact();

}

#endif
