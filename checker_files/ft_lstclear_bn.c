/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:56:07 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 14:22:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear(t_stack **lst)
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
