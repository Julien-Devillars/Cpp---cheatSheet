#pragma once
#include "../import.h"


using foo = int (*) (int, int);
// the name 'foo' now denotes a pointer to function:
int bar1(int a, int b) { return a + b; }
int bar2(int a, int b) { return a * b; }
foo f = bar1;

template<class T>
using ptr = T;

template<class T>
std::string myPrint13(T val)
{
	return val ;
}

std::string function_13_aliases(){
  // 13. aliases
	std::string toReturn = "";
    toReturn += "######### 13 Aliases ############\n\n";
	
	toReturn += "alias are identical to typedef void (*func)(int, int)\n\n";
	
	toReturn += "using foo = int (*) (int, int); // Alias\n\n"
		"int bar1(int a, int b) { return a + b; }\n"
		"int bar2(int a, int b) { return a * b; }\n\n"
		"foo f = bar1;\n"
		"f(2, 10) = ";

		toReturn += std::to_string(f(2, 10)) + "\n";   // 2 + 10

		f = bar2;

		toReturn += 
			"\nf = bar2\n"
			"f(2, 10) = ";

		toReturn += std::to_string(f(2, 10)) + "\n";   // é * 10

	return toReturn;
}