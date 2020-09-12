#pragma once
#include "../import.h"
#include <execution>
#include <algorithm>
#include <vector>
#include <chrono>
#include <time.h>

void randomize(std::vector<int>& vec) 
{
	for (int i = 0; i < 1'000'000; i++)
		vec[i] = rand();
}

std::string function_23_parallel_stl(){
  // 23. parallel stl
	std::string toReturn = "";
	srand(time(NULL));
    toReturn += "######### 23 Parallel STL ############\n\n";
	
	toReturn += "The basic idea is to provide an extra argument to each standard-library algorithm, "
		"allowing the user to request vectorization and/or multithreading\n\n";

	
	int N = 1'000'000;

	toReturn += "N = " + std::to_string(N) + " (sorting N values)\n";

	std::vector<int> vec(N);
	std::cout << vec.size() << std::endl;
	// Standart
	randomize(vec);
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(vec.begin(), vec.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_seconds = end - start;

	toReturn += "elapsed time : " + std::to_string(elapsed_seconds.count()) + "s | Before\n";

	// Sequential
	randomize(vec);
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::seq, vec.begin(), vec.end());       
	end = std::chrono::high_resolution_clock::now();
	elapsed_seconds = end - start;

	toReturn += "elapsed time : " + std::to_string(elapsed_seconds.count()) + "s | Sequential (std::execution::seq)\n";

	// Parallel
	randomize(vec);
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::par, vec.begin(), vec.end());
	end = std::chrono::high_resolution_clock::now();
	elapsed_seconds = end - start;

	toReturn += "elapsed time : " + std::to_string(elapsed_seconds.count()) + "s | Parallel (std::execution::par)\n";

	// Parallel & Vectorized
	randomize(vec);
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::par_unseq, vec.begin(), vec.end());
	end = std::chrono::high_resolution_clock::now();
	elapsed_seconds = end - start;

	toReturn += "elapsed time : " + std::to_string(elapsed_seconds.count()) + "s | Parallel & Vectorized (std::execution::par_unseq)\n\n";

	return toReturn;
}