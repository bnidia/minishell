/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:18:49 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:29:30 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	t_size	counter;

	counter = 0;
	if (s1 == (char *)0 || s2 == (char *)0)
		return ((char *)0);
	p = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (p == (char *)0)
		return ((char *)0);
	while (*s1 != '\0')
		*(p + counter++) = *s1++;
	while (*s2 != '\0')
		*(p + counter++) = *s2++;
	*(p + counter) = '\0';
	return (p);
}
