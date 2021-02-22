#pragma once

#include "customer.hpp"
#include <fstream>
#include "func.hpp"

namespace Registration {
    class Registration {
        private:
            std::ofstream fout;
        public:
            void __init__();
            void addUser(Customer customerInfo);
    };
}
