/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:26:48 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:28:09 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memmove
** Copies len bytes from the memory of src to dst. Memories may overlap.
** First, the bytes in src are copied into a temporary array and then to dst.
** Return Value
** A pointer to the memory area dst
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (src >= dst)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
