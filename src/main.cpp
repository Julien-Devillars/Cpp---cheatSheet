#include <iostream>

#define print(a) std::cout << std::endl << a << std::endl << std::endl;
#define p(a) std::cout << a << std::endl;
#define NN std::cout << "\n";
#define _for(a, lambda) std::for_each(a.begin(), a.end(), lambda);

void function1() {
	// 1 auto & decltype
	print("######### 1 Auto & Decltype ############");
	// auto
	auto i = 7;   // int
	auto f = 7.2; // float

	// decltype
	int val = 3;
	decltype(val) value = (decltype(val)) 10.5;

	std::cout << value << std::endl;
}

int main(){
	
	// c++ 11

	function1();  // auto and decltype
	
	return 0;
}