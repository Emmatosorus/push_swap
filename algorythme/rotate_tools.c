/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:58:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/18 13:14:47 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both_dir(t_stack **a, t_stack **b, int dir)
{
	int	ad;
	int	bd;

	ad = is_in_order(a);
	bd = is_in_order(b);
	if (ad == -1 && bd == -1)
	{
		if (dir == 1)
			rotate_both(a, b);
		if (dir == -1)
			rev_rotate_both(a, b);
	}
}

void	rotate_a_dir(t_stack **a, int dir)
{
	if (is_in_order(a) == -1)
	{
		if (dir == 1)
			rotate_a(a, false);
		else if (dir == -1)
			rev_rotate_a(a, false);
	}
}

void	rotate_b_dir(t_stack **b, int dir)
{
	if (is_in_order(b) == -1)
	{
		if (dir == 1)
			rotate_b(b, false);
		else if (dir == -1)
			rev_rotate_b(b, false);
	}
}

void	rotate(t_stack **a, t_stack **b, char c)
{
	int	a_dir;
	int	b_dir;

	a_dir = get_direction(a);
	b_dir = get_direction(b);
	if (c == 'k' && a_dir == b_dir)
		rotate_both_dir(a, b, a_dir);
	if (c == 'k' && a_dir != b_dir)
	{
		rotate_a_dir(a, a_dir);
		rotate_b_dir(b, b_dir);
	}
	if (c == 'a')
		rotate_a_dir(a, a_dir);
	if (c == 'b')
		rotate_b_dir(b, b_dir);
}
