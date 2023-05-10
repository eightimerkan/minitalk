/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:52:26 by edolgun           #+#    #+#             */
/*   Updated: 2022/11/13 12:24:18 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_hex_converter(unsigned long myHexNumber, int *lenght)
{
	char	*my_base;

	my_base = "0123456789abcdef";
	if (myHexNumber >= 16)
	{
		my_hex_converter(myHexNumber / 16, lenght);
		my_hex_converter(myHexNumber % 16, lenght);
	}
	else
		ft_putchar_fd(my_base[myHexNumber], 1, lenght);
}

void	my_hex_up_converter(unsigned long myHexNumber, int *lenght)
{
	char	*my_base;

	my_base = "0123456789ABCDEF";
	if (myHexNumber >= 16)
	{
		my_hex_up_converter(myHexNumber / 16, lenght);
		my_hex_up_converter(myHexNumber % 16, lenght);
	}
	else
		ft_putchar_fd(my_base[myHexNumber], 1, lenght);
}

void	my_decimal_converter(unsigned int myDecimalNumber, int *lenght)
{
	char	*my_base;

	my_base = "0123456789";
	if (myDecimalNumber >= 10)
	{
		my_decimal_converter(myDecimalNumber / 10, lenght);
		my_decimal_converter(myDecimalNumber % 10, lenght);
	}
	else
		ft_putchar_fd(my_base[myDecimalNumber], 1, lenght);
}

static int	ft_check_islong(const char *str, int i, int x)
{
	long	number;
	long	temp;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = number;
		number *= 10;
		number += str[i] - '0';
		if (temp > number)
		{
			if (x == -1)
				return (0);
			if (x == 1)
				return (-1);
		}
		i++;
	}
	return (number * x);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	return (ft_check_islong(str, i, x));
}
