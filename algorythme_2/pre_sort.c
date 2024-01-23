/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:03:43 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/23 12:59:49 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr->next != ptr->prev)
	{
		push_b(a, b);
		ptr = *a;
	}
}
