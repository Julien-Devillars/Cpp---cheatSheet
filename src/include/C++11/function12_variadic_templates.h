#pragma once
#include "../import.h"
#include <iostream>

template<class T>
void myPrint(T value) {
	std::cout << value << "\n";
}

template<class T, class ...Args>
void myPrint(T value, Args... args) {
	myPrint(value); // draw the first parameter
	myPrint(args...); // recursive call for next parameters
}


std::string function_12_variadic_templates(){
  // 12. Variadic templates
	std::string toReturn = "";
    std::cout << "######### 12 Variadic Templates ############\n\n";
	std::cout << 
		"A feature called variadic templates[Gregor et al. 2004] to directly addresses two problems :\n\n"
		" - The inability to instantiate class and function templates with an arbitrarily - long list of template parameters.\n"
		" - The inability to pass an arbitrary number of arguments to a function in a type - safe manner.\n\n";

	std::cout << "I create my print function which is called\n "
		"myPrint<int, std::string, char, double>(3, \"test12\", 'c', 3.14) : \n\n";

	myPrint<int, std::string, char, double>(3, "test12", 'c', 3.14);

	std::cout << "\nthe Template Argument (<T, ...Args>) are deducted since C++17, you can avoid them\n"
		"myPrint(1,2,\"test\",3.13,5.f,10ll) : \n\n";
	
	myPrint(1,2,"test",3.13,5.f,10ll);

	std::cout << std::endl;

	//myPrint<int,std::string,char,double>(3.13,333,'c',3.14); // Compilater error, second parameter not string

	return toReturn;
}