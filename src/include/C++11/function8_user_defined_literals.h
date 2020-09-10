#pragma once
#include "../import.h"

#include <complex>
#include <iostream>
class MyDistance {
public:
    MyDistance(double i) :m(i) {}

    friend MyDistance operator+(const MyDistance& a, const MyDistance& b) { return MyDistance(a.m + b.m); }
    friend std::ostream& operator<< (std::ostream& out, const MyDistance& myDist) { out << myDist.m << " m"; return out; }
private:
    double m;
};

MyDistance operator "" _m(long double d) { return MyDistance(1 * d); }
MyDistance operator "" _dm(long double d) { return MyDistance(10 * d); }
MyDistance operator "" _cm(long double d) { return MyDistance(100 * d); }
MyDistance operator "" _km(long double d) { return MyDistance(1000 * d); }

int operator "" _2(long double i) { return i * i; }

/*
Only the following parameter lists are allowed on literal operators :

( const char * )	(1)
( unsigned long long int )	(2)
( long double )	(3)
( char )	(4)
( wchar_t )	(5)
( char8_t )	(6)	(since C++20)
( char16_t )	(7)
( char32_t )	(8)
( const char * , std::size_t )	(9)
( const wchar_t * , std::size_t )	(10)
( const char8_t * , std::size_t )	(11)	(since C++20)
( const char16_t * , std::size_t )	(12)
( const char32_t * , std::size_t )	(13)	*/

std::string function_8_user_defined_literals(){
  // 8. user-defined literals
	std::string toReturn = "";
    std::cout << "######### 8 User-defined literals ############\n\n";
    using namespace std::complex_literals;

    std::cout << "Enable the user to creater is own literals" << std::endl;

    std::complex<double> mycomplex1(10.0, 2.0); // defined as the function above => 10 + 2i
    std::complex<double> mycomplex2 = 10.0 + 2i;

    std::cout << "std::complex<double> mycomplex1(10.0, 2.0) : " << mycomplex1 << std::endl;
    std::cout << "std::complex<double> mycomplex2 = 10.0 + 2.0i : " << mycomplex2 << " (with the namespace std::complex_literals)" << std::endl;

    std::cout << "\n";

    std::cout << "operator 0b : enable binary to int -> 0b1010 = " <<  0b1010 << "\n";
    std::cout << "operator 0x : enable hexadecimal to int -> 0x1010 = " <<  0x1010 << "\n";

    std::cout << "\n";

    std::cout << "1.0_m : " << 1.0_m << std::endl;      // 1m
    std::cout << "1.0_dm : " << 1.0_dm << std::endl;    // 10m
    std::cout << "1.0_cm : " << 1.0_cm << std::endl;    // 100m
    std::cout << "1.0_km : " << 1.0_km << std::endl;    // 1000m

    std::cout << "1.0_km + 523.7_m + 1.5_dm : " << 1.0_km + 523.7_m + 1.5_dm << std::endl;

    std::cout << "\n";

    std::cout << "int operator "" _2(long double i) { return i * i; }\n";
    
    std::cout << "5.0_2 => 5.0*5 : " << 5.0_2 << std::endl;
	
    toReturn += "\nOnly the following parameter lists are allowed on literal operators :\n"
         " - (const char*)\n"
         " - (unsigned long long int)\n"
         " - (long double)\n"
         " - (char)\n"
         " - (wchar_t)\n"
         " - (char8_t)   (since C++20)\n"
         " - (char16_t)\n"
         " - (char32_t)\n"
         " - (const char*, std::size_t)	\n"
         " - (const wchar_t*, std::size_t)	\n"
         " - (const char8_t*, std::size_t)   (since C++20)\n"
         " - (const char16_t*, std::size_t)"
         " - (const char32_t*, std::size_t) \n";

	return toReturn;
}