#pragma once
#include "import.h"
#include <chrono>

using namespace std::chrono;

std::string function_15_digit_separator(){
  // 15. digit separator
	std::string toReturn = "";
    toReturn += "######### 15 Digit Separator ############\n\n";
	
    int binary1 = 0b0110'0000;  // = 96
    toReturn += "0b0110'0000 = " + std::to_string(binary1) + '\n';

    int binary2 = 0b1111'1111'1111; // = 4095
    toReturn += "0b1111'1111'1111 = " + std::to_string(binary2) + "\n\n";

    int int1 = 1111'1111; // = 11111111
    toReturn += "1111'1111 = " + std::to_string(int1) + "\n";

    int hexa1 = 0xFF'FF;    // 65535
    toReturn += "0xFF'FF = " + std::to_string(hexa1) + "\n\n";


    auto sec1 = 6'00s;  // = 600 s == 10 min

    
    toReturn += "6'00s = " + std::to_string(duration_cast<seconds>(sec1).count()) + " seconds \n";
    toReturn += "6'00s = " + std::to_string(duration_cast<minutes>(sec1).count()) + " minutes \n\n";

    auto min1 = 6'00min; // == 600 min == 36 000 seconds == 10 hours

    toReturn += "6'00min = " + std::to_string(duration_cast<seconds>(min1).count()) + " seconds \n";
    toReturn += "6'00min = " + std::to_string(duration_cast<minutes>(min1).count()) + " minutes \n";
    toReturn += "6'00min = " + std::to_string(duration_cast<hours>(min1).count()) + " hours \n";

	return toReturn;
}