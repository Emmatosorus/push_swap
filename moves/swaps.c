/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:06:54 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/17 12:23:41 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **a, bool both)
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
	if (both == false)
		ft_printf("sa\n");
}

void	swap_b(t_stack **b, bool both)
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
	if (both == false)
		ft_printf("sb\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap_a(a, true);
	swap_b(b, true);
	ft_printf("ss\n");
}
