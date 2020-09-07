#pragma once
#include "import.h"

std::string function_9_raw_literals(){
  // 9. Raw Literals
	std::string toReturn = "";
    toReturn += "######### 9 Raw Literals ############\n\n";
	
	toReturn += "Using R\"(myString)\" instead of a normal string => avoid theuse of backslash";

    toReturn += "\" in double quote  \" + \\ 1 backslash\n";
    toReturn += R"(\" in double quote & backslash  \" + \\ 2 backslash\n)";

	return toReturn;
}
