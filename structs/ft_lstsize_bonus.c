/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:56 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 17:50:36 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	i = 1;
	ptr = lst;
	ptr = ptr->next;
	if (!lst)
		return (0);
	while (ptr->start == false)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
