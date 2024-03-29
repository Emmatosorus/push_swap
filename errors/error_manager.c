/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:37:28 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 12:17:57 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*back;
	t_stack	*temp;

	if (*lst)
	{
		back = *lst;
		if (back->prev != NULL)
		{
			back = back->prev;
			back->next = NULL;
		}
		ptr = *lst;
		while (ptr->next != NULL)
		{
			temp = ptr->next;
			free(ptr);
			if (temp->start == false)
				ptr = temp;
		}
		free(ptr);
		*lst = NULL;
	}
	return ;
}

void	error_exit(t_stack **stack_a, char **strs, int i)
{
	write(2, "\x1b[31;1mError\n\x1b[0m", 17);
	if (strs)
	{
		while (strs[i])
		{
			if (strs[i])
				free(strs[i]);
			i++;
		}
		free(strs[i]);
		free(strs);
	}
	ft_free_stack(stack_a);
	stack_a = NULL;
	exit(EXIT_FAILURE);
}
