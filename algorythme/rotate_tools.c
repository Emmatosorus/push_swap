/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:58:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/19 12:43:26 by epolitze         ###   ########.fr       */
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

int	rotate_who(t_stack **a, t_stack **b)
{
	if (is_sorted(a) == -1 && is_sorted(b) == -1)
		return (3);
	else if (is_sorted(a) == -1)
		return (1);
	else if (is_sorted(b) == -1)
		return (2);
	return (0);
}

void	rotate_anb(t_stack **a, t_stack **b)
{
	int	a_dir;
	int	b_dir;

	a_dir = get_direction(a);
	b_dir = get_direction(b);
	if (a_dir == 1 && b_dir == 1)
		rotate_both(a, b);
	else if (a_dir == -1 && b_dir == -1)
		rev_rotate_both(a, b);
	else if (a_dir == 1 && b_dir == -1)
	{
		rotate_a(a, false);
		rev_rotate_b(b, false);
	}
	else if (a_dir == -1 && b_dir == 1)
	{
		rotate_b(b, false);
		rev_rotate_a(a, false);
	}
}
