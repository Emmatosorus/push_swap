CC = cc

CFLAGS = -Werror -Wextra -Wall -MMD -MP

NAME = libftprintf.a

SRC = \
	ft_printf.c \
	ft_printf_functions.c \
	ft_printf_hex_functions.c

OBJ = $(SRC:.c=.o)
OBJ_D = ${OBJ:.o=.d}

# ####### Rules

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

-include $(OBJ_D)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_D)

fclean:	
	rm -f $(OBJ) $(OBJ_D) $(NAME)

re: fclean all

.PHONY: clean fclean all re