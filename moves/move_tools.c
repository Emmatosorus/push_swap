/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:18:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rm_second(t_stack **stk)
{
	t_stack	*first;
	t_stack	*other;

	other = *stk;
	first = other->next;
	first->next = NULL;
	first->prev = NULL;
	first->start = true;
	other->next = NULL;
	other->prev = NULL;
	*stk = first;
}

void	rm_link(t_stack **stk)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	first = *stk;
	temp = first;
	if (first->next == NULL && first->prev == NULL)
	{
		*stk = NULL;
		return ;
	}
	if (first->next == first->prev)
		rm_second(stk);
	else
	{
		last = first->prev;
		first = first->next;
		last->next = first;
		first->prev = last;
		first->start = true;
		temp->next = NULL;
		temp->prev = NULL;
		*stk = first;
	}
}

static void	add_second(t_stack **stk, t_stack **new)
{
	t_stack	*secnd;
	t_stack	*first;

	secnd = *stk;
	first = *new;
	first->next = secnd;
	first->prev = secnd;
	secnd->next = first;
	secnd->prev = first;
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
	if (secnd->next == NULL)
		add_second(stk, new);
	else
	{
		last = secnd->prev;
		secnd->prev = first;
		last->next = first;
		first->next = secnd;
		first->prev = last;
		*stk = first;
	}
}
