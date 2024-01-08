CC = cc

CFLAGS = -Werror -Wextra -Wall -MMD -MP

LINKER = -Lft_printf_ps -lftprintf	

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
	$(MAKE) -C ft_printf_ps
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKER)


clean:
	$(MAKE) -C ft_printf_ps clean
	rm -f $(OBJ) $(OBJ_D)

fclean:	
	$(MAKE) -C ft_printf_ps fclean
	rm -f $(OBJ) $(OBJ_D) $(NAME)

re: fclean all

.PHONY: clean fclean all re
