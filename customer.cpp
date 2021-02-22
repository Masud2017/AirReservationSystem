#include "customer.hpp"

#include <sstream>

void Customer::setId(int Custid) {id = Custid;}
int Customer::getId() {return id;}

void Customer::setName(std::string Custname){name = Custname;}
std::string Customer::getName() {;return name;}

void Customer::setAddress(std::string Custaddress) {address = Custaddress;}
std::string Customer::getAddress() {return address;}

void Customer::setEmail(std::string Custemail) {email = Custemail;}
std::string Customer::getEmail() {return email;}

void Customer::setPassword(std::string Custpassword) {password = Custpassword;}
std::string Customer::getPassword() {return password;}

void Customer::setPhone(std::string Custphone) {phone = Custphone;}
std::string Customer::getPhone() {return phone;}

std::string Customer::toString() {
    std::stringstream convertable;
    convertable << id;
    std::string id_string;
    convertable >> id_string;
    return (std::string)id_string+","+name+","+address+","+email+","+password+","+phone;

}
