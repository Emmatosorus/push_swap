/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:59:58 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 12:35:42 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_list
{
	char			*move;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	int				nb;
	int				final_pos;
	int				temp_pos;
	bool			start;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void	arg_parse(int ac, char **av, t_stack **stack_a);
void	get_moves(t_stack **a, t_stack **b, t_list **move_list);
void	checker_exit(t_stack **a, t_stack **b, t_list **mv_lst, char *str);
void	ft_free_list(t_list **lst);
void	ft_free_stack(t_stack **lst);

// ---------- Needed for Moves -----------
void	rm_link(t_stack **stk);
void	add_link(t_stack **stk, t_stack **new);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	rev_rotate_a(t_stack **a);
void	rev_rotate_b(t_stack **b);
void	rev_rotate_both(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_both(t_stack **a, t_stack **b);

#endif