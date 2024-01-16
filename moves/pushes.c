/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:20 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/16 17:26:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a && b)
	{
		temp = *b;
		rm_link(b);
		add_link(a, &temp);
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a && b)
	{
		temp = *a;
		rm_link(a);
		add_link(b, &temp);
	}
}
