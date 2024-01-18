/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:56 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/17 12:24:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **a, bool both)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->next;
		ptr->start = true;
		*a = ptr;
		if (both == false)
			ft_printf("ra\n");
	}
}

void	rotate_b(t_stack **b, bool both)
{
	t_stack	*ptr;

	ptr = *b;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->next;
		ptr->start = true;
		*b = ptr;
		if (both == false)
			ft_printf("rb\n");
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate_a(a, true);
	rotate_b(b, true);
	ft_printf("rr\n");
}
