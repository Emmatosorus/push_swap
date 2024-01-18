/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:48:44 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/18 17:29:52 by epolitze         ###   ########.fr       */
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

void	sort_tops_a(t_stack **a, int bigger)
{
	t_stack	*ptr;

	ptr = *a;
	if (is_next_smaller(a) == 1 && ptr->final_pos != bigger)
		swap_a(a, false);
	if (is_sorted(a) == -1)
	{
		if (get_direction(a) == 1)
			rotate_a(a, false);
		else
			rev_rotate_a(a, false);
	}
}

void	sort_tops_b(t_stack **b, int bigger)
{
	t_stack	*ptr;

	ptr = *b;
	if (is_next_smaller(b) == 1 && ptr->final_pos != bigger)
		swap_b(b, false);
	if (is_sorted(b) == -1)
	{
		if (get_direction(b) == 1)
			rotate_b(b, false);
		else
			rev_rotate_b(b, false);
	}
}

void	stack_sorter(t_stack **a, t_stack **b)
{
	int		i;
	int		size;
	int		bigger;

	i = 0;
	size = ft_lstsize(*a);
	devide_stacks(a, b, size);
	bigger = get_biggest(a);
	while (is_sorted(a) == -1)
		sort_tops_a(a, bigger);
	bigger = get_biggest(b);
	while (is_sorted(b) == -1)
		sort_tops_b(b, bigger);
	unite_stacks(a, b, size);
}
