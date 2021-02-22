#pragma once

#include <iostream>

class Customer {
    private:
        int id;
        std::string name;
        std::string address;
        std::string email;
        std::string password;
        std::string phone;
    public:
       void setId(int id);
       int getId();
       void setName(std::string name);
       std::string getName();
       void setAddress(std::string address);
       std::string getAddress();
       void setEmail(std::string email);
       std::string getEmail();
       void setPassword(std::string password);
       std::string getPassword();
       void setPhone(std::string phone);
       std::string getPhone();
       std::string toString();
};
