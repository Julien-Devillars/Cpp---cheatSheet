/*

Here is a summary of every new features added to c++ from 2006 to 2020
It was inspired by the paper from Bjarne Stroustrup , https://dl.acm.org/doi/pdf/10.1145/3386320

I didnt added the WIP features explanations and the future of C++.
But there is every feature presented in the paper.


I tried to add some examples and explanations when I can.
Some features arestill not implemented on the compler (c++20 features for example)

There is a summary of every new features added in each version of c++ under the main body.

*/

#pragma once
#include <iostream>
#include "include/function1_auto_decltype.h"
#include "include/function2_range_for.h"
#include "include/function3_move_semantic.h"
#include "include/function4_smart_pointer.h"
#include "include/function5_uniform_initialization.h"
#include "include/function6_nullptr.h"
#include "include/function7_constexpr.h"


#define print(a) std::cout << a << std::endl << std::endl;
#define p(a) std::cout << a << std::endl;
#define NN std::cout << "\n";

int main(){
	
	// c++ 11

	//p(function_1_auto_decltype());  // auto and decltype
	//p(function_2_range_for());  // Range-for
	//p(function_3_move_semantic());  // Range-for
    //p(function_4_smart_pointer());
    //p(function_5_uniform_initialization());
    //p(function_6_nullptr());
    p(function_7_constexpr());
    //function3();  // Move semantics
    //function4();  // smart pointers
    //function5();  // uniform Initialization
    //function6();  // nullptr
    //function7();  // constexpr
    //function8();  // User-defined litterals
    //function9();  // Raw litterals
    //function10(); // Attributes
    //function11(); // lambdas
    //function12(); // variadic template
    //function13(); // aliases
    //function14(); // tuples
	
	
	
	return 0;
}

/*
C++ 11

    C++11 introduced a bewildering number of language features, including:

        • memory model - an efficient low level-model of modern hardware as a foundation for
        concurrency
        • auto and decltype - avoiding redundant repetition of type names
        • range-for - simple linear traversal of ranges
        • move semantics and rvalue references - minimizing copying of data
        • uniform initialization - an (almost) completely general syntax and semantics for initializing
        objects of all kinds and types
        • nullptr - a name for the null pointer
        • constexpr functions - compile-time evaluated functions
        • user-defined literals - literals for user-defined types
        • raw string literals - literals where escape characters are not needed, mostly for regular
        expressions
        • attributes - associating essentially arbitrary information with a name
        • lambdas - unnamed function objects
        • variadic templates - templates that can handle an arbitrary number of arguments of
        arbitrary types
        • template aliases - the ability to rename a template and to bind some template arguments for
        the new name
        • noexcept - a way of ensuring that an exception isn’t thrown from a function
        • override and final - explicit syntax for managing large class hierarchies
        • static_assert - compile-time assertions
        • long long - a longer integer type
        • default member initializers - give a data member a default value that can be superseded by
        initialization in a constructor
        • enum classes - strongly typed enumerations with scoped enumerators
        And here is a list of the major standard-library components
        • unique_ptr and shared_ptr - resource-management pointers relying on RAII
        • memory model and atomic variables
        • thread, mutex, condition_variable, etc. - type-safe and portable support for basic systemlevel concurrency
        • future, promise, and packaged_task, etc. - slightly higher-level concurrency
        • tuple - unnamed simple composite types
        • type traits - testable properties of types for use in metaprogramming
        • regular expression matching
        • random numbers - with many generators (engines) and distributions
        • Time - time_point and duration
        • unordered_map, etc. - hash tables
        • forward_list - a singly-linked list
        • array - a fixed-constant-sized array that knows its size
        • emplace operations - construct objects right within a container to avoid copying
        • exception_ptr - enables transfer of exceptions between threads

    ====================================================

    The C++11 improvements relating directly to type safety are:

        • Type-safe interface to threading and locking - avoid POSIX and Windows reliance on void**
        and macros in concurrent code
        • Range-for - avoid erroneous specification of ranges
        • Move semantics - addresses the problem of overuse of pointers
        • Resource management pointers (unique_ptr and shared_ptr )
        • uniform initialization - make initialization more general, more uniform, and safer
        • constexpr - eliminate many uses of (untyped and unscoped) macros
        • User-defined literals - make user-defined types more like built-in types
        • enum classes - eliminate some weakly-typed practices involving integer constants
        • std::array - avoid unsafe łdecayž of built-in arrays to pointers

    =====================================================

    C++11 added a few key library components supporting specific tasks:

        • threads - thread-and-lock-based concurrency
        • regex - regular expressions
        • chrono - time
        • random - random number generators and distributions

*/