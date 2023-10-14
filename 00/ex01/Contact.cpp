# include <iostream>
# include "Contact.class.hpp"

Contact::Contact(void) {

	// Initialise each contact field with default value.
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	secrecy = "";
}

Contact::~Contact(void) {
}