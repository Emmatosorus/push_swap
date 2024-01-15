/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:56:07 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 15:08:49 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack **lst)
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
