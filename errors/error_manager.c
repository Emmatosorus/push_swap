/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:37:28 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/10 15:12:09 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	del(int nb)
{
	nb = 0;
}

void    error_exit(t_stack **stack_a)
{
    ft_printf("Error\n");
    ft_lstclear(stack_a, del);
    exit(EXIT_FAILURE);
}