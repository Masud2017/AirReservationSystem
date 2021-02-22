#include "auth.hpp"

#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include "func.hpp"

namespace Auth {

    int Auth::login(std::string username,std::string password) {
        std::vector<std::string> dbChunk;
        // at first we have to check if the input is valid
        // sedcond we have to search for the username in db if exists
        // if it's exist then create the session else return false
        std::ofstream sessionWriter; // this is the file stream that is responsibe for write session to the file
        std::string line;
        std::ifstream sessionReader;

        std::ifstream dbReader;
        dbReader.open("db.txt");


        sessionReader.open("session.txt");

        getline(sessionReader,line);
        if (line == "loggedin") {
            std::cout<<"You are already logged in"<<std::endl;
            return 0;
        }

        while(dbReader) {
            getline(dbReader,line);

            dbChunk = split(line);

            if (dbChunk[3] == username) {

                if (dbChunk[4] == password) {
                    // Create session
                    sessionWriter.open("session.txt");

                    sessionWriter<<"loggedin"<<std::endl;
                    sessionWriter<<dbChunk[0]<<","<<dbChunk[1]<<","<<dbChunk[2]<<","<<dbChunk[3]<<","<<dbChunk[4]<<","<<dbChunk[5]<<std::endl;
                    std::cout<<"User logged in successfully"<<std::endl;
                   break;
                }
            }

        }

    }


    int Auth::logout() {
        std::ifstream sessionReader;
        sessionReader.open("session.txt");
        std::string line;

        getline(sessionReader,line);

        if (line == "loggedin") {
            system("rm session.txt");
        }
    }
}


