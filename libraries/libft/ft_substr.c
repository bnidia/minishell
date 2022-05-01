/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:40:09 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/31 16:16:32 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_substr
** Allocates (with malloc(3)) and returns a substring from the string 's'.
** The substring begins at index 'start' and is of maximum size 'len'
** Return Value
** The substring. NULL if the allocation fails
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	size_t	s_len;
	size_t	str_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len < start || len <= 0)
		return ((char *)ft_calloc(1, 1));
	if (len < s_len - (size_t)start)
		str_len = len;
	else
		str_len = s_len - start;
	str = (char *)ft_calloc(sizeof(char), str_len + 1);
	while (len-- && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
