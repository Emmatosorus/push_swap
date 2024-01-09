/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:56 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/09 16:29:14 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = lst;
	if (!lst)
		return (0);
	while (ptr->next != NULL)
	{
		i++;
		//ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	return (i + 1);
}
