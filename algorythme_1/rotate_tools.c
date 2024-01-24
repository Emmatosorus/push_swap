/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:26:08 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/24 19:23:25 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
