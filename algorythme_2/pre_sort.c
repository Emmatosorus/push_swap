/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:03:43 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/25 12:41:19 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int 	small_range;
	int 	big_range;

	ptr = *a;
	while (ptr->next != ptr->prev)
	{
		small_range = (ft_lstsize(*a) / 5) - 1;
		big_range = ft_lstsize(*a) - (ft_lstsize(*a) / 5) - 1;
		while (ptr->final_pos < big_range && ptr->final_pos > small_range)
		{
			rotate_a(a, false);
			ptr = *a;
		}
		if (ptr->final_pos >= big_range || ptr->final_pos <= small_range)
			push_b(a, b);
		if (ptr->final_pos >= big_range)
			rotate_b(b, false);
		ptr = *a;
	}
}
