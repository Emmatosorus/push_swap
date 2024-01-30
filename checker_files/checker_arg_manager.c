/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:38:09 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/30 15:12:02 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	add_struct(t_list **move_list, char *str, t_stack **a, t_stack **b)
{
	t_list	*ptr;
	t_list	*new;
	char	*move;

	new = NULL;
	ptr = NULL;
	if (*move_list != NULL)
		ptr = *move_list;
	new = NULL;
	if (ptr)
		while (ptr->next != NULL)
			ptr = ptr->next;
	new = (t_list *)malloc(sizeof(t_list));
	move = ft_strdup(str);
	if (!new || !move)
		checker_exit(a, b, move_list, str);
	new->move = move;
	new->next = NULL;
	if (*move_list == NULL)
		*move_list = new;
	else
		ptr->next = new;
}

static int	check_move(char *str)
{
	if (ft_strncmp(str, "sa\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "sb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "ss\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "pa\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "pb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "ra\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "rb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "rr\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		return (1);
	else
		return (-1);
}

void	get_moves(t_stack **a, t_stack **b, t_list **move_list)
{
	char	*str;

	str = "\0";
	while (str != NULL)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (check_move(str) == -1)
			checker_exit(a, b, move_list, str);
		else
			add_struct(move_list, str, a, b);
		free(str);
	}
}
