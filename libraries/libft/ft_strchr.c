/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:46:25 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:30:07 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strchr
** Locates the first occurrence of 'c' in the string pointed to by 's'.
** The terminating null character is considered to be part of the string,
** therefore if 'c' is '\0', locates the terminating '\0'
** Return Value
** A pointer to the first occurrence of the character c in the string or
** NULL if the character is not found
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
		if (*s++ == ch)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
