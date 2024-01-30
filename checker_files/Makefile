CC = cc

CFLAGS = -Werror -Wextra -Wall -g3

LIB_HDR = ../libft/libft.h

LIB_AR = ../libft/libft.a

HDR = checker.h 

LINKER = -L../libft -lft

NAME = ../checker

#---------Sources---------#

SRC = \
	main_checker.c \
	checker_arg_manager.c \
	checker_errors.c \
	argument_manager_bn.c \
	struct_tools_bn.c \
	ft_lstadd_back_bn.c \
	ft_lstclear_bn.c \
	ft_lstsize_bn.c \
	ft_lstlast_bn.c \
	move_tools_bn.c \
	pushes_bn.c \
	rotates_bn.c \
	rev_rotates_bn.c \
	swaps_bn.c

OBJ = $(SRC:%.c=%.o)

#---------Rules---------#

all : $(NAME)

%.o: %.c $(HDR) $(LIB_AR)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKER)

$(LIB_AR): force
	$(MAKE) -C ../libft

clean:
	$(MAKE) -C ../libft clean
	rm -f $(OBJ)

fclean:	
	$(MAKE) -C ../libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re force
