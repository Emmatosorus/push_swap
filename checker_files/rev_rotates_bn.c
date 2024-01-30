/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates_bn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:52 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 12:30:03 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotate_a(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->prev;
		ptr->start = true;
		*a = ptr;
	}
}

void	rev_rotate_b(t_stack **b)
{
	t_stack	*ptr;

	ptr = *b;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->prev;
		ptr->start = true;
		*b = ptr;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
}
