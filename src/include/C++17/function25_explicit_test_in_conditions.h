#pragma once
#include "../import.h"

int square(int val) {
	return val * val;
}

std::string function_25_explicit_test_in_conditions(){
  // 25. Explicit Test In Conditions
	std::string toReturn = "";
    toReturn += "######### 25 Explicit Test In Conditions ############\n\n";
	
	toReturn += "You can make assignement in conditions\n\n"
		"if(auto p = foo(10); p < 10){\n"
		"    //p usable\n"
		"}\n"
		"//p is destroyed at the end of the if condition scope\n\n";
	
	if (auto p = square(10); p > 10)
		int i = square(p); // p usable
	// p destroyed

	toReturn += "It's equal to : \n"
		"{\n"
		"    auto p = foo(10); // p usable\n"
		"    if(p(10) > 10)\n"
		"        {...}	//In condition\n"
		"    // p usable\n"
		"} // p not usable\n\n";

	return toReturn;
}