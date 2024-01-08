/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:24:47 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/08 13:31:18 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Remove this for the love of God
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				*content;
	int				start;
	struct s_list	*next;
}					t_list;

#endif