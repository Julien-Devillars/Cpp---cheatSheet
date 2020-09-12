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

#include "include/C++11/function1_auto_decltype.h"
#include "include/C++11/function2_range_for.h"
#include "include/C++11/function3_move_semantic.h"
#include "include/C++11/function4_smart_pointer.h"
#include "include/C++11/function5_uniform_initialization.h"
#include "include/C++11/function6_nullptr.h"
#include "include/C++11/function7_constexpr.h"
#include "include/C++11/function8_user_defined_literals.h"
#include "include/C++11/function9_raw_litterals.h"
#include "include/C++11/function10_attributes.h"
#include "include/C++11/function11_lambdas.h"
#include "include/C++11/function12_variadic_templates.h"
#include "include/C++11/function13_aliases.h"
#include "include/C++11/function14_tuples.h"

#include "include/C++14/function15_digit_separator.h"
#include "include/C++14/function16_variables_templates.h"
#include "include/C++14/function17_function_return_type_deduction.h"
#include "include/C++14/function18_generic_lambdas.h"

#include "include/C++17/function19_constructor_template_argument_deduction.h"
#include "include/C++17/function20_structured_bindings.h"
#include "include/C++17/function21_optional_variant_any.h"
#include "include/C++17/function22_concurrency.h"


#define print(a) std::cout << a << std::endl << std::endl;
#define p(a) std::cout << a << std::endl;
#define NN std::cout << "\n";

#define pb push_back
int main(){
	
	// C++ 11

    using function = std::string(*) ();    // alias
    std::vector<function> functions;

	functions.pb(function_1_auto_decltype);                        // auto and decltype
	functions.pb(function_2_range_for);                            // Range-for
	functions.pb(function_3_move_semantic);                        // Move semantics
    functions.pb(function_4_smart_pointer);                        // smart pointers
    functions.pb(function_5_uniform_initialization);               // uniform Initialization
    functions.pb(function_6_nullptr);                              // nullptr
    functions.pb(function_7_constexpr);                            // constexpr
    functions.pb(function_8_user_defined_literals);                // User-defined litterals
    functions.pb(function_9_raw_literals);                         // Raw litterals
    functions.pb(function_10_attributes);                          // Attributes
    functions.pb(function_11_lambdas);                             // Lambdas
    functions.pb(function_12_variadic_templates);                  // Variadic Templates
    functions.pb(function_13_aliases);                             // Variadic Templates
    functions.pb(function_14_tuples);                              // tuples
	
	// C++ 14
	
    functions.pb(function_15_digit_separator);                     // Digit Separators
    functions.pb(function_16_variables_templates);                 // Variable Templates
    functions.pb(function_17_function_return_type_deduction);      // Function Return Type Deduction
    functions.pb(function_18_generic_lambdas);                     // Generic Lambdas

    // C++ 17
    
    functions.pb(function_19_constructor_template_argument_deduction);// Constructor Template Argument Deduction
    functions.pb(function_20_structure_bindings);                   // Constructor Template Argument Deduction
    functions.pb(function_21_optional_variant_any);                 // variant, optional, and any
    functions.pb(function_22_concurrency);                          // concurrency


    //function23();   // Parallel STL
    //function24();   // File System
    //function25();   // Explicit Tests in Condition
    


    std::cout << functions[functions.size() - 1]() << std::endl;

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

/*
C++ 14

    The C++14 feature set can be summarized as:

        • Binary literals - e.g., 0b1001000011110011
        • Digit separators - for readability, e.g., 0b1001’0000’1111’0011
        • Variable templates - parameterized constants and variables
        • Function return type deduction
        • Generic lambdas
        • Local variables in constexpr functions
        • Move capture - e.g., [p = move(ptr)] {  ...  }; move a value into a lambda
        • Accessing a tuple by type, e.g., x = get<int>(t);
        • User-defined literals in the standard library - e.g., 10i, "Hello!"s, 10s, 3ms, 55us, 17ns
*/

/*
C++17
    C++17 had about 21 new language features, including:

        • Constructor template argument deduction - simplify object definitions
        • Deduction guides - an explicit notation for resolving constructor template argument deduction ambiguities
        • Structured bindings - simplify notation and eliminate a source of uninitialized variables
        • inline variables - simplify the use of statically allocated variables in header-only libraries
        • Fold expressions - simplify some uses of variadic templates
        • Explicit test in conditions - a bit like conditions in for-statements
        • Guaranteed copy elision - eliminate many redundant copy operations
        • Stricter expression evaluation order - prevents some subtle order-of-evaluation mistakes
        • auto as a template argument type - type deduction for value template arguments
        • Standard attributes to catch common mistakes - [[maybe_unused]], [[nodiscard]], and [[fallthrough]]
        • Hexadecimal floating-point literals
        • Constant expression if - simplify compile-time evaluated code

    Unfortunately, this is not quite the full list of extensions. Quite a few are so small that they are
    not easy to briefly describe.

    The C++17 standard-library added about 13 new features plus many minor modifications:

        • optional, variant, and any - standard-library types for expressing alternatives
        • shared_mutex and shared_lock (reader-writer locks) and scoped_lock
        • parallel STL - multi-threaded and/or vectorized versions of standard-library algorithms
        • file system - the ability to portably manipulate file-system paths and directories
        • string_view - a non-owning reference to an immutable sequence of characters
        • Mathematical special functions - including Lag

    Proposals That Didn’t Make C++17

        • concepts (C++20)
        • networking
        • operator dot
        • uniform call syntax
        • default comparison
        • coroutines (C++20)

*/
