/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:47 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/18 17:29:33 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Remove this for the love of God
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	int				final_pos;
	bool			start;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void	arg_parse(int ac, char **av, t_stack **stack_a);
void	stack_sorter(t_stack **a, t_stack **b);
t_stack	*ft_struct(int nb, bool start);
int		ft_dup_check(int nb, t_stack **lst);
void	mark_pos(t_stack **lst, int max, int rounds, int size);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_front(t_stack *lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	error_exit(t_stack **stack_a, char **strs, int i);
int		is_sorted(t_stack **stack);
int		is_next_smaller(t_stack **stack);
int		is_in_order(t_stack **stack);
int		get_smallest(t_stack **stack);
int		get_biggest(t_stack **stack);
int		get_direction(t_stack **stack);
void	b_has_max(t_stack **a, t_stack **b);
void	rotate_both_dir(t_stack **a, t_stack **b, int dir);
void	rotate_a_dir(t_stack **a, int dir);
void	rotate_b_dir(t_stack **b, int dir);
void	rotate(t_stack **a, t_stack **b, char c);
void	swap(t_stack **a, t_stack **b, char c);
void	rm_link(t_stack **stk);
void	add_link(t_stack **stk, t_stack **new);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a, bool both);
void	rotate_b(t_stack **b, bool both);
void	rotate_both(t_stack **a, t_stack **b);
void	rev_rotate_a(t_stack **a, bool both);
void	rev_rotate_b(t_stack **b, bool both);
void	rev_rotate_both(t_stack **a, t_stack **b);
void	swap_a(t_stack **a, bool both);
void	swap_b(t_stack **b, bool both);
void	swap_both(t_stack **a, t_stack **b);

#endif