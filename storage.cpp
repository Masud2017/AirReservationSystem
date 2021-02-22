#include "storage.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

//using std::filesystem::exists;

namespace Storage {
	void Storage::__init__ () {
		std::ofstream fout;
		std::ifstream fileInput("db.txt");

		if (!fileInput) {
            std::cout <<"Creating database file..."<<std::endl;
            fout.open("db.txt");
        }
	}
}



