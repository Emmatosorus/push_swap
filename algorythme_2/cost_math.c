/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:37 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/23 15:30:32 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_b_len(t_stack *ptr, int pos)
{
	t_stack *top;
	int	ro_len;
	int	rv_len;

	top = ptr;
	ro_len = 0;
	rv_len = 0;
	while (ptr->final_pos != pos)
	{
		ro_len++;
		ptr = ptr->next;
	}
	ptr = top;
	while (ptr->final_pos != pos)
	{
		rv_len--;
		ptr = ptr->prev;
	}
	if (ro_len < (rv_len * -1))
		return (ro_len);
	return (rv_len);
}

int	get_a_len(t_stack **a, int pos)
{
	t_stack	*ptr;
	int		ro_len;
	int		rv_len;

	ptr = *a;
	ro_len = get_forward_len(a, pos);
	rv_len = get_bckward_len(a, pos);
	if (ro_len < (rv_len * -1))
		return (ro_len);
	return (rv_len);
}

int	get_cost(t_stack **a, t_stack **b, int pos)
{
	int	b_rotates;
	int	a_rotates;

	b_rotates = get_b_len(*b, pos);
	a_rotates = get_a_len(a, pos);
	if (b_rotates < 0)
		b_rotates *= -1;
	if (a_rotates < 0)
		a_rotates *= -1;
	return (b_rotates + a_rotates + 1);
}

int	get_low_cost(t_stack **a, t_stack **b)
{
	t_stack *ptr;
	t_stack	*result;
	int		min_cost;
	int		temp;

	ptr = *b;
	min_cost = get_cost(a, b, ptr->final_pos);
	result = ptr;
	ptr = ptr->next;
	while (ptr->start == false)
	{
		temp = get_cost(a, b, ptr->final_pos);
		if (temp < min_cost)
		{
			min_cost = temp;
			result = ptr;
		}
		ptr = ptr->next;
	}
	return (result->final_pos);
}
