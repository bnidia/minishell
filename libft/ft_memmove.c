/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:12:44 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/13 22:51:22 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dst_cpy == (void *)0 && src_cpy == (void *)0)
		return ((void *)0);
	if (src_cpy >= dst_cpy)
		while (n-- != 0)
			*dst_cpy++ = *src_cpy++;
	else
		while (n-- != 0)
			*(dst_cpy + n) = *(src_cpy + n);
	return (dest);
}
