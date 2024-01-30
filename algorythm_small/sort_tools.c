/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:32:34 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 15:06:47 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_smallest(t_stack **stack)
{
	int		min;
	t_stack	*ptr;

	ptr = *stack;
	min = ptr->final_pos;
	ptr = ptr->next;
	while (ptr->start == false)
	{
		if (ptr->final_pos < min)
			min = ptr->final_pos;
		ptr = ptr->next;
	}
	return (min);
}

int	get_biggest(t_stack **stack)
{
	int		max;
	t_stack	*ptr;

	ptr = *stack;
	max = ptr->final_pos;
	if (ptr->next != NULL)
	{
		ptr = ptr->next;
		while (ptr->start == false)
		{
			if (ptr->final_pos > max)
				max = ptr->final_pos;
			ptr = ptr->next;
		}
	}
	return (max);
}

static int	next_not_small(t_stack **stack, int pos)
{
	t_stack	*next;
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->final_pos != pos)
		ptr = ptr->next;
	next = ptr->next;
	if (ptr->final_pos > next->final_pos)
		return (-1);
	return (1);
}

int	get_direction(t_stack **stack)
{
	int		bkwd;
	int		frwd;
	int		next;
	t_stack	*ptr;
	t_stack	*top;

	bkwd = 0;
	frwd = 0;
	top = *stack;
	ptr = top;
	while (next_not_small(stack, ptr->final_pos) == 1)
	{
		frwd++;
		ptr = ptr->next;
	}
	ptr = ptr->next;
	next = ptr->final_pos;
	ptr = top;
	while (ptr->final_pos != next && bkwd++ <= frwd)
		ptr = ptr->prev;
	if (frwd <= bkwd)
		return (1);
	return (-1);
}

void	b_has_max(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr->final_pos != 0)
	{
		rotate_a(a, false);
		ptr = *a;
	}
	push_a(a, b);
}
