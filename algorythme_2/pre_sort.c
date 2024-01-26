/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:03:43 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/26 03:11:25 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_temp_pos(t_stack **a)
{
	t_stack *ptr;

	ptr = *a;
	ptr->temp_pos = -1;
	ptr = ptr->next;
	while (ptr->start == false)
	{
		ptr->temp_pos = -1;
		ptr = ptr->next;
	}
}

void	mark_temp_pos(t_stack **lst, int max, int rounds, int size)
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
			if (ptr->temp_pos == -1 && (ptr->nb > max
					|| (ptr->nb == max && max == INT_MIN)))
			{
				max = ptr->nb;
				temp = ptr;
			}
			ptr = ptr->next;
			rounds--;
		}
		temp->temp_pos = size;
		max = INT_MIN;
	}
}

int		not_all_medium(t_stack **a, int big_range, int small_range)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->temp_pos <= big_range && ptr->temp_pos >= small_range)
			return (1);
	ptr = ptr->next;
	while (ptr->start != false)
	{
		if (ptr->temp_pos <= big_range && ptr->temp_pos >= small_range)
			return (1);
		ptr = ptr->next;
	}
	return (-1);
}

void	move_it_move_it(t_stack **a, t_stack **b, int size)
{
	t_stack *ptr;
	int 	small_range;
	int 	big_range;
	int 	j;

	ptr = *a;
	small_range = (size / 3);
	big_range = size - (size / 3);
	if (ptr->temp_pos > big_range || ptr->temp_pos < small_range)
	{
		push_b(a, b);
		if (ptr->temp_pos >= big_range)
			rotate_b(b, false);
	}
	j = 0;
	ptr = *a;
	while (ptr->temp_pos <= big_range && ptr->temp_pos >= small_range
		   && not_all_medium(a, big_range, small_range) == 1
		   && (big_range - small_range) > 4)
	{
		rotate_a(a, false);
		ptr = *a;
	}
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int 	size;

	ptr = *a;
	size = ft_lstsize(ptr) + 1;
	while (ptr->next != ptr->prev)
	{
		del_temp_pos(a);
		mark_temp_pos(a, INT_MIN, size, size);
		move_it_move_it(a, b, size);
		size--;
		ptr = *a;
	}
}
