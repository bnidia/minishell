/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:00:27 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:27:30 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_size	ft_getsize(t_size n)
{
	t_size	size;

	size = 1;
	while (n / 0x0a != 0)
	{
		size++;
		n /= 0x0a;
	}
	return (size);
}

static char	*ft_allocstr(t_size *size, int negative)
{
	char	*str;

	if (negative)
		str = ft_calloc(++(*size) + 1, 1);
	else
		str = ft_calloc(*size + 1, 1);
	if (str == (char *)0)
		return ((char *)0);
	str[*size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	t_size	un;
	t_size	size;

	negative = FALSE;
	un = n;
	if (n < 0)
	{
		negative = TRUE;
		un = (long long int)n * -1;
	}
	size = ft_getsize(un);
	str = ft_allocstr(&size, negative);
	if (str == (char *)0)
		return ((char *)0);
	while (size != 0)
	{
		str[--size] = 0x30 + (un % 0x0a);
		un /= 0x0a;
	}
	if (negative)
		str[size] = '-';
	return (str);
}
