CC = cc

CFLAGS = -Werror -Wextra -Wall

HDR = push_swap.h

LIB_HDR = libft/libft.h

LIB_AR = libft/libft.a

LINKER = -Llibft -lft

NAME = push_swap

#---------Sources---------#

SRC = \
	main.c \
	errors/error_manager.c \
	structs/argument_manager.c \
	structs/struct_tools.c \
	structs/ft_lstadd_back.c \
	structs/ft_lstclear.c \
	structs/ft_lstsize.c \
	structs/ft_lstlast.c \
	moves/move_tools.c \
	moves/pushes.c \
	moves/rotates.c \
	moves/rev_rotates.c \
	moves/swaps.c \
	algorythm_big/sort_stacks.c \
	algorythm_big/pre_sort.c \
	algorythm_big/rotate_tools.c \
	algorythm_big/cost_math.c \
	algorythm_big/cost_tools_forward.c \
	algorythm_big/cost_tools_bckward.c \
	algorythm_big/order_checkers.c \
	algorythm_small/sort_stacks.c \
	algorythm_small/sort_tools.c \
	algorythm_small/rotate_tools.c

OBJ = $(SRC:%.c=%.o)

#---------Rules---------#

all : $(NAME)

%.o: %.c $(HDR) $(LIB_AR)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKER)

bonus: force
	$(MAKE) -C checker_files

$(LIB_AR): force
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C checker_files clean
	rm -f $(OBJ)

fclean:	
	$(MAKE) -C libft fclean
	$(MAKE) -C checker_files fclean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus force
