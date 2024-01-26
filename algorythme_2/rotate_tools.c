/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:02:36 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/26 03:56:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rv_helper(t_stack **a, t_stack **b, int reps_a, int reps_b)
{
	while (reps_a < 0 && reps_b < 0)
	{
		rev_rotate_both(a, b);
		reps_a++;
		reps_b++;
	}
	while (reps_a++ < 0)
		rev_rotate_a(a, false);
	while (reps_b++ < 0)
		rev_rotate_b(b, false);
}

void	ro_helper(t_stack **a, t_stack **b, int reps_a, int reps_b)
{
	while (reps_a > 0 && reps_b > 0)
	{
		rotate_both(a, b);
		reps_a--;
		reps_b--;
	}
	while (reps_a-- > 0)
		rotate_a(a, false);
	while (reps_b-- > 0)
		rotate_b(b, false);
}

void	move_both(int pos, t_stack **a, t_stack **b)
{
	int	reps_a;
	int	reps_b;

	reps_a = get_a_len(a, pos);
	reps_b = get_b_len(*b, pos);
	if (reps_a < 0)
		rv_helper(a, b, reps_a, reps_b);
	else
		ro_helper(a, b, reps_a, reps_b);
}
