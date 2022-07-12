/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:14:32 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/14 20:22:45 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size n)
{
	t_size	current_byte;

	current_byte = 0;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (current_byte < n)
	{
		*((unsigned char *)dest + current_byte) = \
		*((const unsigned char *)src + current_byte);
		current_byte++;
	}
	return (dest);
}
