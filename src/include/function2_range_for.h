#pragma once

#include <vector>


std::string function_2_range_for(){
  // 2. range-for
	std::string toReturn = "";
    toReturn += "######### 2 Range for ############\n\n";
	
    std::vector<int> vec {1,2,3,4};
    for(auto i : vec)
	    toReturn += i + "\n";
		
	return toReturn;
}