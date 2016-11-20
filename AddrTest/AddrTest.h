//AddrTest.h
//Written by Jesse Gibbons
#ifndef MY_FUNCS_H
#define MY_FUNCS_H
#include <string>
#include <fstream>
//#include "AddrBook.h"
namespace AddrBookLib
{
	//check if min <= value <= max
	inline bool InRange(int value, int min, int max) { return (value >= min && value <= max); }
	//get a category from the user by displaying a menu to cout and getting input from in.
	Field GetCategoryFromUser(bool get = false, Field fldDefault = "Other", std::istream & in = std::cin);
	//delay for the specified number of miliseconds
	void Delay(int milliseconds = 2000);
	//check if the given ostream is a standard ostream (cout, cerr, clog)
	inline bool IsStandardOstream(const ostream * const os) { return os == std::_Ptr_cout || os == _Ptr_cerr || os == _Ptr_clog; }
	//check if the given istream is a standard istream (cin).
	inline bool IsStandardIstream(const istream * const is) { return is == std::_Ptr_cin; }
}

#endif
