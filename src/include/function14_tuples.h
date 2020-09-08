#pragma once
#include "import.h"


std::tuple<double, char, std::string> get_student(int id)
{
    switch (id) {
        case 0: 
            return { 3.8, 'A', "Lisa Simpson" };         // Error until N4387
        case 1: 
            return std::tuple<double, char, std::string>{2.9, 'C', "Milhouse Van Houten"}; // Always works
        case 2: 
            return std::make_tuple(1.7, 'D', "Ralph Wiggum");  // Always works
        default: 
            std::invalid_argument("id");
    }
}

std::string function_14_tuples(){
  // 14. tuples
	std::string toReturn = "";
    toReturn += "######### 14 Tuples ############\n\n";
	
    
    toReturn += "Tuples are fixed-size heterogeneous containers. They are a general-purpose utility, adding"
        "   to the expressiveness of the language. Some examples of common uses for tuple types are :          \n\n"
        " - Return types for functions that need to have more than one return type.                              \n"
        " - Grouping related types or objects (such as entries in parameter lists) into single entities.         \n"
        " - Simultaneous assignment of multiple values.                                                          \n\n";

    toReturn += "3 ways to create a tuple : \n\n" 
         " - Uniform initialization\n"
         "    { 1.324, 'c', \"string\" }\n"
         " - Constructor\n"
         "    std::tuple<double, char, std::string>{1.324, 'c', \"string\"}\n"
         " - Make_tuple function\n"
         "    std::make_tuple(1.324, 'c', \"string\") (make_tuple function)\n\n";

    toReturn += "3 ways to get values from a tuple : \n\n"
        " - Get function (with i (integer) the selected attribute)\n"
        "    std::get<i>(myTuple)\n"
        " - Tie function (wich modify values by reference) \n"
        "    std::tie(var1, var2, var3) \n"
        " - Structured Binding (C++17)\n"
        "    auto [var1, var2, var3] = myTuple \n\n";

    // basic used
    auto student0 = get_student(0);
    toReturn += "ID: 0, GPA: " + std::to_string(std::get<0>(student0))  + ", "
        + "grade: " + std::to_string(std::get<1>(student0))  + ", "
        + "name: "  + std::get<2>(student0)  + "\n\n";

    // using tie function from tuple
    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(1);

    toReturn += "ID: 0, GPA: " + std::to_string(gpa1) + ", "
        + "grade: " + std::to_string(grade1) + ", "
        + "name: " + name1 + "\n\n";


    // using C++17 structured binding:

    auto [gpa2, grade2, name2] = get_student(2);

    toReturn += "ID: 0, GPA: " + std::to_string(gpa2) + ", "
        + "grade: " + std::to_string(grade2) + ", "
        + "name: " + name2 + "\n\n";

	return toReturn;
}