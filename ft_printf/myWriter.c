/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mywriter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:58:47 by edolgun           #+#    #+#             */
/*   Updated: 2022/07/28 21:01:41 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_character(char myChar, int *lenght)
{
	ft_putchar_fd(myChar, 1, lenght);
}

void	write_upper_hex(unsigned int myPointer, int *lenght)
{
	my_hex_up_converter(myPointer, lenght);
}

void	write_lower_hex(unsigned int myPointer, int *lenght)
{
	my_hex_converter(myPointer, lenght);
}

void	ft_putchar_fd(char c, int fd, int *lenght)
{
	write(fd, &c, 1);
	(*lenght)++;
}

void	ft_putstr_fd(char *s, int fd, int *lenght)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, lenght);
		i++;
	}
}
