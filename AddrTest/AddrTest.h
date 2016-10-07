//MyFuncs.h
//Written by Jesse Gibbons
#ifndef MY_FUNCS_H
#define MY_FUNCS_H
#include <string>
#include <fstream>
#include "AddrBook.h"
namespace AddrBookLib
{
	inline bool InRange(int value, int min, int max) { return (value >= min && value <= max); }
	//check if min <= value <= max

}

#endif
