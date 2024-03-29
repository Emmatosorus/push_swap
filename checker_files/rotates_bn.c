/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_bn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:56 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 14:23:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->next;
		ptr->start = true;
		*a = ptr;
	}
}

void	rotate_b(t_stack **b)
{
	t_stack	*ptr;

	ptr = *b;
	if (ptr != NULL && ptr->next != NULL && ptr->prev != NULL)
	{
		ptr->start = false;
		ptr = ptr->next;
		ptr->start = true;
		*b = ptr;
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate_a(a);
	rotate_b(b);
}
