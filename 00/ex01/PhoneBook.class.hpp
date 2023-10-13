#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include <iostream>
# include <string>

class PhoneBook {

	private:
		std::string *contact_fields;
		int current_contact;
		int max_contact;
		int default_width;

		// ADD features
		int is_input_empty(std::string input);
		void get_input(std::string current_field_name, std::string *current_field);

		// SEARCH features
		void format_print(std::string input);
		int is_index_valid(std::string index);
		int print_contact(int i);
		void print_selected_contact(void);
		void print_all_contact(void);

	public:
		// -----> Constructor and de-constructor
		PhoneBook(void);
		~PhoneBook(void);

		// -----> In-used variables
		Contact contact[8]; // Since dynamic allocation is forbidden, so we hard-coded like this.

		// -----> Features
		void add_contact(void);
		void search_contact(void);
};

#endif