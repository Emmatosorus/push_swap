/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:30:59 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/09 17:44:42 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arg_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_printf("Invalid input\n"); // exit(EXIT_FAILURE); // Call error function
		i++;
	}
}

void    create_struct(int nb, t_stack ***stack_a, bool start)
{
    t_stack *new;

    new = ft_struct(nb, start);
	//ft_printf("Stage 3 Completed!\n");
	if (start == false)
    	ft_lstadd_back(*stack_a, new);
	else
		**stack_a = new;
	//ft_printf("Stage 4 Completed!\n");
}

void	arg_manager(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		j;
    bool    start;
	char	**args;

	i = 1;
    start = true;
	while (i < ac)
	{
        if (i > 1)
            start = false;
		args = ft_split(av[i], ' ');
		if (!args)
			exit(EXIT_FAILURE); // Call error function
		j = 0;
		//ft_printf("Stage 1 Completed!\n");
		while (args[j])
		{
			arg_check(args[j]);
			//ft_printf("Stage 2 Completed!\n");
            create_struct(ft_atoi(args[j]), &stack_a, start);
			//ft_printf("Stage 5 Completed!\n");
			free(args[j]);
			j++;
		}
		free(args);
		i++;
	}
}
