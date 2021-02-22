#include "auth.hpp"

#include <fstream>

namespace Auth {

    int Auth::login(std::string username,std::string password) {
        // at first we have to check if the input is valid
        // sedcond we have to search for the username in db if exists
        // if it's exist then create the session else return false
        ofstream sessionWriter; // this is the file stream that is responsibe for write session to the file

        ifstream dbReader;
        dbReader.open("db.txt");
        while(dbReader) {
            getline(dbReader,line);

            std::cout<<line<<std::endl;
        }
    }
}

