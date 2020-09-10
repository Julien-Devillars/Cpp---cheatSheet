#pragma once
#include "../import.h"
#include <typeinfo>

template < typename T >
constexpr T pi = T(3.1415926535897932385);

template < typename T >
T circular_area(T r)
{
	return pi<T> * r * r;
}

std::string function_16_variables_templates(){
  // 16. variables templates
	std::string toReturn = "";
    toReturn += "######### 16 Variables Templates ############\n\n";
	
	toReturn +=
		"template < typename T >\n"
		"constexpr T pi = T(3.1415926535897932385);\n\n"
		"template < typename T >\n"
		"T circular_area(T r)\n"
		"{\n"
		"   return pi<T> * r * r;\n"
		"}\n\n"
		"r = 2 (float, int, double)\n\n";

	float r_float = 2.0f;
	int r_int = 2;
	double r_double = 2.0;

	auto area1 = circular_area<decltype(r_float)>(r_float);
	auto area2 = circular_area<decltype(r_int)>(r_int);
	auto area3 = circular_area<decltype(r_double)>(r_double);

	toReturn += 
		"Area 1 : "  + std::to_string(area1)  + " and his type is : "  + typeid(area1).name()  + "\n"
		"Area 2 : "  + std::to_string(area2)  + " and his type is : "  + typeid(area2).name()  + "\n"
		"Area 3 : "  + std::to_string(area3)  + " and his type is : "  + typeid(area3).name()  + "\n\n";
	
	return toReturn;
}