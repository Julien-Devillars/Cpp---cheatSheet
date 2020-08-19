#pragma once
#include "import.h"


void function_auto() {
	// autoa
	print("###### Auto ######");
	auto i = 7;   // int
	auto d = 7.2; // double
	auto f = 7.2f; // double

	std::cout << i << " is " << typeid(i).name() << std::endl;
	std::cout << d << " is " << typeid(d).name() << std::endl;
	std::cout << f << " is " << typeid(f).name() << std::endl;
}

void function_decltype() {
	print("###### Decltype ######");

	// decltype
	int val = 3;
	decltype(val) value = (decltype(val)) 10.5;

	std::cout << value << " is "  << typeid(val).name() << std::endl;
}


void function_1_auto_decltype() {

	// 1 auto & decltype
	print("######### 1 Auto & Decltype ############");

	function_auto();
	function_decltype();
}