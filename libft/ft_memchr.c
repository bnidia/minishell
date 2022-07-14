/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:40:36 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 18:54:20 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	t_size			i;
	unsigned char	*address;

	i = 0;
	address = (unsigned char *)s;
	while (i < n)
	{
		if (*(address + i) == (unsigned char)c)
			return (address + i);
		i++;
	}
	return ((void *)0);
}
