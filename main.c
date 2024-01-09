/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/09 17:41:21 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(int nb)
{
	nb = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int size;
	// t_stack	stack_b;

	stack_a = NULL;
	size = 0;
	if (ac <= 1)
		return (0);
	//ft_printf("Stage 0 Completed!\n");
	arg_manager(ac, av, &stack_a);
	//ft_printf("Stage 42 Completed!\n");
	size = ft_lstsize(stack_a);
	printf("%d\n", size);
	ft_lstclear(&stack_a, del);
}
