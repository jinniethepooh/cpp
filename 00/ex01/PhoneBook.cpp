# include "PhoneBook.class.hpp"
# include <iostream>
# include <string>

PhoneBook::PhoneBook(void) {

	// Initialise latest accessed contact index.
	current_contact = 0;
	max_contact = 8;
	default_width = 10;
}


PhoneBook::~PhoneBook(void) {
}


/*
-------------------------------------------------------------------------------------
ADD: save a new contact
	◦ If the user enters this command, they are prompted to input the information
	of the new contact one field at a time. Once all the fields have been completed,
	add the contact to the phonebook.
	◦ The contact fields are: first name, last name, nickname, phone number, and
	darkest secret. A saved contact can’t have empty fields.
-------------------------------------------------------------------------------------
*/
int PhoneBook::is_input_empty(std::string input) {

	for(int i = 0; i < (int)input.length(); i++) {
		if (!isspace(input[i])) { return 0; }
	}
	return 1;
}


void PhoneBook::get_input(std::string current_field_name, std::string *current_field) {

	std::string tmp = "";
	std::cout << current_field_name;
	std::getline(std::cin, tmp);

	while (PhoneBook::is_input_empty(tmp)) {
		std::cout << "Please provide valid input (not empty nor only whitespace input)." << std::endl;
		std::cout << current_field_name;
		std::getline(std::cin, tmp);
	}

	*current_field = tmp;
}


void PhoneBook::add_contact(void) {

	if (PhoneBook::current_contact == PhoneBook::max_contact) {
		PhoneBook::current_contact = 0;
	}

	PhoneBook::get_input("First name: ", &PhoneBook::contact[PhoneBook::current_contact].first_name);
	PhoneBook::get_input("Last name: ", &PhoneBook::contact[PhoneBook::current_contact].last_name);
	PhoneBook::get_input("Nickname: ", &PhoneBook::contact[PhoneBook::current_contact].nick_name);
	PhoneBook::get_input("Phone number: ", &PhoneBook::contact[PhoneBook::current_contact].phone_number);
	PhoneBook::get_input("Darkest secret: ", &PhoneBook::contact[PhoneBook::current_contact].secrecy);
	std::cout << "Successfully add new contact!" << std::endl;

	PhoneBook::current_contact += 1;
}


/*
-------------------------------------------------------------------------------------
SEARCH: display a specific contact
	◦ Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname.
	◦ Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’).
	◦ Then, prompt the user again for the index of the entry to display. If the index
	is out of range or wrong, define a relevant behavior. Otherwise, display the
	contact information, one field per line.
-------------------------------------------------------------------------------------
*/
void PhoneBook::format_print(std::string input) {

	int space_size;

	if (input.length() < PhoneBook::default_width) {
		space_size = PhoneBook::default_width - input.length();
		for (int i = 0; i < space_size; i++) {
			std::cout << " ";
		}
		std::cout << input;
	}
	else {
		for (int i = 0; i < PhoneBook::default_width - 1; i++) {
			std::cout << input[i];
		}
		std::cout << ".";
	}
}


int PhoneBook::print_contact(int i) {

	if (!PhoneBook::is_input_empty(PhoneBook::contact[i].first_name)) {
		std::cout << "| ";
		PhoneBook::format_print(std::to_string(i + 1));
		std::cout << " | ";
		PhoneBook::format_print(PhoneBook::contact[i].first_name);
		std::cout << " | ";
		PhoneBook::format_print(PhoneBook::contact[i].last_name);
		std::cout << " | ";
		PhoneBook::format_print(PhoneBook::contact[i].nick_name);
		std::cout << " |" << std::endl;

		return 0;
	}
	else {
		return 1;
	}
}


void PhoneBook::print_all_contact(void) {

	int empty_count = 0;
	std::cout << "┌╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐" << std::endl;
	std::cout << "|      Index | First name |  Last name |   Nickname |" << std::endl;
	std::cout << "├╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┤" << std::endl;
	for (int i = 0; i < PhoneBook::max_contact; i++) {
		empty_count += PhoneBook::print_contact(i);
	}
	if (empty_count == PhoneBook::max_contact) {
		std::cout << "|                                        No contact |" << std::endl;
	}
	std::cout << "└╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘" << std::endl;
}

int PhoneBook::is_index_valid(std::string index) {

	int valid_flag;

	for (int i = 0; i < PhoneBook::max_contact; i++) {
		if (!index.compare(std::to_string(i + 1))) {
			return 1;
		}
	}
	return 0;
}

void PhoneBook::print_selected_contact(void) {

	std::string tmp;
	int i;

	std::cout << "Input the contact index for more information: ";
	std::getline(std::cin, tmp);
	if (is_index_valid(tmp)) {
		i = std::stoi(tmp) - 1;
		if (!PhoneBook::is_input_empty(PhoneBook::contact[i].first_name)) {
			std::cout << "First name: " << PhoneBook::contact[i].first_name << std::endl;
			std::cout << "Last name: " << PhoneBook::contact[i].last_name << std::endl;
			std::cout << "Nickname: " << PhoneBook::contact[i].nick_name << std::endl;
			std::cout << "Phone number: " << PhoneBook::contact[i].phone_number << std::endl;
			std::cout << "Darkest secret: " << PhoneBook::contact[i].secrecy << std::endl;
		}
		else {
			std::cout << "No data of this contact." << std::endl;
		}
	}
	else {
		std::cout << "You provided the invalid index, please try again next time." << std::endl;
	}

}

void PhoneBook::search_contact(void) {

	PhoneBook::print_all_contact();
	PhoneBook::print_selected_contact();
}