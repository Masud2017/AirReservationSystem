#include <iostream>

#include "registration.hpp"
#include "customer.hpp"
#include "menu.hpp"
#include "auth.hpp"
#include "ticketinfostorage.hpp"

using namespace std;

int main(void) {
	Registration::Registration reg;
	Customer customerInfo;
	ticketStorage::TicketStorage ticketStorage;

	Menu menu;
	reg.__init__();
	ticketStorage.__init__(); // this function is going to run only once if we don't have the ticketStorage file.

	menu.welcomeMessage();

	while(1) {
        menu.actualWindow();
	}



	return 0;
}
