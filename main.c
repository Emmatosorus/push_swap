/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/08 15:28:31 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_manager(int ac, char **av)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	args = NULL;
	while (i < ac)
	{
		j = 0;
		args = ft_split(av[i], ' ');
		if (!args)
			exit(EXIT_FAILURE); // Free structs
		while (args[j])
		{
			ft_printf("%s\n", args[j]);
			free(args[j]);
			j++;
		}
		free(args);

		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	arg_manager(ac, av);
}
