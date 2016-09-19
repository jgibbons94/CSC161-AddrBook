#include <iostream>
#include <string>
#include "MyFuncs.h"


std::string helperFuncs::prompt(std::string strPrompt)
{
	using namespace std;
	string response = "";
	cout << strPrompt;
	getline(cin, response);
	return response;
}
