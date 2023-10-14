# include <iostream>
# include <string>
# include "Contact.class.hpp"
# include "Contact.cpp"
# include "PhoneBook.class.hpp"
# include "PhoneBook.cpp"

std::string welcome_msg = "Welcome to Awwwwwwwwwwwwful Phonebook!";

void distribute_job(std::string command, PhoneBook *book) {
	if (!command.compare("ADD")) {
		book->add_contact();
	}
	else if (!command.compare("SEARCH")) {
		book->search_contact();
	}
	else if (!command.compare("EXIT")) {
		return ;
	}
	else {
		std::cout << "Your command is invalid. Please choose between 'ADD', SEARCH' and 'EXIT'." << std::endl;
	}
}

int	main(void) {

	std::string command;
	std::cout << welcome_msg << std::endl;
	PhoneBook book;

	while (command.compare("EXIT")) {
		std::cout << "Enter your command: ";
		std::getline(std::cin, command);
		distribute_job(command, &book);
	}
	return 0;
}