#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

class Contact {

	public:
		
		// A saved contact can’t have empty fields.
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string secrecy;

		// -----> Constructor and destructor
		Contact(void);
		~Contact(void);
};

#endif