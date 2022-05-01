/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:34:49 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:27:38 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memcpy
** Copies n bytes from memory area src to memory of dst. The memory areas
** must not overlap. Use ft_memmove if the memory areas do overlap
** Return Value
** A pointer to the memory area dst
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
