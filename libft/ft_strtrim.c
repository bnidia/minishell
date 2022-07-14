/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:50:01 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/13 19:00:01 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_allowed(char const *set, char const ch)
{
	int	counter;

	counter = 0;
	while (*(set + counter) != '\0')
		if (*(set + counter++) == ch)
			return (FALSE);
	return (TRUE);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin;
	unsigned int	end;
	char			*str;

	begin = 0;
	str = (char *)0;
	if (s1 == (char *)0)
		return ((char *)0);
	if (*s1 == '\0')
		return (ft_strdup(""));
	if (set == (char *)0 || *set == '\0')
		return (ft_strdup(s1));
	end = (unsigned int)ft_strlen(s1) - 1;
	while (*(s1 + begin) != '\0' && \
	!ft_set_allowed(set, (char const)*(s1 + begin)))
		begin++;
	while (end >= begin && !ft_set_allowed(set, (char const)*(s1 + end)))
		end--;
	if (begin != end)
		str = ft_substr(s1, begin, (t_size)(end - begin + 1));
	if (str != (char *)0)
		return (str);
	return ((char *)0);
}
