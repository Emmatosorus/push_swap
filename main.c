/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 15:39:00 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		size;

	stack_a = NULL;
	size = 0;
	if (ac <= 1)
		return (0);
	arg_manager(ac, av, &stack_a);
	size = ft_lstsize(stack_a);
	printf("\nsize = %d\n", size);
	ft_lstclear(&stack_a);
}
