#pragma once

class Money {
    private:
        std::string email;
        int ammount;
    public:
        void setEmail(std::string email);
        std::string getEmail();
        void setAmmount(int ammount);
        int getAmmount();
};
