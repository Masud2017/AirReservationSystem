#pragma once

#include <vector>
#include <iostream>

namespace ticketStorage {
    class TicketStorage {
        private:
            // protected member variables
        public:
            void __init__ ();
            std::vector<std::string> getTicketCollection();
            int isTicketAvailable(std::string destinationString);
            void ticketCollection ();
    };
}
