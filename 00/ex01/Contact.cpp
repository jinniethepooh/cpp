# include <iostream>
# include "Contact.class.hpp"

Contact::Contact(void) {
	// std::cout << "Contact constructure is called." << std::endl;

	// Initialise each contact field with default value.
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	secrecy = "";

	return ;
}

Contact::~Contact(void) {
	// std::cout << "Contact destructure is called." << std::endl;
	return ;
}