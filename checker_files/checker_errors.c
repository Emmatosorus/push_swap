/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:52:32 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 15:12:26 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_list(t_list **lst)
{
	t_list	*ptr;
	t_list	*temp;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->next != NULL)
		{
			temp = ptr->next;
			free(ptr->move);
			free(ptr);
			ptr = temp;
		}
		free(ptr->move);
		free(ptr);
		*lst = NULL;
	}
	return ;
}

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

void	checker_exit(t_stack **a, t_stack **b, t_list **mv_lst, char *str)
{
	write(2, "\x1b[31;1mError\n\x1b[0m", 17);
	ft_free_stack(a);
	ft_free_stack(b);
	ft_free_list(mv_lst);
	if (str)
		free(str);
	str = NULL;
	a = NULL;
	b = NULL;
	mv_lst = NULL;
	exit(EXIT_FAILURE);
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
