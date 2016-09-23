//MyFuncs.cpp
//Written by Jesse Gibbons
#include <iostream>
#include <string>
using namespace std;
#include "MyFuncs.h"
using namespace AddrBookLib;


std::string AddrBookLib::Prompt(std::string strPrompt)
{
	string response = "";
	cout << strPrompt;
	getline(cin, response);
	return response;
}
bool AddrBookLib::GetField(std::ifstream & fileIn, string & outField, char delimeter)
{
	if (!fileIn)
	{
		return false;
	}
	getline(fileIn, outField, delimeter);
	if (fileIn.peek() == delimeter)
		fileIn.ignore();
	return true;
}