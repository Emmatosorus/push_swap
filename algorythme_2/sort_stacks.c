/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:15:20 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/26 03:57:38 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_rotate(t_stack **a)
{
	int	dir;

	dir = get_direction(a);
	if (dir == 1)
		rotate_a(a, false);
	else
		rev_rotate_a(a, false);
}

void	move_to_top(int pos, t_stack **b)
{
	int		reps;

	reps = get_b_len(*b, pos);
	if (reps < 0)
		while (reps++ < 0)
			rev_rotate_b(b, false);
	else
		while (reps-- > 0)
			rotate_b(b, false);
}

void	move_to_pos(int pos, t_stack **a)
{
	int	reps;

	reps = get_a_len(a, pos);
	if (reps < 0)
		while (reps++ < 0)
			rev_rotate_a(a, false);
	else
		while (reps-- > 0)
			rotate_a(a, false);
}

void	move_back(t_stack **a, t_stack **b)
{
	int		final_pos;
	int		reps_a;
	int		reps_b;
	t_stack	*ptr;

	ptr = *b;
	if (ptr->next != NULL)
		final_pos = get_low_cost(a, b);
	else
		final_pos = ptr->final_pos;
	reps_a = get_a_len(a, final_pos);
	reps_b = get_b_len(*b, final_pos);
	if ((reps_a > 0 && reps_b > 0) || (reps_a < 0 && reps_b < 0))
		move_both(final_pos, a, b);
	else
	{
		move_to_top(final_pos, b);
		move_to_pos(final_pos, a);
	}
	push_a(a, b);
}

void	big_stack_sorter(t_stack **a, t_stack **b)
{
	move_to_b(a, b);
	while (*b != NULL)
		move_back(a, b);
	while (is_sorted(a) == -1)
		final_rotate(a);
}
