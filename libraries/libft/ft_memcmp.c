/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 07:26:17 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:33:29 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memcmp
** The memcmp() function compares byte string b1 against byte string b2.
** Both strings are assumed to be len bytes long
** Return Value
** The memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that ‘\200’ is greater than ‘\0’,
** for example). Zero-length strings are always identical
*/

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*by1;
	unsigned char	*by2;

	by1 = (unsigned char *)b1;
	by2 = (unsigned char *)b2;
	if (!len)
		return (0);
	while (--len && *by1 == *by2)
	{
		by1++;
		by2++;
	}
	return ((int)(*by1 - *by2));
}
