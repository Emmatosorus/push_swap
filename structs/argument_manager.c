/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:30:59 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/31 11:18:27 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	arg_check(char **args, int j, t_stack **stack_a)
{
	int		i;
	long	nb;
	char	*str;

	str = args[j];
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])
				|| (i == 0 && (str[i] == '-' || str[i] == '+')
					&& ft_isdigit(str[i + 1]))))
			error_exit(stack_a, args, j);
		i++;
	}
	nb = ft_atoi(str);
	if ((nb == 0 && (ft_strlen(str) != 1 && ft_is_zeros(str) != 1))
		|| ft_dup_check(nb, stack_a) == -1)
	{
		error_exit(stack_a, args, j);
	}
	return (nb);
}

static int	create_struct(int nb, t_stack **stack_a, bool start)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_struct(nb, start);
	if (!new)
		return (-1);
	else if (start == false)
	{
		last = ft_lstlast(*stack_a);
		new->prev = last;
		ft_lstadd_back(stack_a, new);
	}
	else
		*stack_a = new;
	return (1);
}

static void	make_list(int i, char **args, t_stack **stack_a)
{
	int		j;
	int		error;
	bool	start;

	j = -1;
	start = true;
	while (args[++j])
	{
		if (i > 1 || j > 0)
			start = false;
		error = create_struct(arg_check(args, j, stack_a), stack_a, start);
		if (error < 0)
			error_exit(stack_a, args, 0);
		free(args[j]);
	}
}

static void	link_back(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;

	first = *stack_a;
	last = ft_lstlast(*stack_a);
	first->prev = last;
	last->next = first;
}

void	arg_parse(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		stack_size;
	char	**args;

	i = 0;
	while (++i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args || !args[0])
			error_exit(stack_a, NULL, 0);
		make_list(i, args, stack_a);
		free(args);
	}
	link_back(stack_a);
	stack_size = ft_lstsize(*stack_a);
	mark_pos(stack_a, INT_MIN, stack_size, stack_size);
}
