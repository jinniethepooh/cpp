# include <cstdio>
# include <iostream>

void megaphone(int len, char **str_lst) {

	// -----> In a for loop manner
	for (int i = 1; i < len; i += 1) {
		for (int j = 0; j < (int)strlen(str_lst[i]); j += 1) {
			std::cout << (char)toupper(str_lst[i][j]);
		}
	}
	std::cout << std::endl;

	// -----> In a while loop manner
	// int i = 1;

	// while (str_lst[i]) {
	// 	int j = 0;
	// 	while (str_lst[i][j]) {
	// 		std::cout << (char)toupper(str_lst[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// std::cout << std::endl;
}

int	main(int argc, char **argv) {

	if (argc > 1) {
		megaphone(argc, argv);
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}