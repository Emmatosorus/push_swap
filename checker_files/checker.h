/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:59:58 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 10:00:20 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

typedef struct s_list
{
	char			*move;
	struct s_list	*next;
}					t_list;

void	get_moves(t_stack **a, t_stack **b, t_list **move_list);
void	checker_exit(t_stack **a, t_stack **b, t_list **mv_lst, char *str);
void	ft_free_list(t_list **lst);

#endif