/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:18:20 by edolgun           #+#    #+#             */
/*   Updated: 2022/11/13 12:22:51 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void	my_hex_converter(unsigned long myHexNumber, int *lenght);
void	my_hex_up_converter(unsigned long myHexNumber, int *lenght);
void	my_decimal_converter(unsigned int myDecimalNumber, int *lenght);
void	write_character(char myChar, int *lenght);
void	write_string(char *myString, int *lenght);
void	write_pointer(unsigned long myPointer, int *lenght);
void	write_decimal(int myDecimalNumber, int *lenght);
void	write_unsigned_integer(int myNumber, int *lenght);
void	write_upper_hex(unsigned int myPointer, int *lenght);
void	write_lower_hex(unsigned int myPointer, int *lenght);

void	ft_putstr_fd(char *s, int fd, int *lenght);
void	ft_putchar_fd(char c, int fd, int *lenght);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

void	find_type(const char myCharacter, va_list *myList, int *lenght);
int		ft_printf(const char *myString, ...);

#endif