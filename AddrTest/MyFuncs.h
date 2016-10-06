//MyFuncs.h
//Written by Jesse Gibbons
#ifndef MY_FUNCS_H
#define MY_FUNCS_H
#include <string>
#include <fstream>
#include "AddrBook.h"
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
	//send strPrompt to the user, return result.
	Field Prompt(Field fldPrompt);
	//Get a field from the stream's current position to the delimeter, then ignore the delimeter.
	// bool GetField(std::ifstream & fileIn, string & outField, char delimeter = ',');
	//check if min <= value <= max
	 inline bool InRange(int value, int min, int max) { return (value >= min && value <= max); }
	//Send the options to the user, retrieve the user's response in a standard result as the number of the chosen option.
	//User can send a number (required for the project) or a case-insensitive letter, specified in parentheses in the option list.
	// int GetResponseFromMenu();
	//Ask the user which contact to delete from the console.
	// int GetContactToDeleteFromConsole(const AddrBook & book);
	//clears whitespace from the console.
	//use only before << or getline(). Plugs up the program if used in other places.
	// void ClearConsoleInput();
}

#endif