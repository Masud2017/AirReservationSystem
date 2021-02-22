#include "menu.hpp"

#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "auth.hpp"
#include "otherDisp.hpp"
#include <fstream>

void Menu::welcomeMessage(void) {
    std::cout <<"*******************************************************************"<<std::endl;
    std::cout <<"*******************************************************************"<<std::endl;
    std::cout <<"*******************************************************************"<<std::endl;
    std::cout <<"*****************                                 *****************"<<std::endl;
    std::cout <<"**************** Welcome to Air reservation system ****************"<<std::endl;
    std::cout <<"*****************                                 *****************"<<std::endl;
    std::cout <<"*******************************************************************"<<std::endl;
    std::cout <<"*******************************************************************"<<std::endl;
    std::cout <<"*******************************************************************"<<std::endl;

    std::cout<<std::endl<<"Press enter button for start the app.."<<std::endl;
    getchar();
    std::cout<<std::endl;
    system("clear");
}

void Menu::actualWindow() {
    std::ifstream sessionReader;
    sessionReader.open("session.txt");
    std::string line;
    getline(sessionReader,line);

    if (line == "loggedin") {loggedinDisplay();}
    else {
        std::cout<<"************ Main menu ***************"<<std::endl;
        std::cout<<"Choose one option: "<<std::endl;
        std::cout<<"[1] Register a user."<<std::endl;
        std::cout<<"[2] Login."<<std::endl;
        std::cout<<"[3] About us."<<std::endl;
        std::cout<<"[4] Exit."<<std::endl;
        std::cin >> option;

        if (option == 1) {
            system("clear");
            registerDisplay();

        } else if (option == 2) {
            Auth::Auth auth;
            std::ifstream sessionReader;
            std::string username;
            std::string password;

            auth.login(username,password);
            sessionReader.open("session.txt");
            system("clear");

            loginDisplay();

            loggedinDisplay();



        } else if (option == 3) {
            system("clear");
            std::cout<<"This software is created by "<<std::endl<<"[-] Md.Masud karim"<<std::endl<<"[-] Hasibul hasan shanto"<<std::endl<<"[-] Monjurul Islam"<<std::endl;
            char halt;
            std::cin >> halt;
            system("clear");
        } else if (option == 4) {
            exit(0);
        }
    }
}
