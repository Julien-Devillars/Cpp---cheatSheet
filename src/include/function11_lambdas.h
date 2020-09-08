#pragma once
#include "import.h"
#include <algorithm>

std::string function_11_lambdas(){
  // 11. lambdas
	std::string toReturn = "";
    toReturn += "######### 11 Lambdas ############\n\n";
	
    toReturn += "Lambda syntax :                                                                                        \n"
        "[capture](params) { body }                                                                                   \n\n"
        "- capture :                                                                                                    \n"
        "Specify that the variables are visibles in the scope where the function                                        \n"
        "is declared, they are usables on the body.                                                                   \n\n"
        "                                                                                                               \n"
        "[a, &b] where a is captured by value and b is captured by eference                                             \n"
        "[this] is the pointer this                                                                                     \n"
        "[&] captures all symbols by reference                                                                          \n"
        "[=] captures all by value                                                                                      \n"
        "[] captures nothing                                                                                           \n\n"
        "                                                                                                               \n"
        "- params : parameters list like a normal function                                                            \n\n"
        "- body : core of the function                                                                                \n\n"
        "                                                                                                               \n"
        "[&v] capture is potentially efficient because v is not copied. If the callback is invoked                      \n"
        "on a different thread, [&v] capture could be a disaster because v could go out of scope before it              \n"
        "was used; in that case, we want a copy                                                                       \n\n"
        "                                                                                                               \n"
        "Lambdas was mainly for the use as arguments to STL algorithms                                                  \n"
        "(check STL functions on https://github.com/srcmake/cpp-stl-algorithms)                                     \n\n\n";
		
        auto l1 = [](float a, float b) { return std::abs(a) < std::abs(b); };
        auto l2 = [](float a, float b) { return a < b; };

        float x[5]{ 3,2,-2,-3.5,0 };
        unsigned int N = 5;

        toReturn += "Before sorting\n";
        for (int i = 0; i < N; i++)
            toReturn += std::to_string(x[i]) + " : " ;

        std::sort(x, x + N, l1);

        toReturn += "\n\nAfter sorting by absolute value :\n";
        toReturn += "lambda : [](float a, float b) { return std::abs(a) < std::abs(b); }\n";
        for (int i = 0; i < N; i++)
            toReturn += std::to_string(x[i]) + " : ";

        std::sort(x, x + N, l2);

        toReturn += "\n\nAfter sorting by ascending\n";
        toReturn += "lambda : [](float a, float b) { return a < b; }\n";
        for (int i = 0; i < N; i++)
            toReturn += std::to_string(x[i]) + " : ";

        toReturn += "\n";

	return toReturn;
}