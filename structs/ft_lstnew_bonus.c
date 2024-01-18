/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:15:31 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/17 12:55:04 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(void *content)
{
	t_stack			*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->nb = content;
	list->next = NULL;
	return (list);
}
