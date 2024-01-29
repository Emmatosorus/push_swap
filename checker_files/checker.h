
#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

typedef struct s_list 
{
	char			*move;
	struct s_list	*next;
}					t_list;

void	get_moves(t_stack **a, t_stack **b, t_list **move_list);
void	error_exit_checker(t_stack **a, t_stack **b, t_list **move_list, char *str);
void	ft_free_list(t_list **lst);

#endif