CC = cc

CFLAGS = -Werror -Wextra -Wall -MMD -MP -g3#-fsanitize=address

LINKER = -Llibft -lft

NAME = push_swap

SRC = \
	main.c \
	errors/error_manager.c \
	structs/argument_manager.c \
	structs/struct_tools.c \
	structs/ft_lstadd_back_bonus.c \
	structs/ft_lstclear_bonus.c \
	structs/ft_lstsize_bonus.c \
	structs/ft_lstlast_bonus.c \
	moves/move_tools.c \
	moves/pushes.c \
	moves/rotates.c \
	moves/rev_rotates.c \
	moves/swaps.c
	# algorythme/sort_stacks.c

	# structs/ft_lstnew_bonus.c \
	# structs/ft_lstdelone_bonus.c \
	# structs/ft_lstadd_front_bonus.c \
	# structs/ft_lstiter_bonus.c \
	# structs/ft_lstmap_bonus.c

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
	$(MAKE) clean # You might want to remove this


clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ) $(OBJ_D)

fclean:	
	$(MAKE) -C libft fclean
	rm -f $(OBJ) $(OBJ_D) $(NAME)

re: fclean all

.PHONY: clean fclean all re
