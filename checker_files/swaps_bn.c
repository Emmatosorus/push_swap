/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:06:54 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 14:23:37 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stack **a)
{
	t_stack	*two;
	t_stack	*one;
	t_stack	*temp;

	two = *a;
	if (two != NULL && two->next != NULL && two->prev != NULL)
	{
		one = two->next;
		two->start = false;
		one->start = true;
		temp = one->next;
		one->next = two;
		two->next = temp;
		temp->prev = two;
		temp = two->prev;
		two->prev = one;
		one->prev = temp;
		temp->next = one;
		*a = one;
	}
}

void	swap_b(t_stack **b)
{
	t_stack	*two;
	t_stack	*one;
	t_stack	*temp;

	two = *b;
	if (two != NULL && two->next != NULL && two->prev != NULL)
	{
		one = two->next;
		two->start = false;
		one->start = true;
		temp = one->next;
		one->next = two;
		two->next = temp;
		temp->prev = two;
		temp = two->prev;
		two->prev = one;
		one->prev = temp;
		temp->next = one;
		*b = one;
	}
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}
