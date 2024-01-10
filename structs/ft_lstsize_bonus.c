/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:56 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/10 14:01:29 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*ptr;
	t_stack	*prev;

	i = 0;
	ptr = lst;
	if (!lst)
		return (0);
	while (ptr->next != NULL)
	{
		i++;
		ft_printf("\nnb = %d\n", ptr->content); // remove
		ft_printf("start = %d\n", ptr->start); // remove
		prev = ptr->prev;
		ft_printf("previous = %d\n", prev->content); // remove
		ptr = ptr->next;
	}
	ft_printf("\nnb = %d\n", ptr->content); // remove
	ft_printf("start = %d\n", ptr->start); // remove
	prev = ptr->prev;
	ft_printf("previous = %d\n", prev->content); // remove
	return (i + 1);
}
