/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/24 19:27:12 by epolitze         ###   ########.fr       */
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
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
