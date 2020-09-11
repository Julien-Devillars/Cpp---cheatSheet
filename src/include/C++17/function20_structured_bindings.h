#pragma once
#include "../import.h"
#include "../C++11/function14_tuples.h"
#include <vector>

std::string function_20_structure_bindings(){
  // 20. structure bindings
	std::string toReturn = "";
    toReturn += "######### 20 Structure Bindings ############\n\n";
	
    toReturn += "Structured Bindings extends the ability of break an object into N values to cope  "
        "with types that are not tuples or plain structs\n\n";

    toReturn += "Using the third example from the functiion 14 (tuples) : \n";

    toReturn += " auto [gpa2, grade2, name2] = get_student(2);\n\n";
    auto [gpa2, grade2, name2] = get_student(2);
    toReturn +="ID: 2, "
        "GPA: " + std::to_string(gpa2) + ", "
        "grade: " + grade2 + ", "
        "name: " + name2 + "\n\n";



    std::vector<std::pair<int, std::string>> v;
    v.push_back(std::make_pair(1, "un"));
    v.push_back(std::make_pair(2, "deux"));
    v.push_back(std::make_pair(3, "trois"));

    toReturn += "std::vector<std::pair<int, std::string>> v;\n"
        "for (auto [x, y] : v) // x get the .first value and y the .second : \n\n";
    for (auto [x, y] : v)
        toReturn += std::to_string(x) + " : " + y + "\n";

	return toReturn;
}