/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:58:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/22 16:10:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	next_not_smaller(t_stack **stack, int pos)
{
	t_stack	*next;
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->final_pos != pos)
		ptr = ptr->next;
	next = ptr->next;
	if (ptr->final_pos > next->final_pos)
		return (-1);
	return (1);
}

int	get_direction(t_stack **stack)
{
	int		bkwd;
	int		frwd;
	int		next;
	t_stack	*ptr;
	t_stack	*top;

	bkwd = 0;
	frwd = 0;
	top = *stack;
	ptr = top;
	while (next_not_smaller(stack, ptr->final_pos) == 1)
	{
		frwd++;
		ptr = ptr->next;
	}
	ptr = ptr->next;
	frwd++;
	next = ptr->final_pos;
	ptr = top;
	while (ptr->final_pos != next && bkwd++ <= frwd)
		ptr = ptr->prev;
	if (frwd <= bkwd)
		return (1);
	return (-1);
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
