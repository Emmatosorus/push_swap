/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:58 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/15 19:29:10 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_struct(int nb, bool start)
{
	t_stack			*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = nb;
	list->final_pos = -1;
	list->start = start;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

int	ft_dup_check(int nb, t_stack **lst)
{
	t_stack	*ptr;

	if (*lst)
	{
		ptr = *lst;
		while (ptr)
		{
			if (ptr->content == nb)
				return (-1);
			ptr = ptr->next;
		}
	}
	return (0);
}

void	mark_pos(t_stack **lst, int max)
{
	int		size;
	t_stack	*ptr;
	t_stack	*temp;

	ptr = *lst;
	ptr = ptr->next;
	size = ft_lstsize(*lst);
	while (size-- > 0)
	{
		while (ptr->start == false)
		{
			if (ptr->final_pos < 0 && (ptr->content > max
					|| (ptr->content == max && max == INT_MIN)))
			{
				max = ptr->content;
				temp = ptr;
			}
			ptr = ptr->next;
		}
		temp->final_pos = size;
	}
}
