/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPrinter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:01:22 by edolgun           #+#    #+#             */
/*   Updated: 2022/07/28 21:10:42 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_string(char *myString, int *lenght)
{
	if (!myString)
	{
		write(1, "(null)", 6);
		(*lenght) += 6;
		return ;
	}
	ft_putstr_fd(myString, 1, lenght);
}

void	write_pointer(unsigned long myPointer, int *lenght)
{
	write(1, "0x", 2);
	(*lenght) += 2;
	my_hex_converter(myPointer, lenght);
}

void	write_decimal(int my_decimal_number, int *lenght)
{
	char	*my_decimal_number_string;

	my_decimal_number_string = ft_itoa(my_decimal_number);
	ft_putstr_fd(my_decimal_number_string, 1, lenght);
	free(my_decimal_number_string);
}

void	write_unsigned_integer(int myNumber, int *lenght)
{
	my_decimal_converter(myNumber, lenght);
}
