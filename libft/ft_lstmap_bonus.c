/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:14:12 by epolitze          #+#    #+#             */
/*   Updated: 2023/11/15 14:07:51 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*c;
	t_list	*nwlst;
	t_list	*temp;

	nwlst = NULL;
	while (lst && f && del)
	{
		c = f(lst->content);
		if (!c)
		{
			ft_lstclear(&nwlst, del);
			return (NULL);
		}
		temp = ft_lstnew(c);
		if (!temp)
		{
			(*del)(c);
			ft_lstclear(&nwlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nwlst, temp);
		lst = lst->next;
	}
	return (nwlst);
}
