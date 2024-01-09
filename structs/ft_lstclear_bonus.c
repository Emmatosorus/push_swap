/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:56:07 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/09 14:43:41 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*ptr;
	t_stack	*temp;

	if (lst && del)
	{
		ptr = *lst;
		while (ptr)
		{
			temp = ptr->next;
			del(ptr->content);
			free(ptr);
			ptr = temp;
		}
		*lst = NULL;
	}
	return ;
}
