#include "Booking.hpp"
#include "ticketinfostorage.hpp"
#include "func.hpp"

#include <unistd.h>
#include <fstream>
#include <sstream>

namespace booking {
    void Booking::scheduleTicket() {
        system("clear");
        ticketStorage::TicketStorage ticketStorage;
        int option = 0;
        int paymentOption = 0;

        std::vector<std::string> ticketCollection = ticketStorage.getTicketCollection();

        std::cout << "********** Book/Schedule ticket **********"<<std::endl;

        for (int i = 0; i < ticketCollection.size(); i++) {
            std::cout << "["<< i+1<<"]"<< " " << ticketCollection.at(i) << std::endl;
        }
        std::cout << "Choose one ticket :"<<std::endl;
        std::cin >> option;


                std::cout <<"Do you want to pay the money now or later: "<<std::endl<<"Enter your choice: [1] or [2]"<<std::endl;
                std::cin >> paymentOption;
                std::string ticket;

                if (paymentOption == 1) {
                     std::cout <<"Booking process with payment is established please wait for the confirmation... "<<std::endl;

                    std::string userEmail = getCurrentUserEmail();
                    std::ofstream ticketUserListWriter;
                    ticketUserListWriter.open("userDb/"+userEmail+".txt",std::ios::app);
                    int userBalance = getCurrentUserBalance();
                    if (userBalance < 1) {
                        std::cout << "Ticket stock has finished come again letter!"<<std::endl;

                    } else {

                    std::string tickLine;


                    std::ifstream ticketStorageReader;
                    ticketStorageReader.open("ticketStorage.txt");

                    for (int i = 0; i < option; i++) {
                        getline(ticketStorageReader,tickLine);
                    }
                    int ticketAvailable = getAvaileAbleTicket(tickLine);
                    int ticketPrice = getPriceTicket(tickLine);
                    std::vector<std::string> splittedTicketLine = split(tickLine);
                    std::string ticketName = splittedTicketLine[0];
                    std::string date;
                    std::cout << "Enter the date for your travle: ";
                    std::cin >> date;

                    ticketUserListWriter <<ticketName<<","<<"true"<<","<<date<<std::endl;

                    ticketAvailable = ticketAvailable - 1;
                    userBalance = userBalance - ticketPrice;


                    // We are going to update balance and ticket

                    updateUserBalance(userBalance);
                    updateTicketList(ticketAvailable,tickLine);
                    }
                } else if (paymentOption == 2) {
                     std::cout <<"Booking process without payment is established please wait for the confirmation... "<<std::endl;

                    std::string userEmail = getCurrentUserEmail();
                    std::ofstream ticketUserListWriter;
                    ticketUserListWriter.open("userDb/"+userEmail+".txt",std::ios::app);
                    int userBalance = getCurrentUserBalance();
                    if (userBalance < 1) {
                        std::cout << "Ticket stock has finished come again letter!"<<std::endl;

                    } else {

                    std::string tickLine;


                    std::ifstream ticketStorageReader;
                    ticketStorageReader.open("ticketStorage.txt");

                    for (int i = 0; i < option; i++) {
                        getline(ticketStorageReader,tickLine);
                    }
                    int ticketAvailable = getAvaileAbleTicket(tickLine);
                    int ticketPrice = getPriceTicket(tickLine);
                    std::vector<std::string> splittedTicketLine = split(tickLine);
                    std::string ticketName = splittedTicketLine[0];
                    std::string date;
                    std::cout << "Enter the date for your travle: ";
                    std::cin >> date;

                    ticketUserListWriter <<ticketName<<","<<"false"<<","<<date<<std::endl;

                    ticketAvailable = ticketAvailable - 1;
                    userBalance = userBalance - ticketPrice;


                    // We are going to update balance and ticket

                    updateUserBalance(userBalance);
                    updateTicketList(ticketAvailable,tickLine);
                    }


                }


        sleep(3);
        system("clear");
    }


    void Booking::showMyTickets() {
        system("clear");
        std::ifstream myTickets;
        char halt = 0;
        myTickets.open("userDb/"+getCurrentUserEmail()+".txt");
        std::string line;
        std::vector<std::string> myTicketVect;
        while (myTickets) {
            if (myTickets.good()){
                getline(myTickets,line);
                size_t found = line.find(",");
                if (found != std::string::npos)
                    myTicketVect.push_back(line);
            }
        }
        std::cout << "My ticket list"<<std::endl;
        for (int i = 0; i < myTicketVect.size(); i++) {
            std::vector<std::string> splittedTickVect = split(myTicketVect.at(i));
            std::string isVerified = (splittedTickVect[1] == "true")?"-- Payment Verified --":" -- Payment not verified --";
            std::cout<<splittedTickVect[0]<<" " << isVerified <<" " <<"-- Date: "<<splittedTickVect[2] <<std::endl;
        }
        std::cin >> halt;

        system("clear");

    }

    void Booking::cancelBooking() {
        system("clear");
        char halt;
        std::vector<std::string> myTicketVect;
        std::ifstream myTicketReader;
        myTicketReader.open("userDb/"+getCurrentUserEmail()+".txt");
        std::string line;
        int cancelOption;

        while (myTicketReader) {
            getline(myTicketReader,line);
            size_t found = line.find(",");
            if (found != std::string::npos)
                myTicketVect.push_back(line);
        }
        std::cout << "******************* Ticket Cancelation system *****************"<<std::endl;

        for (int i = 0; i < myTicketVect.size(); i++) {
            std::vector<std::string> splittedTickVect = split(myTicketVect.at(i));
            std::string isVerified = (splittedTickVect[1] == "true")?"-- Payment Verified --":" -- Payment not verified --";
            std::cout<<"["<<i+1<<"] "<<splittedTickVect[0]<<" " << isVerified <<" " <<"-- Date: "<<splittedTickVect[2] <<std::endl;
        }
        std::cout << "Enter the ticket number you want to cancel: ";
        std::cin >> cancelOption;

        std::string tickLine;
        std::ifstream ticketStorageReader;
        ticketStorageReader.open("ticketStorage.txt");

        std::ifstream userTicketReader;
        userTicketReader.open("userDb/"+getCurrentUserEmail()+".txt");
        std::string userTicketReaderLine;
        std::vector<std::string>userTicketVect;

        while(userTicketReader) {
            getline (userTicketReader, userTicketReaderLine);
            userTicketVect.push_back(userTicketReaderLine);
        }
        std::vector<std::string> splittedUserTicketVect = split(userTicketVect[cancelOption - 1]);


        while (ticketStorageReader) {
            getline(ticketStorageReader,tickLine);
            std::vector<std::string> ticketLineSplitted = split(tickLine);

            if (ticketLineSplitted[0] == splittedUserTicketVect[0]) {
                break;
            }
        }

        int availAbleTicket = getAvaileAbleTicket(tickLine);
        availAbleTicket += 1;
        std::cout << "Value of tickLine "<<tickLine<<std::endl;
        int tickPrice = getPriceTicket(tickLine);
        int userBalance = getCurrentUserBalance();
        userBalance = userBalance + tickPrice;


        updateTicketList(availAbleTicket,tickLine);
        updateUserBalance(userBalance);
        deleteUserTicket(cancelOption);



        system("clear");
    }
}
