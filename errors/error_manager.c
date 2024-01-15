/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:37:28 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 18:48:53 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (*lst)
	{
		ptr = *lst;
		while (ptr)
		{
			temp = ptr->next;
			free(ptr);
			ptr = temp;
		}
		*lst = NULL;
	}
	return ;
}

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
	ft_free_list(stack_a);
	str = NULL;
	stack_a = NULL;
	exit(EXIT_FAILURE);
}
