/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:56:07 by epolitze          #+#    #+#             */
/*   Updated: 2023/11/15 11:07:17 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*temp;

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
