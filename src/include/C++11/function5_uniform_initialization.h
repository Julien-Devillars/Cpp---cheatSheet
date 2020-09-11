#pragma once
#include "../import.h"
#include <vector>


std::string function_5_uniform_initialization(){
    // 5. Uniform Initialization
	std::string toReturn = "";
    toReturn += "######### 5 Uniform Initialization ############\n\n";

    // Braces ({}) are optional for single values
    int a1 = { 5 }; // built - in type
    int a2 = 5;
    int a3(5); 
    int a4{ 5 }; 
    
    // Equal (=) is optional before a brace initializer list
    int b1[]{ 7 ,8 }; // array
    int b2[] = { 7 ,8 }; // array

    std::vector<int> v = { 7 ,8 }; // user - defined type with constructor
    toReturn += "Braces ({}) are optional for single values :\n - int i = 5 \n - int i = {5} \n - int i(5) \n - int i {5}\n\n";
    toReturn += "Equal (=) is optional before a brace initializer list : \n - int v[] = {1,2,3} \n - int v[]{1,2,3} \n";
    
		
	return toReturn;
}