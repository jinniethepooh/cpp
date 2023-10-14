#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include <iostream>
# include <string>

class PhoneBook {

	private:
		int current_contact;
		int max_contact;
		int default_width;

		// ADD features
		int is_input_empty(std::string input);
		void get_input(std::string current_field_name, std::string *current_field);

		// SEARCH features
		int is_index_valid(std::string index);
		void format_print(std::string input);
		int print_contact(int i);
		void print_selected_contact(void);
		void print_all_contact(void);

	public:
		// -----> Constructor and destructor
		PhoneBook(void);
		~PhoneBook(void);

		// -----> In-used variables
		Contact contact[8]; // Since dynamic allocation is forbidden, so we hard-coded like this.

		// -----> Features
		// ADD
		void add_contact(void);
		// SEARCH
		void search_contact(void);
};

#endif