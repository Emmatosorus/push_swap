/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:15:20 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/24 19:26:22 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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
	t_stack	*ptr;

	ptr = *b;
	if (ptr->next != NULL)
	{
		final_pos = get_low_cost(a, b);
		move_to_top(final_pos, b);
	}
	else
		final_pos = ptr->final_pos;
	move_to_pos(final_pos, a);
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
