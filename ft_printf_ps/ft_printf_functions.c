/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:01:28 by epolitze          #+#    #+#             */
/*   Updated: 2023/11/23 17:50:37 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	temp;

	if (str)
		temp = write(1, str, ft_strlen(str));
	else
		temp = write(1, "(null)", 6);
	return (temp);
}

int	ft_putnbr(long long n, int wcount)
{
	int	temp;
	int	temp2;

	temp = 0;
	if (n < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		wcount = ft_putnbr(n / 10, wcount);
		temp2 = ft_putchar(n % 10 + '0');
		if (temp2 == -1)
			return (-1);
	}
	else
		temp2 = ft_putchar(n % 10 + '0');
	if (temp == -1 || temp2 == -1)
		return (-1);
	wcount += (temp + temp2);
	return (wcount);
}

int	ft_putunbr(unsigned long int n, int wcount)
{
	int	temp;

	if (n > 9)
	{
		wcount = ft_putnbr(n / 10, wcount);
		temp = ft_putchar(n % 10 + '0');
		if (temp == -1)
			return (-1);
	}
	else
		temp = ft_putchar(n % 10 + '0');
	if (temp == -1)
		return (-1);
	wcount += temp;
	return (wcount);
}
