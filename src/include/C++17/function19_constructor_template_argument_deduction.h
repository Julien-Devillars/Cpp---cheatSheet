#pragma once
#include "../import.h"
#include <utility>


std::string function_19_constructor_template_argument_deduction(){
  // 19. constructor_template_argument_deduction
	std::string toReturn = "";
    toReturn += "######### 19 Constructor Template Argument Deduction ############\n\n";
	
    std::pair<std::string, int> p0(std::string(" Hi !"), 129); // no deduction
    auto p1 = std::make_pair(std::string(" Hey !"), 291); // p1 is a pair < string , int >
    std::pair p2(std::string(" Yo !"), 921); // error under c++ 17: template arguments missing for pair
    
    toReturn +=
        "std::pair<std::string, int> p0(std::string(\" Hi !\"), 129); // no deduction\n"
        "auto p1 = std::make_pair(std::string(\" Hey !\"), 291); // p1 is a pair < string , int >\n"
        "std::pair p2(std::string(\" Yo !\"), 921); // error under c++ 17: template arguments missing for pair\n\n";

    toReturn += "0 : [" + p0.first + "] = " + std::to_string(p0.second) + "\n";
    toReturn += "1 : [" + p1.first + "] = " + std::to_string(p1.second) + "\n";
    toReturn += "2 : [" + p2.first + "] = " + std::to_string(p2.second) + "\n";

	return toReturn;
}