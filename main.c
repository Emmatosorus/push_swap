/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/29 18:14:43 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	arg_parse(ac, av, &stack_a);
	if (is_in_order(&stack_a) == 1)
		while (is_sorted(&stack_a) == -1)
			final_rotate(&stack_a);
	else if (is_sorted(&stack_a) == -1)
	{
		if (ft_lstsize(stack_a) < 6)
			small_stack_sorter(&stack_a, &stack_b);
		else
			big_stack_sorter(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
