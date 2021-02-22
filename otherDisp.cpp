#include "otherDisp.hpp"
#include "registration.hpp"
#include "customer.hpp"
#include "auth.hpp"
#include "func.hpp"
#include "ticketinfostorage.hpp"
#include "Booking.hpp"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

void loggedinDisplay() {
    std::ifstream sessionReader;
    std::string line;
    Auth::Auth auth;
    ticketStorage::TicketStorage ticketStorage;
    booking::Booking booking;

    sessionReader.open("session.txt");

    getline(sessionReader,line);

    if (line == "loggedin") {
        int option;
        getline(sessionReader,line);
        std::vector<std::string> loggedUser;
        loggedUser = split(line);

        std::cout <<"***** "<<loggedUser[1]<<"            "<<loggedUser[3]<<" ***********"<<std::endl;
        std::cout <<"***** "<<"            "<<"Dashboard"<<"             "<< "***********"<<std::endl;

        std::cout << "[1] My tickets."<<std::endl;
        std::cout << "[2] Show profile."<<std::endl;
        std::cout << "[3] Check Balance."<<std::endl;
        std::cout << "[4] Cancel booked or scheduled tickets."<<std::endl;
        std::cout << "[5] Show all ticket"<<std::endl;
        std::cout << "[6] Book/Schedule ticket."<<std::endl;
        std::cout << "[7] Logout."<<std::endl;
        std::cout << "[8] Exit."<<std::endl;
        std::cin >> option;

        if (option == 1) {
            booking.showMyTickets();
        } else if (option == 2) {
            system("clear");
            std::ifstream sessionReader;
            std::string line;
            sessionReader.open("session.txt");
            getline(sessionReader,line);
            getline(sessionReader,line);
            std::vector<std::string> sessionSplittedData = split(line);
            std::cout << "******************* Personal Info *******************"<<std::endl;
            std::cout << "Name : "<<sessionSplittedData[1]<<std::endl;
            std::cout << "Email : "<<sessionSplittedData[3]<<std::endl;
            std::cout << "Adress : "<<sessionSplittedData[2]<<std::endl;
            std::cout << "Phone number : "<<sessionSplittedData[5]<<std::endl;
            char halt;
            std::cin >> halt;
            system("clear");
        } else if (option == 3) {
            std::string balance = getBalance();
            system("clear");
            std::cout << "Your balance is : "<<balance<<std::endl;

            char halt;
            std::cin >> halt;
            system("clear");
        } else if (option == 4) {
            booking.cancelBooking();

        } else if (option == 5) {
            system("clear");
            ticketStorage.ticketCollection();
            char halt;
            std::cin >> halt;
            system("clear");
            //
        } else if (option == 6) {
            // check ticket availability
            booking.scheduleTicket();
        } else if (option == 7) {
            auth.logout();
            system("clear");
        } else if (option == 8) {
            exit(0);
        }

    }


}


void registerDisplay() {
    Registration::Registration registration;
    Auth::Auth auth;

    std::string name;
    std::string email;
    std::string address;
    std::string password;
    std::string phone;

    Customer customerinfo;

    std::cout <<"Enter your name: ";
    getline(std::cin >> std::ws,name);
    std::cout << "Enter your address: ";
    getline(std::cin >> std::ws,address);
    std::cout << "Enter your email :";
    getline(std::cin,email);
    std::cout << "Enter your password : ";
    getline(std::cin,password);
    std::cout << "Enter your phone number : ";
    getline(std::cin,phone);

    customerinfo.setName(name);
    customerinfo.setEmail(email);
    customerinfo.setAddress(address);
    customerinfo.setPassword(password);
    customerinfo.setPhone(phone);

    registration.addUser(customerinfo);


    auth.login(customerinfo.getEmail(),customerinfo.getPassword());
    system("clear");

}

void loginDisplay() {
    Auth::Auth auth;
    std::string username;
    std::string password;

    std::cout <<"******** Log in display ***********" << std::endl;
    std::cout <<"Enter your username: "<< std::endl;
    std::cin >> username;
    std::cout << "Enter your password : "<<std::endl;
    std::cin >> password;

    auth.login(username,password);
    system("clear");
}
