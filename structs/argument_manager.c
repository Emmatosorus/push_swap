/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:30:59 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/10 17:42:38 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arg_check(char *str, t_stack **stack_a)
{
	int	i;
	long nb;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			error_exit(stack_a);
		i++;
	}
	nb = ft_atoi(str);
	if (nb == 0 && ft_strlen(str) != 1)
		error_exit(stack_a);
	return (nb);
}

void    create_struct(int nb, t_stack ***stack_a, bool start)
{
    t_stack *new;
	t_stack *last;

    new = ft_struct(nb, start);
	if (start == false)
	{
		last = ft_lstlast(**stack_a);
		new->prev = last;
    	ft_lstadd_back(*stack_a, new);
	}
	else
		**stack_a = new;
}

void	link_back(t_stack ***stack_a)
{
	t_stack *last;
	t_stack *first;

	first = **stack_a;
	last = ft_lstlast(**stack_a);
	first->prev = last;
	
}

void	arg_manager(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		j;
    bool    start;
	char	**args;

	i = 0;
    start = true;
	while (++i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			error_exit(stack_a);
		j = 0;
		while (args[j])
		{
			if (i > 1 || j > 0)
            	start = false;
            create_struct(arg_check(args[j], stack_a), &stack_a, start);
			free(args[j]);
			j++;
		}
		free(args);
	}
	link_back(&stack_a);
}
