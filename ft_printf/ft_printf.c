/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:01:18 by edolgun           #+#    #+#             */
/*   Updated: 2022/07/28 21:06:51 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_type(const char myCharacter, va_list *myList, int *lenght)
{
	if (myCharacter == 'c')
		write_character(va_arg(*myList, int), lenght);
	else if (myCharacter == 's')
		write_string(va_arg(*myList, char *), lenght);
	else if (myCharacter == 'p')
		write_pointer(va_arg(*myList, unsigned long), lenght);
	else if (myCharacter == 'd' || myCharacter == 'i')
		write_decimal(va_arg(*myList, int), lenght);
	else if (myCharacter == 'u')
		write_unsigned_integer(va_arg(*myList, int), lenght);
	else if (myCharacter == 'x')
		write_lower_hex(va_arg(*myList, unsigned long), lenght);
	else if (myCharacter == 'X')
		write_upper_hex(va_arg(*myList, unsigned long), lenght);
	else if (myCharacter == '%')
	{
		ft_putchar_fd('%', 1, lenght);
	}
}

int	ft_printf(const char *myString, ...)
{
	va_list	my_args;
	int		lenght ;

	va_start(my_args, myString);
	lenght = 0;
	while (*myString)
	{
		if (*myString == '%')
		{
			while (*(++myString) == ' ')
				;
			find_type(*myString, &my_args, &lenght);
		}
		else
			ft_putchar_fd(*myString, 1, &lenght);
		myString++;
	}
	va_end(my_args);
	return (lenght);
}
