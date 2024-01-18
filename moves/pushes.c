/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:07:20 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/17 10:33:58 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		if (!*a)
		{
			temp = *b;
			rm_link(b);
			*a = temp;
		}
		else
		{
			temp = *b;
			rm_link(b);
			add_link(a, &temp);
		}
		ft_printf("pa\n");
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		if (!*b)
		{
			temp = *a;
			rm_link(a);
			*b = temp;
		}
		else
		{
			temp = *a;
			rm_link(a);
			add_link(b, &temp);
		}
		ft_printf("pb\n");
	}
}
