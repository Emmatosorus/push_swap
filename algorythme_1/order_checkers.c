/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:12 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/22 15:22:18 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_in_order(t_stack **stack)
{
	int		min;
	t_stack	*ptr;
	t_stack	*temp;

	ptr = *stack;
	min = get_smallest(stack);
	while (ptr->final_pos != min)
		ptr = ptr->next;
	ptr = ptr->next;
	while (ptr->final_pos != min)
	{
		temp = ptr->next;
		if (ptr->nb > temp->nb && temp->final_pos != min)
			return (-1);
		ptr = temp;
	}
	return (1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*ptr;
	int		prev_nb;

	ptr = *stack;
	if (!ptr)
		return (0);
	if (ptr->next != NULL && ptr->prev != NULL)
	{
		prev_nb = ptr->nb;
		ptr = ptr->next;
		while (ptr->start == false)
		{
			if (prev_nb > ptr->nb)
				return (-1);
			prev_nb = ptr->nb;
			ptr = ptr->next;
		}
	}
	return (1);
}

int	is_next_smaller(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (!ptr)
		return (0);
	if (ptr->next != NULL && ptr->prev != NULL)
	{
		prev = ptr->nb;
		ptr = ptr->next;
		if (ptr->nb < prev)
			return (1);
	}
	return (-1);
}

int	next_is_sorted(t_stack **stack)
{
	int		max;
	t_stack	*ptr;
	t_stack	*prev;

	ptr = *stack;
	max = get_biggest(stack);
	while (ptr->final_pos != max)
	{
		prev = ptr;
		ptr = ptr->next;
		if (prev->final_pos > ptr->final_pos)
			return (1);
	}
	return (-1);
}
