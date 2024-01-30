/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_tools_bckward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:07:02 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 14:58:06 by epolitze         ###   ########.fr       */
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
	while (ptr->start == false)
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
		ptr = prev;
		prev = prev->prev;
		len--;
	}
	return (len);
}

int	get_bckward_len(t_stack **a, int pos)
{
	t_stack	*ptr;
	t_stack	*prev;
	int		len;

	ptr = *a;
	len = 0;
	prev = ptr->prev;
	if (is_smallest(*a, pos) == 1 || is_biggest(*a, pos) == 1)
		return (xtrem_case(ptr));
	while (!(ptr->final_pos > pos && prev->final_pos < pos))
	{
		len--;
		ptr = prev;
		prev = prev->prev;
	}
	return (len);
}
