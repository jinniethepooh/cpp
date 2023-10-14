NAME	= megaphone
SRC_FIL	= megaphone

CPP		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

BORG	= "\033[1;38;5;220m"
SYEL	= "\033[38;5;229m"
ENDCL	= "\033[0;37m"

SRCS	= $(addsuffix .cpp, $(SRC_FIL))

all: $(NAME)

$(NAME):
	@$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo $(BORG)"... megaphone ..."$(ENDCL)

clean:
	@echo $(SYEL)"... finished cleaning ..."$(ENDCL)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME).dSYM
	@$(RM) .DS_Store
	@echo $(SYEL)"... finished f-cleaning ..."$(ENDCL)

re: fclean all

.PHONY: all clean fclean re