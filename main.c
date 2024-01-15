/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 18:49:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstprint(t_stack *lst)
{
	int		i;
	t_stack	*ptr;
	t_stack	*prev;

	i = 0;
	ptr = lst;
	if (!lst)
		return (0);
	while (ptr->start == false || (i == 0 && ptr->start == true))
	{
		i++;
		ft_printf("\nnb = %d\n", ptr->content);
		ft_printf("start = %d\n", ptr->start);
		ft_printf("pos = %d\n", ptr->final_pos);
		prev = ptr->prev;
		ft_printf("previous = %d\n", prev->content);
		ptr = ptr->next;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		size;

	stack_a = NULL;
	size = 0;
	if (ac <= 1)
		return (0);
	arg_manager(ac, av, &stack_a);
	size = ft_lstprint(stack_a);
	ft_printf("\nsize = %d\n", size);
	ft_lstclear(&stack_a);
}
