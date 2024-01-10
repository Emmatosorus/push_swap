/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:47 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/10 17:33:24 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Remove this for the love of God
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	bool			start;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void	arg_manager(int ac, char **av, t_stack **stack_a);
t_stack	*ft_struct(int nb, bool start);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst, void (*del)(int));
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void    error_exit(t_stack **stack_a);

#endif