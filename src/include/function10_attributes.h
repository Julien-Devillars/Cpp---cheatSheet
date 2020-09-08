#pragma once
#include "import.h"

/*
[[noreturn]] indicates that the function does not return
[[carries_dependency]] indicates that dependency chain in release - consume std::memory_order propagates in and out of the function
[[deprecated]] (C++14)
[[deprecated("reason")]] (C++14)	indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason
[[fallthrough]] (C++17)	indicates that the fall through from the previous case label is intentionaland should not be diagnosed by a compiler that warns on fall - through
[[nodiscard]] (C++17)
[[nodiscard("reason")]] (C++20)	encourages the compiler to issue a warning if the return value is discarded
[[maybe_unused]] (C++17)	suppresses compiler warnings on unused entities, if any
[[likely]] (C++20)
[[unlikely]] (C++20)	indicates that the compiler should optimize for the case where a path of execution through a statement is more or less likely than any other path of execution
[[no_unique_address]] (C++20)	indicates that a non - static data member need not have an address distinct from all other non - static data members of its class
[[optimize_for_synchronized]] (TM TS)	indicates that the function definition should be optimized for invocation from a synchronized statement
*/

[[noreturn]] void foo10_1() 
{
    throw "error";
}

/*
[[noreturn]] specifies that a function never returns; in other words,
it always throws an exception. The compiler can adjust its rules of
compilation for entities [[noreturn]]. */

[[carries_dependecy]] void foo10_2() {}

/*
[[carries_dependency]] specifies that the function propagates the ordering of
data dependencies regarding thread synchronization.
The attribute can be applied to one or more parameters, to specify
that the passed argument bears a dependency in the body of the function.
The attribute can be applied to the function itself, to specify that the value
return carries a dependency from the function. The compiler can use
this information to generate more efficient code. */

[[deprecated]] void foo10_3() {}
[[deprecated]] int bar10 = 5;

/*
[[deprecated]] Visual Studio 2015 and later: specifies that a function
is not intended for use and does not exist in later versions
of a library interface. The compiler can use it to generate a message
information when the client code tries to call the function. Can be applied to
the declaration of a class, a typedef name, a variable, a data member
non-static, to a function, to a namespace, to an enumeration, to an enumerator or
to a model specialization. */

std::string g() { return " g "; };
std::string h() { return " h "; };
std::string i() { return " i "; };

std::string foo10_4(int n) {
    std::string toReturn = "";
    switch (n) {
    case 1:
    case 2:
        toReturn += g();
        [[fallthrough]];
    case 3: // no warning on fallthrough
        toReturn += h();
    case 4: // compiler may warn on fallthrough
        if (n < 3) {
            toReturn += i();
            [[fallthrough]]; // OK
        }
        else {
            return toReturn;
        }
    case 5:
        while (false) 
            [[fallthrough]]; // ill-formed: next statement is not part of the same iteration
        
    case 6:
        [[fallthrough]]; // ill-formed, no subsequent case or default label
    }
    return toReturn;
}

/*
[[fallthrough]] Visual Studio 2017 and later: (available with / std: c ++ 17)
the [[fallthrough]] attribute can be used in the context of switch statements by
as a flag for the compiler (or anyone reading the code) to which the behavior
FallThrough is intended. Currently, the Microsoft C ++ compiler does not issue a warning
on FallThrough behavior. this attribute therefore has no effect on the behavior of the compiler. */

[[nodiscard]] void foo10_5() {}

/*
[[nodiscard]] Visual Studio 2017 version 15.3 and later: (available with / std: c ++ 17)
specifies that the return value of a function is not intended to be ignored. */

[[maybe_unused]] void foo10_6() {}

/*
[[maybe_unused]] Visual Studio 2017 version 15.3 and later: (available with / std: c ++ 17)
specifies that a variable, a function, a class, a typedef, a non-static data member,
an enumeration or model specialization may not be used intentionally.
The compiler does not warn when a known entity [[maybe_unused]] is not in use.
An entity declared without the attribute can be redeclared later with the attribute and vice versa.
An entity is considered recognized after its first statement known to be analyzed
and for the rest of the translation from the current translation unit.*/



std::string function_10_attributes(){
  // 10. attributes
	std::string toReturn = "";
    toReturn += "######### 10 Attributes ############\n\n";
	
    toReturn += "[[noreturn]] void foo10_1() {"
        "throw \"error\""
        "}\n\n";

        "[[noreturn]] specifies that a function never returns; in other words, "
        "it always throws an exception. The compiler can adjust its rules for"
        "compilation for entities [[noreturn]]. \n \n";

    toReturn += "[[carries_dependecy]] void foo10_2() {}\n\n"

        "[[carries_dependency]] specifies that the function propagates the ordering of "
        "data dependencies with regard to thread synchronization."
        "The attribute can be applied to one or more parameters, to specify"
        "that the passed argument carries a dependency in the body of the function."
        "The attribute can be applied to the function itself, to specify that the value"
        "return carries a dependency from the function. The compiler can use"
        "this information to generate more efficient code. \n \n";

    toReturn += "[[deprecated]] void foo10_3() {}\n"
        "[[deprecated]] int bar10 = 5;\n\n"

        "[[deprecated]] Visual Studio 2015 and later: Specifies that a "
        "is not intended for use and does not exist in later versions"
        "a library interface. The compiler can use this to generate a message"
        "information when the client code tries to call the function. Can be applied to"
        "the declaration of a class, a typedef name, a variable, a data member"
        "non-static, to a function, to a namespace, to an enumeration, to an enumerator or"
        "to a model specialization.\n \n";



    toReturn += "void foo10_4(int n) {\n"
        "std::string toReturn = "";\n"
        "switch (n) {\n"
        "case 1:\n"
        "    [[fallthrough]];\n"
        "case 2:\n"
        "    return:\n"
        "}\n\n";

        "[[fallthrough]] Visual Studio 2017 and later: (available with / std: c ++ 17) "
         "the [[fallthrough]] attribute can be used in the context of switch statements by"
         "as a flag for the compiler (or anyone reading the code) to which the behavior"
         "FallThrough is intended. Currently, the Microsoft C ++ compiler does not issue a warning"
         "on FallThrough behavior. So this attribute has no effect on the behavior of the compiler. \n \n";

    toReturn += 
        "[[nodiscard]] void foo10_5() {}\n\n"

        "[[nodiscard]] Visual Studio 2017 version 15.3 and later: (available with / std: c ++ 17) "
        "specifies that the return value of a function is not intended to be ignored. \n \n";

    toReturn += "[[maybe_unused]] void foo10_6() {}\n\n"


        "[[maybe_unused]] Visual Studio 2017 version 15.3 and later: (available with / std: c ++ 17)"
        "specifies that a variable, a function, a class, a typedef, a non - static data member,"
        "an enumeration or model specialization may not be used intentionally."
        "The compiler does not warn when a known entity [[maybe_unused]] is not in use."
        "An entity declared without the attribute can be redeclared later with the attribute and vice versa."
        "An entity is considered recognized after its first statement known to be analyzed"
        "and for the rest of the translation from the current translation unit. \n \n";

    toReturn += "\nFrom cppreference (https://en.cppreference.com/w/cpp/language/attributes) :\n\n"
        " - [[noreturn]] indicates that the function does not return\n\n"
        " - [[carries_dependency]] indicates that dependency chain in release - consume std::memory_order propagates in and out of the function\n\n"
        " - [[deprecated]] (C++14)\n"
        " - [[deprecated(\"reason\")]] (C++14)	indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason\n\n"
        " - [[fallthrough]] (C++17)	indicates that the fall through from the previous case label is intentionaland should not be diagnosed by a compiler that warns on fall - through\n\n"
        " - [[nodiscard]] (C++17)\n"
        " - [[nodiscard(\"reason\")]] (C++20)	encourages the compiler to issue a warning if the return value is discarded\n\n"
        " - [[maybe_unused]] (C++17)	suppresses compiler warnings on unused entities, if any\n\n"
        " - [[likely]] (C++20)\n"
        " - [[unlikely]] (C++20)	indicates that the compiler should optimize for the case where a path of execution through a statement is more or less likely than any other path of execution\n\n"
        " - [[no_unique_address]] (C++20)	indicates that a non - static data member need not have an address distinct from all other non - static data members of its class\n\n"
        " - [[optimize_for_synchronized]] (TM TS)	indicates that the function definition should be optimized for invocation from a synchronized statement\n\n";

	return toReturn;
}