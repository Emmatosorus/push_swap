/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:08:43 by epolitze          #+#    #+#             */
/*   Updated: 2023/11/23 17:51:27 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	null_check(void *ptr, int wcount)
{
	int	temp;

	if (ptr)
	{
		temp = ft_putstr("0x");
		wcount = temp + ft_putaddress(ptr, wcount);
	}
	else
		wcount = ft_putstr("(nil)");
	return (wcount);
}

static int	argument_manager(char c, va_list *arg)
{
	int	wcount;

	wcount = 0;
	if (c == 'c')
		wcount = ft_putchar(va_arg(*arg, int));
	else if (c == 's')
		wcount = ft_putstr(va_arg(*arg, char *));
	else if (c == 'p')
		wcount = null_check(va_arg(*arg, void *), wcount);
	else if (c == 'd' || c == 'i')
		wcount = ft_putnbr(va_arg(*arg, int), wcount);
	else if (c == 'u')
		wcount = ft_putunbr(va_arg(*arg, unsigned int), wcount);
	else if (c == 'x' || c == 'X')
		wcount = ft_puthex(va_arg(*arg, unsigned int), c != 'X', wcount);
	else if (c == '%')
		wcount = ft_putchar('%');
	else
		wcount = -1;
	return (wcount);
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	int			wcount;
	int			temp;
	va_list		arg;

	i = -1;
	wcount = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	while (str && str[++i])
	{
		if (str[i] == '%')
			temp = argument_manager(str[++i], &arg);
		else
			temp = ft_putchar(str[i]);
		if (temp == -1)
		{
			va_end(arg);
			return (-1);
		}
		wcount += temp;
	}
	va_end(arg);
	return (wcount);
}
