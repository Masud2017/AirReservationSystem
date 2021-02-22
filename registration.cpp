#include "registration.hpp"
#include <iostream>
#include <fstream>

#include "func.hpp"

namespace Registration {
    void Registration::__init__() {
		std::ifstream fileInput("db.txt");

		if (!fileInput) {
            std::cout <<"Creating database file..."<<std::endl;
            fout.open("db.txt");
        }
    }
    void Registration::addUser(Customer customerInfo) {

        // We want to check if the user exists after that maybe I will procced further
        std::ofstream fout("db.txt",std::ios::app);
        std::ifstream dbReader;
        dbReader.open("db.txt");
        std::string line;
        std::vector<std::string> vect;

        while(dbReader) {
            getline(dbReader,line);
            vect = split(line);
            if (vect[3] == customerInfo.getEmail()) {
                std::cout <<"User already exists you can't use this email address"<<std::endl;

                exit(0);
            }
        }

        //std::cout <<customerInfo.toString()<<std::endl;

        fout<<customerInfo.toString()<<std::endl;
        fout.close();
        std::ifstream reader("db.txt");
        std::string st;

        getline(reader, st);
        std::cout <<st<<std::endl ;

        addBalance(customerInfo);

        reader.close();


    }
}
