#include "RandomGenerators.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include "Name.h"
#include "Contact.h"
#include "CategorizedContact.h"
using namespace std;
using namespace AddrBookLib;

void seed()
{
	//If I remember C++ semester 1, a static int in a function is like a global variable, but can only be accessed through that function.
	static int random_seeded = 0;
	if (random_seeded == 0)
	{
		random_seeded++;
		std::srand((unsigned int)std::time(nullptr));
	}
}
int test::GenerateLowRandomNumber()
{
	seed();
	return std::rand() % 50 - 100;
}

int test::GenerateMediumRandomNumber()
{
	seed();
	return std::rand() % 50;
}

int test::GenerateHighRandomNumber()
{
	seed();
	return std::rand() % 50 + 100;
}

std::string test::GenerateLowRandomString()
{
	seed();
	std::string lowStrings[] = { "Apple","Acrophobia","Arachnophobia","Aphid","Aardvark","Basilisk","Before","Beyond","Batman","Banana", "Boomerang""Cow","Crane","Clinton","Cookie" };
	return lowStrings[rand() % sizeof(lowStrings)];
}

std::string test::GenerateMediumRandomString()
{
	seed();
	std::string lowStrings[] = { "Monkey","Microphone","Mickey","Mouse","Marvin","Nancy","Nothing","Nathan","Noob","Necromancer","Octopus","Octogon","Orange" };
	return lowStrings[rand() % sizeof(lowStrings)];
}

std::string test::GenerateHighRandomString()
{
	seed();
	std::string lowStrings[] = { "Monkey","Microphone","Mickey","Mouse","Marvin","Nancy","Nothing","Nathan","Noob","Necromancer","Octopus","Octogon","Orange" };
	return lowStrings[rand() % sizeof(lowStrings)];
}

AddrBookLib::CategorizedContact test::GenerateLowRandomCategorizedContact()
{
	seed();
	return AddrBookLib::CategorizedContact(AddrBookLib::Contact(Name(GenerateLowRandomString(), GenerateLowRandomString())));
}

AddrBookLib::CategorizedContact test::GenerateMediumRandomCategorizedContact()
{
	seed();
	return AddrBookLib::CategorizedContact(AddrBookLib::Contact(Name(GenerateMediumRandomString(), GenerateMediumRandomString())));
}

AddrBookLib::CategorizedContact test::GenerateHighRandomCategorizedContact()
{
	seed();
	return AddrBookLib::CategorizedContact(AddrBookLib::Contact(Name(GenerateHighRandomString(), GenerateHighRandomString())));
}
