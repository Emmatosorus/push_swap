CC = cc

CFLAGS = -Werror -Wextra -Wall

HDR = push_swap.h

LIB_HDR = libft/libft.h

BNS_HDR = checker_files/checker.h 

LINKER = -Llibft -lft

NAME = push_swap

BNS_NAME = checker

#---------Sources---------#

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
	moves/swaps.c \
	algorythme_2/sort_stacks.c \
	algorythme_2/pre_sort.c \
	algorythme_2/rotate_tools.c \
	algorythme_2/cost_math.c \
	algorythme_2/cost_tools_forward.c \
	algorythme_2/cost_tools_bckward.c \
	algorythme_2/order_checkers.c \
	algorythme_1/sort_stacks.c \
	algorythme_1/sort_tools.c \
	algorythme_1/rotate_tools.c

OBJ = $(SRC:.c=.o)

BNS_SRC = \
		errors/error_manager.c \
		checker_files/main_checker.c \
		checker_files/checker_arg_manager.c \
		checker_files/checker_errors.c \
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

BNS_OBJ = $(BNS_SRC:.c=.o)

#---------Rules---------#

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ) $(HDR) $(LIB_HDR) $(BNS_OBJ) $(BNS_HDR) $(LIB_HDR)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKER)

bonus: $(BNS_OBJ) $(BNS_HDR) $(LIB_HDR)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(BNS_OBJ) -o $(BNS_NAME) $(LINKER)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ) $(BNS_OBJ)

fclean:	
	$(MAKE) -C libft fclean
	rm -f $(OBJ) $(BNS_OBJ) $(NAME) $(BNS_NAME)

re: fclean all

.PHONY: clean fclean all re
