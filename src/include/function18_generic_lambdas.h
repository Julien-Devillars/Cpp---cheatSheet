#pragma once
#include "import.h"
#include "function17_function_return_type_deduction.h"
#include <algorithm>
#include <vector>
#include <iostream>

#define _for(a, lambda) std::for_each(a.begin(), a.end(), lambda);


std::string function_18_generic_lambdas(){
  // 18. generic lambdas
    std::string toReturn = "";
    std::cout << "######### 18 Generic Lambdas ############\n\n";
	
    std::cout << "auto can be used in the parameter from a lambda : [](auto x){}\n\n";
    auto print = [](auto x) { std::cout << x.first << "\n"; };
    auto sorted = [](auto a, auto b) {return a.first < b.first; };

    std::cout << "auto print = [](auto x) { std::cout << x.first << \"\\n\"; };\n";
    std::cout << "auto sorted = [](auto a, auto b) { return a.first < b.first; };";

    std::vector<A17> array_A(3);    // using B

    array_A[0].first = 1;
    array_A[1].first = 18;
    array_A[2].first = -5;
    
    std::vector<B17> array_B(5);

    array_B[0].first = "AA";
    array_B[1].first = "BBBB";
    array_B[2].first = "AAAA";
    array_B[3].first = "bbbbb";

    std::cout << "\n\n";
    
    std::cout << "Before sorting : \n";
    _for(array_A, print);

    std::sort(array_A.begin(), array_A.end(), sorted);

    std::cout << "\nAfter sorting : \n";
    _for(array_A, print);

    std::cout << "\n===============\n";

    std::cout << "Before sorting : \n";
    _for(array_B, print);

    std::sort(array_B.begin(), array_B.end(), sorted);
    std::cout << "\nAfter sorting : \n";

    _for(array_B, print);

	return toReturn;
}