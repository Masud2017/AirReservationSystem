#pragma once

#include<iostream>

namespace booking {
    class Booking {
        public:
            void scheduleTicket();
            void cancelBooking();
            int paymentVerify();
            void showMyTickets();
    };
}
