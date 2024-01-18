/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/18 17:33:57 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *lst)
{
	t_stack	*ptr;
	t_stack	*prev;
	int		i;

	ptr = lst;
	i = 0;
	if (!lst)
		return ;
	while ((ptr->start == false || (i == 0 && ptr->start == true)))
	{
		i++;
		ft_printf("\nnb = %d -> %d\n", ptr->nb, ptr->final_pos);
		ft_printf("start = %d\n", ptr->start);
		ft_printf("pos = %d\n", ptr->final_pos);
		if (ptr->next == NULL)
			return ;
		prev = ptr->prev;
		ft_printf("previous = %d\n", prev->nb);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	arg_parse(ac, av, &stack_a);
	// ft_printf("\n%s\n", "\033[4;1mStack a:\033[0m");
	// print_stack(stack_a);
	// ft_printf("\n%s\n", "\033[4;1m\nStack b:\033[0m");
	// print_stack(stack_b);

	//ft_printf("\n%s\n", "\033[7;1;32mMoves :\033[0m");

	stack_sorter(&stack_a, &stack_b);

	// ft_printf("\n");
	// ft_printf("\n%s\n", "\033[4;1mStack a:\033[0m");
	// print_stack(stack_a);
	// ft_printf("\n%s\n", "\033[4;1m\nStack b:\033[0m");
	// print_stack(stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
