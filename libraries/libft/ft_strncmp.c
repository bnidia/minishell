/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 06:57:24 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:31:58 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strncmp
** The strcmp() and strncmp() functions lexicographically compare the
** NUL-terminated strings s1 and s2. The strncmp() function compares
** at most len characters.
** Return Value
** Return an integer greater than, equal to, or less than 0, according
** to whether the string s1 is greater than, equal to, or less than
** the string s2. The comparison is done using unsigned characters,
** so that ‘\200’ is greater than ‘\0’.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (!len)
		return (0);
	while (len-- && (*s1 || *s2) && (*s1++ == *s2++))
		;
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
}
