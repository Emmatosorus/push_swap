/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:42 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/08 14:33:26 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(char *nb)
{
	
}

int	arg_manager(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (arg_ckeck(av[i]) == -1)
			return (-1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	error;

	if (ac <= 1)
		return (0);
	error = arg_manager(ac, av);
	if (error == -1)
	{
		ft_printf("Error\n");
	}
}
