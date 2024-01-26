/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:02:36 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/25 14:44:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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