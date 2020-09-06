#pragma once
#include "import.h"


struct LengthInKM {
    constexpr explicit LengthInKM(double d) : val(d) { }
    constexpr double getValue() { return val; }
private:
    double val;
};

struct LengthInMile {
    constexpr explicit LengthInMile(double d) : val(d) { }
    constexpr double getValue() { return val; }
    constexpr operator LengthInKM () { return LengthInKM(1.609344 * val); }
private:
    double val;
};


std::string function_7_constexpr(){
  // 7. constexpr
	std::string toReturn = "";
    toReturn += "######### 7 Constexpr ############\n\n";
	
    toReturn += "Given that, we can make a table of constants without fear of unit errors or conversion errors :\n";

    const int N = 2;

    LengthInMile marksInMile[N] = { LengthInMile(2.3) , LengthInMile(0.76), };
    LengthInKM marksinKm[N] = { LengthInMile(2.3) , LengthInMile(0.76), };

    for (int i = 0; i < N; i++)
        toReturn += std::to_string(marksInMile[i].getValue()) + " in Mile is " + std::to_string(marksinKm[i].getValue()) + " in Km.\n";
	
    toReturn += "\nConversion make at compile time\n";

	return toReturn;
}