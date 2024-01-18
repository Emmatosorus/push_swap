/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:59:25 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/18 17:33:44 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **a, t_stack **b, char c)
{
	int	ad;
	int	bd;

	ad = is_in_order(a);
	bd = is_in_order(b);
	if (c == 'k' && ad == bd && ad == -1)
		swap_both(a, b);
	else if (c == 'a' && ad == -1)
		swap_a(a, false);
	else if (c == 'b' && bd == -1)
		swap_b(b, false);
}
