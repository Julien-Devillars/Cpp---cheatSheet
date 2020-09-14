#pragma once
#include "../import.h"
#include <filesystem>

std::string function_24_file_system(){
  // 24. File System
	std::string toReturn = "";
    toReturn += "######### 24 File System ############\n\n";
	
	toReturn += "We don't need the boost file system library anymore :)\n\n";

	const std::string myPath = "path/to/file";

	std::filesystem::path p{ myPath };		// name could be in Russian or Arabic
											// name could use Linux or Windows file notation

    toReturn += "File System library support every languages (arabian, russian, etc) and support Linux & Windows notation\n\n";

    try {
        if (exists(p)) {
            if (is_regular_file(p))
                int i = 0;
            //cout << p << " regular file , size : " << file_size(p) << '\n ';
            else if (is_directory(p))
                //cout << p << " directory \n ";
                int i = 1;
        }
    }
    catch (const std::filesystem::filesystem_error& ex) {
        //cerr << ex.what() << "\n ";
        throw;
    }

    toReturn += "There is a lot of functions useful, just check the documentation for more info.\n"
        "You can throw an excetion with filesystem_error\n\n";
	return toReturn;
}