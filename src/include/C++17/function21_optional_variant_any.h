#pragma once
#include "../import.h"


#include <variant>
#include <optional>
#include <any>

// optional can be used as the return type of a factory that may fail
std::optional<std::string> optional_createA(bool b) {
    if (b)
        return "Godzilla";
    return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto optional_createB(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

std::string variant()
{
    std::string toReturn = "";
    toReturn += "std::variant<int, float> v, w; // v and w can both be a int or a float\n\n";
    toReturn += "Can use std::get<float> or std::get<int>\n"
        "try {\n"
        "    std::get<float>(w); // if w is not float => throw error\n"
        "}\n"
        "catch (const std::bad_variant_access&){}\n\n";

    std::variant<int, float> v, w;
    v = 12; // v contains int
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line

    //  std::get<double>(v); // error: no double in [int, float]
    //  std::get<3>(v);      // error: valid index values are 0 and 1

    try {
        std::get<float>(w);
    }
    catch (const std::bad_variant_access&) {
        toReturn += "w contains int, not float => throws\n";
    }

    w = 1.f;

    try {
        std::get<float>(w);
        toReturn += "w contains float, dont throw => w : " + std::to_string(std::get<float>(w)) + "(" +
            typeid(std::get<float>(w)).name() + ")\n\n";
    }
    catch (const std::bad_variant_access&) {
        toReturn += "w contains int, not float => throws\n\n";
    }
    return toReturn;
}

std::string any() {

    // any type
    std::string toReturn = "std::any a = 1\n";
    std::any a = 1;

    toReturn += a.type().name();
    toReturn += " : " + std::to_string(std::any_cast<int>(a)) + '\n';

    a = 3.14;
    toReturn += "\na = 3.14\n";

    toReturn += a.type().name();
    toReturn += " : " + std::to_string(std::any_cast<double>(a)) + '\n';

    a = true;
    toReturn += "\na = true\n";

    toReturn += a.type().name();
    toReturn += " : " + std::to_string(std::any_cast<bool>(a)) + "\n\n";

    // bad cast
    try
    {
        a = 1;
        toReturn += "a = 1 \n";

        toReturn += "std::any_cast<float>(a) : ";
        std::any_cast<float>(a);
    }
    catch (const std::bad_any_cast& e)
    {
        toReturn += e.what();
        toReturn += "\n\n";
    }

    // has value
    a = 1;
    toReturn += "a = 1 // has value\n";
    toReturn += "if (a.has_value()) // true, int \n";

    if (a.has_value()) {
        toReturn += a.type().name();
        toReturn += "\n\n";
    }

    // reset
    a.reset();
    toReturn += "a.reset() // reset the value\n";
    toReturn += "if (!a.has_value()) // true, no value \n";
    if (!a.has_value())
        toReturn += "no value\n\n";

    return toReturn;
}

std::string function_21_optional_variant_any(){
  // 21. optional variant any
	std::string toReturn = "";
    toReturn += "######### 21 Optional Variant Any ############\n\n";
	
    // Variant
    toReturn += "################\n"
        "An instance of std::variant at any given time either holds"
        " a value of one of its alternative types, or in the case of error - no value\n";
    toReturn += "Variant : \n\n";
    toReturn += variant();
	
    // variant
    toReturn += "################\n"
        "The class template std::optional manages an optional contained value, "
        "i.e. a value that may or may not be present\n";
    toReturn += "Optional : \n\n";
    toReturn += "optional_createA(false) returned " + optional_createA(false).value_or("empty") + "\n\n";

    toReturn += "Optional-returning factory functions are usable as conditions of while and if : \n\n";
    toReturn += "if (auto str = optional_createB(true))\n";

    if (auto str = optional_createB(true))
        toReturn += "optional_createB(true) returned " + *str + "\n\n";

    // Any
    toReturn += "################\n"
        "The class any describes a type-safe container for single values of any type.\n";
    toReturn += "Any : \n\n";
    toReturn += any();

	return toReturn;
}