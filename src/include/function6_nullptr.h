#pragma once
#include "import.h"

std::string function_6_nullptr(){
  // 6. nullptr
	std::string toReturn = "";
    toReturn += "######### 6 Nullptr ############\n\n";

    toReturn += "Initialize a pointer to null value \n";

    int* p0 = 0; // == int* ptr = nullptr
    int* p1 = nullptr;
    int* p2 = NULL; // OK for compatibility
    
    toReturn += " - int* ptr = 0\n";
    toReturn += " - int* ptr = nullptr \n";
    toReturn += " - int* ptr = NULL (Ok for compatibility)\n";
		
	return toReturn;
}