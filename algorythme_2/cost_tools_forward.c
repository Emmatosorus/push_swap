/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tools_forward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:43:29 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/23 17:50:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_smallest(t_stack *ptr, int pos)
{
	int		min;

	if (pos == 0)
		return (1);
	min = INT_MAX;
	if (ptr->final_pos < min)
		min = ptr->final_pos;
	ptr = ptr->next;
	while(ptr->start == false)
	{
		if (ptr->final_pos < min)
			min = ptr->final_pos;
		ptr = ptr->next;
	}
	if (pos < min)
		return (1);
	return (-1);
}

static int	is_biggest(t_stack *ptr, int pos)
{
	int	max;

	max = 0;
	if (ptr->final_pos > max)
		max = ptr->final_pos;
	ptr = ptr->next;
	while (ptr->start == false)
	{
		if (ptr->final_pos > max)
			max = ptr->final_pos;
		ptr = ptr->next;
	}
	if (pos > max)
		return (1);
	return (-1);
}

static int	xtrem_case(t_stack *ptr)
{
	t_stack	*prev;
	int		len;

	len = 0;
	prev = ptr->prev;
	while (prev->final_pos < ptr->final_pos)
	{
		prev = ptr;
		ptr = ptr->next;
		len++;
	}
	return (len);
}

int	get_forward_len(t_stack **a, int pos)
{
	t_stack	*ptr;
	t_stack *next;
	t_stack *prev;
	int		len;

	ptr = *a;
	len = 0;
	prev = ptr->prev;
	next = ptr->next;
	if (is_smallest(*a, pos) == 1 || is_biggest(*a, pos) == 1)
		return (xtrem_case(ptr));
	while (!(ptr->final_pos > pos && prev->final_pos < pos))
	{
		len++;
		prev = ptr;
		ptr = next;
		//ft_printf("What does the fox say?\n");
		next = next->next;
	}
	return (len);
}
