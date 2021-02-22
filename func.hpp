#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "customer.hpp"
#include "ticketinfostorage.hpp"

std::vector<std::string> split(std::string str);
void addBalance(Customer customerinfo);
std::string getBalance();
std::vector<std::string> splitWithEqual(std::string str);
std::string getCurrentUserEmail();
int stringToInteger(std::string str);
int getAvaileAbleTicket(std::string ticket);
int getPriceTicket(std::string ticket);
int getCurrentUserBalance();

void updateUserBalance(int balance);
void deleteUserTicket(int idx);
void updateTicketList(int ticketAvailable,std::string tickLine);
