/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:40:04 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:48:25 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strtrim
** Allocates (with malloc) and returns a copy of 's1' with the characters
** specified in 'set' removed from the beginning and the end of the string
** Return Value
** The trimmed string. NULL if the allocation fails
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	return (ft_substr(s1, 0, s1_len + 1));
}
