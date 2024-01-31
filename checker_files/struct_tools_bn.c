/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools_bn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:58 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/31 11:15:40 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (-1);
		i++;
	}
	return (1);
}

t_stack	*ft_struct(int nb, bool start)
{
	t_stack			*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->final_pos = -1;
	list->temp_pos = -1;
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
			if (ptr->nb == nb)
				return (-1);
			ptr = ptr->next;
		}
	}
	return (0);
}

void	mark_pos(t_stack **lst, int max, int rounds, int size)
{
	int		size_save;
	t_stack	*ptr;
	t_stack	*temp;

	ptr = *lst;
	size_save = size;
	while (size-- > 0)
	{
		rounds = size_save;
		ptr = ptr->next;
		while (rounds > 0)
		{
			if (ptr->final_pos == -1 && (ptr->nb > max
					|| (ptr->nb == max && max == INT_MIN)))
			{
				max = ptr->nb;
				temp = ptr;
			}
			ptr = ptr->next;
			rounds--;
		}
		temp->final_pos = size;
		max = INT_MIN;
	}
}
