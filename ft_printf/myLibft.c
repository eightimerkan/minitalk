/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myLibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:54:28 by edolgun           #+#    #+#             */
/*   Updated: 2022/11/13 12:21:40 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len * sizeof(char));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_digitnum(int n)
{
	int	count;

	count = !n;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	sign = n < 0;
	len = ft_digitnum(n) + sign;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (sign)
	{
		result[0] = '-';
		result[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		result[len] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
