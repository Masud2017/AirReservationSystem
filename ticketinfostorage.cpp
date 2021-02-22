#include "ticketinfostorage.hpp"
#include "func.hpp"

#include <fstream>

namespace ticketStorage {
    void TicketStorage::__init__() {
        std::ofstream ticketStorageWritter;
        std::ifstream ticketStorageReader;
        ticketStorageReader.open("ticketStorage.txt");

        if (ticketStorageReader.good()) {
            return ;
        } else {
            ticketStorageWritter.open("ticketStorage.txt");

            ticketStorageWritter <<"Dhaka to Barishal,avail=10,price=5"<<std::endl;
            ticketStorageWritter <<"Sylhet to Dhaka,avail=4,price=5"<<std::endl;
            ticketStorageWritter <<"Barishal to Dhaka,avail=5,price=7"<<std::endl;
            ticketStorageWritter <<"Dhaka to Sylhet,avail=2,price=7"<<std::endl;
            ticketStorageWritter <<"Dhaka to Chittagong,avail=3,price=10"<<std::endl;
            ticketStorageWritter <<"Chittagong to Dhaka,avail=7,price=10"<<std::endl;
            ticketStorageWritter <<"Dhaka to Kustia,avail=5,price=15"<<std::endl;
            ticketStorageWritter <<"Kustia to Dhaka,avail=6,price=10"<<std::endl;
            ticketStorageWritter <<"Dhaka to Jessior,avail=0,price=10"<<std::endl;
            ticketStorageWritter <<"Jessior to Dhaka,avail=1,price=10"<<std::endl;

            ticketStorageWritter.close();
        }
    }

    std::vector<std::string> TicketStorage::getTicketCollection() {
        std::vector<std::string> ticketCollection;
        std::ifstream ticketReader;
        ticketReader.open("ticketStorage.txt");
        std::string line;

        while(ticketReader) {


            getline(ticketReader,line);
            size_t found = line.find(",");
            if (found != std::string::npos)
                ticketCollection.push_back(line);
        }
        return ticketCollection;
    }

    int TicketStorage::isTicketAvailable(std::string destinationString) {
        // WE HAVE TO CREATE A PARSER FOR AVAILE ABLE NUMBER OF THE TICKET .... AS LIKE WE DID FOR COMMA SEPERATION.
        std::ifstream ticketReader;
        std::string line;
        std::vector<std::string> ticketDataSplited;

        while(ticketReader) {
            getline(ticketReader,line);
            ticketDataSplited = split(line);

            if (ticketDataSplited[0] == destinationString) {
                int avail = 0;
                std::vector<std::string> priceSplittedData = splitWithEqual(ticketDataSplited[1]);
                std::stringstream stream(priceSplittedData[1]);
                stream >> avail;

                if (avail > 0) {
                    return 0;
                } else {
                    return -1;
                }
            }
        }
    }

    void TicketStorage::ticketCollection() {
        std::vector<std::string> ticketCollection = getTicketCollection();

        std::cout << "************** Ticket list ****************" <<std::endl;

        for (int i = 0; i < ticketCollection.size(); i++) {
            std::cout << ticketCollection.at(i) <<std::endl;
        }
    }
}
