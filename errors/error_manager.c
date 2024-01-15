/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:37:28 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 15:07:29 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_stack **stack_a, char *str, char **strs)
{
	int	i;

	ft_printf("Error\n");
	if (str)
		free(str);
	if (strs)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs[i]);
		free(strs);
	}
	ft_lstclear(stack_a);
	str = NULL;
	stack_a = NULL;
	exit(EXIT_FAILURE);
}
