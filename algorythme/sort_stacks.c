/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:48:44 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/21 20:48:18 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	devide_stacks(t_stack **a, t_stack **b, int size)
{
	size = size / 2;
	while (size-- > 0)
		push_b(a, b);
}

void	unite_stacks(t_stack **a, t_stack **b, int size)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	int		max;

	ptr_a = *a;
	ptr_b = *b;
	while (ft_lstsize(*a) != size)
	{
		max = get_biggest(a);
		while (ptr_a->final_pos < ptr_b->final_pos && ptr_b->final_pos < max)
		{
			rotate_a(a, false);
			ptr_a = *a;
		}
		if (ptr_b->final_pos < max)
			push_a(a, b);
		else if (ptr_b->final_pos > max)
			b_has_max(a, b);
		ptr_a = *a;
		ptr_b = *b;
	}
	while (is_sorted(a) == -1)
		rotate_a(a, false);
}

void	rotate_tops(t_stack **a, t_stack **b)
{
	int	who;

	who = rotate_who(a, b);
	if (who == 1)
	{
		if (get_direction(a) == 1)
			rotate_a(a, false);
		else
			rev_rotate_a(a, false);
	}
	else if (who == 2)
	{
		if (get_direction(b) == 1)
			rotate_b(b, false);
		else
			rev_rotate_b(b, false);
	}
	else if (who == 3)
		rotate_anb(a, b);
}

void	sort_tops(t_stack **a, t_stack **b, int big_a, int big_b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = *a;
	ptr_b = *b;
	if (is_next_smaller(a) == 1 && is_next_smaller(b) == 1
		&& ptr_a->final_pos != big_a && ptr_b->final_pos != big_b)
	{
		swap_both(a, b);
	}
	else if (is_next_smaller(a) == 1 && ptr_a->final_pos != big_a)
		swap_a(a, false);
	else if (is_next_smaller(b) == 1 && ptr_b->final_pos != big_b)
		swap_b(b, false);
	rotate_tops(a, b);
}

void	stack_sorter(t_stack **a, t_stack **b)
{
	int		size;
	int		big_a;
	int		big_b;

	size = ft_lstsize(*a);
	devide_stacks(a, b, size);
	big_a = get_biggest(a);
	big_b = get_biggest(b);
	while (is_sorted(a) == -1 || is_sorted(b) == -1)
		sort_tops(a, b, big_a, big_b);
	unite_stacks(a, b, size);
}
