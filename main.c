/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/10 14:10:09 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(int nb)
{
	nb = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int size; // remove

	stack_a = NULL;
	size = 0; // remove
	if (ac <= 1)
		return (0);
	arg_manager(ac, av, &stack_a);
	size = ft_lstsize(stack_a); // remove
	printf("\nsize = %d\n", size); // remove
	ft_lstclear(&stack_a, del); // remove
}
