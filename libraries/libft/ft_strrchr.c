/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 06:49:13 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 21:55:03 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strrchr
** Locates the last occurrence of 'c' in the string pointed to by 's'.
** The terminating null character is considered to be part of the string,
** therefore if 'c' is '\0', locates the terminating '\0'
** Return Value
** A pointer to the last occurrence of the character c in the string or
** NULL if the character is not found
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}
