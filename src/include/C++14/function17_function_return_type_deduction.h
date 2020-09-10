#pragma once
#include "../import.h"


struct A17 {
	int first;
};

struct B17 {
	std::string first;
};

template < typename T >
auto get(const T& a) { return a.first; }

std::string function_17_function_return_type_deduction(){
  // 17. function return type deduction 
	std::string toReturn = "";
    toReturn += "######### 17 Function Return Type Deduction ############\n\n";
	
	toReturn +=
		"C++11 had introduced the ability to deduce the return "
		"type of a lambda from its return statement.\n"
		"C++14 extended that to functions\n\n";

	toReturn +=
		"template < typename T >\n"
		"auto get(const T & a) { return a.first; }\n\n";

	A17 a;
	B17 b;
	a.first = 3;
	b.first = "test";

	auto getA = get<decltype(a)>(a);
	auto getB = get<decltype(b)>(b);

	toReturn += std::to_string(getA) + " : int deduced\n";
	toReturn += getB + " : string deduced\n";

	return toReturn;
}