CC = cc

CFLAGS = -Werror -Wextra -Wall -MMD -MP

LINKER = -Llibft -llibft

NAME = push_swap

SRC = \
	main.c \
	utils.c

OBJ = $(SRC:.c=.o)
OBJ_D = ${OBJ:.o=.d}

#---------Rules---------#

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

-include $(OBJ_D)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKER)


clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ) $(OBJ_D)

fclean:	
	$(MAKE) -C libft fclean
	rm -f $(OBJ) $(OBJ_D) $(NAME)

re: fclean all

.PHONY: clean fclean all re
