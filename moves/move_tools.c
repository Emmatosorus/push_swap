/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:18:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/16 17:20:10 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rm_link(t_stack **stk)
{
	t_stack	*first;
	t_stack	*last;

	first = *stk;
	last = first->prev;
	first = first->next;
	last->next = first;
	first->prev = last;
	first->start = true;
	*stk = first;
}

void	add_link(t_stack **stk, t_stack **new)
{
	t_stack	*secnd;
	t_stack	*last;
	t_stack	*first;

	secnd = *stk;
	first = *new;
	secnd->start = false;
	last = secnd->prev;
	secnd->prev = first;
	last->next = first;
	first->next = secnd;
	first->prev = last;
	*stk = first;
}
