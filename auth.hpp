#pragma once

#include <iostream>

namespace Auth {
    class Auth {
        public:
            int login(std::string username,std::string password);
            int logout();
    };
}

