/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:52 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/17 12:26:22 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_stack **a, bool both)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->prev;
		ptr->start = true;
		*a = ptr;
		if (both == false)
			ft_printf("rra\n");
	}
}

void	rev_rotate_b(t_stack **b, bool both)
{
	t_stack	*ptr;

	ptr = *b;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->prev;
		ptr->start = true;
		*b = ptr;
		if (both == false)
			ft_printf("rrb\n");
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b)
{
	rev_rotate_a(a, true);
	rev_rotate_b(b, true);
	ft_printf("rrr\n");
}
