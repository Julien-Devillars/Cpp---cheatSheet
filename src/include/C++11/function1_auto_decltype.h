#pragma once
#include "../import.h"


std::string function_auto() {
	// autoa
	std::string toReturn = "";
	toReturn += "###### Auto ######\n\n";
	auto i = 7;   // int
	auto d = 7.2; // double
	auto f = 7.2f; // double

	toReturn += std::to_string(i) + " is " + typeid(i).name() + "\n";
	toReturn += std::to_string(d) + " is " + typeid(d).name() + "\n";
	toReturn += std::to_string(f) + " is " + typeid(f).name() + "\n";
	
	return toReturn;
}

std::string function_decltype() {
	std::string toReturn = "";
	toReturn += "###### Decltype ######\n\n";

	// decltype
	int val = 3;
	decltype(val) value = (decltype(val)) 10.5;

	toReturn += std::to_string(value) + " is "  + typeid(val).name() + "\n";
	
	return toReturn;
}


std::string function_1_auto_decltype() {

	// 1 auto & decltype
	std::string toReturn = "";
	toReturn += "######### 1 Auto & Decltype ############\n\n";

	toReturn += function_auto();
	toReturn += "\n";
	toReturn += function_decltype();
	
	return toReturn;
}