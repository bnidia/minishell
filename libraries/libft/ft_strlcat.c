/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 01:45:32 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 01:51:23 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strlcat
** Concatenate the string src to the end of dst. It will concatenate at
** most size - strlen(dst) - 1 bytes, NUL-terminating the result
** Also note that strlcpy() and strlcat() only operate on true “C” strings.
** This means that for strlcpy() src must be NUL-terminated and for strlcat()
** both src and dst must be NUL-terminated.
** Return Value
** The initial length of dst plus the length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + len < dstsize - 1 && src[i] != 0)
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + len);
}
