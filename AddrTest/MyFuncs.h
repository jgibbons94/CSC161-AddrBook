//MyFuncs.h
//Written by Jesse Gibbons
#ifndef MY_FUNCS_H
#define MY_FUNCS_H
#include <string>
#include <fstream>
namespace AddrBookLib
{
	/*
		std::string prompt(std::string strPrompt);
		Prompts the user with the given prompt, and returns the user's answer.
		If STDIN is piped from a file, or STDOUT is piped to a file, this could fail.
		Parameters:
		std::string strPrompt - a prompt for user input.
		Example: "Please enter the first name: "
		prints:
		Please enter the first name:
		The program then waits for the user to type in an answer and returns the entire line of user input.
		If STDIN is piped from a file, it reads the next line from the file rather than from the user's input.
			If STDIN is piped from /dev/zero, this function may lock.
		If STDOUT is piped to a file, the prompt is written to that file rather than the console.

	*/
	std::string Prompt(std::string strPrompt);
	bool GetField(std::ifstream & fileIn, string & outField, char delimeter = ',');
}

#endif