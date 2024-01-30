/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:23:32 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 12:38:41 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	choose_move(char *str, t_stack **a, t_stack **b)
{
	if (ft_strncmp(str, "sa\n", 5) == 0)
		swap_a(a);
	else if (ft_strncmp(str, "sb\n", 5) == 0)
		swap_b(b);
	else if (ft_strncmp(str, "ss\n", 5) == 0)
		swap_both(a, b);
	else if (ft_strncmp(str, "pa\n", 5) == 0)
		push_a(a, b);
	else if (ft_strncmp(str, "pb\n", 5) == 0)
		push_b(a, b);
	else if (ft_strncmp(str, "ra\n", 5) == 0)
		rotate_a(a);
	else if (ft_strncmp(str, "rb\n", 5) == 0)
		rotate_b(b);
	else if (ft_strncmp(str, "rr\n", 5) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		rev_rotate_a(a);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		rev_rotate_b(b);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		rev_rotate_both(a, b);
}

void	make_moves(t_list **move_list, t_stack **a, t_stack **b)
{
	t_list	*ptr;

	ptr = *move_list;
	while (ptr != NULL)
	{
		choose_move(ptr->move, a, b);
		ptr = ptr->next;
	}
}

void	check_sort(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	*next;

	if (*b != NULL)
	{
		ft_printf("\x1b[31;1mKO\n\x1b[0m");
		return ;
	}
	ptr = *a;
	next = ptr->next;
	while (next->start == false)
	{
		if (ptr->final_pos > next->final_pos)
		{
			ft_printf("\x1b[31;6;1mKO\n\x1b[0m");
			return ;
		}
		ptr = next;
		next = next->next;
	}
	ft_printf("\x1b[32;1mOK\n\x1b[0m");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*move_list;

	stack_a = NULL;
	stack_b = NULL;
	move_list = NULL;
	if (ac <= 1)
		exit(EXIT_FAILURE);
	arg_parse(ac, av, &stack_a);
	get_moves(&stack_a, &stack_b, &move_list);
	make_moves(&move_list, &stack_a, &stack_b);
	check_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	ft_free_list(&move_list);
}
