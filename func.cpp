#include "func.hpp"
#include "customer.hpp"

#include <fstream>
#include <sstream>
#include <string>

std::vector<std::string> split(std::string str) {
    std::stringstream stream(str);
    std::vector<std::string> vect;
    while(stream.good()) {
        std::string subs;
        getline(stream,subs,',');
        vect.push_back(subs);
    }

    return vect;
}

std::vector<std::string>splitWithEqual(std::string str) {
    std::stringstream stream(str);
    std::vector<std::string> vect;

    while(stream.good()) {
        std::string subs;
        getline(stream,subs,'=');
        vect.push_back(subs);
    }
    return vect;
}

void addBalance(Customer customerinfo) {
    std::ofstream balanceWriter;
    balanceWriter.open("money/"+customerinfo.getEmail()+".txt",std::ios::app);

    std::string user = customerinfo.getEmail();
    balanceWriter << user <<","<<"100"<<std::endl;
}

std::string getBalance() {
    std::ifstream balanceFileReader;
    balanceFileReader.open("money/"+getCurrentUserEmail()+".txt");
    std::ifstream sessionReader;
    sessionReader.open("session.txt");
    std::string line;
    std::string line2;

    getline(sessionReader,line2);
    getline(sessionReader,line2);// we got the user info
    std::vector<std::string> loggedInUser = split(line2);

    while(balanceFileReader) {
        getline(balanceFileReader,line);
        std::vector<std::string> balanceFragment = split(line);

        if (loggedInUser[3] == balanceFragment[0]) {
            return balanceFragment[1];
        }
    }
    return NULL;
}


std::string getCurrentUserEmail() {
    std::ifstream sessionReader;
    sessionReader.open("session.txt");
    std::string line;
    std::vector<std::string> splittedSessionUserInfo;

    getline(sessionReader,line);
    getline(sessionReader,line);

    splittedSessionUserInfo = split(line);

    return splittedSessionUserInfo[3];
}

int stringToInteger(std::string str) {
    std::stringstream stream(str);

    int responseInt = 0;
    stream >> responseInt;

    return responseInt;
}

int getAvaileAbleTicket(std::string ticket) {
    std::vector<std::string> splittedTicket = split(ticket);
    std::vector<std::string> splittedAvaile = splitWithEqual(splittedTicket[1]);
    int availe = 0;
    std::stringstream stream(splittedAvaile[1]);
    stream >> availe;

    return availe;
}

int getPriceTicket(std::string ticket) {
    std::vector<std::string> splittedTicket = split(ticket);
    std::vector<std::string> splittedPrice = splitWithEqual(splittedTicket[2]);
    int price = 0;
    std::stringstream stream(splittedPrice[1]);
    stream >> price;

    return price;
}

int getCurrentUserBalance() {
    std::ifstream balanceReader;
    balanceReader.open("money/"+getCurrentUserEmail()+".txt");
    std::string userEmail = getCurrentUserEmail();
    std::string line;
    int balance;

    while (balanceReader) {
        getline(balanceReader,line);
        std::vector<std::string> userVect = split(line);
        if (userEmail == userVect[0]) {
            std::stringstream stream(userVect[1]);

            stream >> balance;

            return balance;
        } else
            return 0;
    }
}

void updateUserBalance(int balance) {
    if (balance < 1) {
        std::cout << "Sorry you are out of money !!"<<std::endl;
    } else {
        std::string balanceStr = std::to_string(balance);
    std::string userEmail = getCurrentUserEmail();

    std::ifstream balanceReader;
    balanceReader.open("money/"+getCurrentUserEmail()+".txt");
    std::string line;
    std::vector<std::string> splitLine;
    std::vector<std::string> balanceBackup;

    while (balanceReader) {
        getline(balanceReader,line);
        balanceBackup.push_back(line);
    }


    for (int i = 0; i < balanceBackup.size(); i++) {
        splitLine = split(balanceBackup.at(i)); // equivilant of getline()

        if (userEmail == splitLine[0]) {
            //
            splitLine[1] = balanceStr;
            std::string str = splitLine[0]+","+splitLine[1];
            balanceBackup[i] = str;
        }

    }
    std::ofstream balanceWriter("money/"+getCurrentUserEmail()+".txt");
    for (int i = 0; i < balanceBackup.size(); i++) {

        balanceWriter << balanceBackup[i]+"\n";
    }



    }

}


void updateTicketList(int ticketAvailable,std::string tickLine) {
    if (ticketAvailable < 1) {
        std::cout << "Ticket is out of stock come back later !!"<<std::endl;
    } else {
        std::string ticketAvailableStr = std::to_string(ticketAvailable);
        std::vector<std::string> ticketLineSplitted = split(tickLine);
        std::ifstream ticketStorageReader;
        ticketStorageReader.open("ticketStorage.txt");
        std::vector<std::string> ticketList;
        std::string line;

        while(ticketStorageReader) {
            getline (ticketStorageReader,line);
            ticketList.push_back(line);
        }
        std::vector<std::string> ticketListSplitted;
        std::string strToBeReplaced;
        for (int i = 0; i < ticketList.size(); i++) {
            ticketListSplitted = split(ticketList[i]);
            if (ticketLineSplitted[0] == ticketListSplitted[0]) {
                strToBeReplaced = ticketListSplitted[0]+","+"avail="+ticketAvailableStr+","+ticketListSplitted[2];
                ticketList[i] = strToBeReplaced;
            }
        }

        std::ofstream ticketStorageWriter;
        ticketStorageWriter.open("ticketStorage.txt");

        for (int i = 0; i < ticketList.size();i++) {
            ticketStorageWriter<<ticketList[i]<<std::endl;
        }
    }


}

void deleteUserTicket(int idx) {
    std::ifstream userTicketReader;
    userTicketReader.open("userDb/"+getCurrentUserEmail()+".txt");
    std::string line;
    std::vector<std::string>userTicketVect;

    while(userTicketReader) {
        getline (userTicketReader,line);
        userTicketVect.push_back(line);
    }
    userTicketVect.erase(userTicketVect.begin() + (idx - 1));
    std::ofstream userTicketWriter;
    userTicketWriter.open("userDb/"+getCurrentUserEmail()+".txt");
    for (int i = 0; i < userTicketVect.size(); i++) {
        userTicketWriter << userTicketVect[i] <<std::endl;
    }
}
