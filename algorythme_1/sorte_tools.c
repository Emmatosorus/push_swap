/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:56:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/22 15:34:42 by epolitze         ###   ########.fr       */
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

	max = 0;
	if (*stack)
	{
		ptr = *stack;
		max = ptr->final_pos;
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
