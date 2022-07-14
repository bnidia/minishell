/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:27:19 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/13 18:56:53 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s2, const char *s1, t_size n)
{
	t_size	counter;
	t_size	i;

	counter = 0;
	if (*s1 == '\0')
		return ((char *)s2);
	while (*(s2 + counter) != '\0' && counter < n)
	{
		i = 0;
		while (*(s2 + counter + i) == \
		*(s1 + i) && counter + i < n && *(s1 + i) != '\0')
			if (*(s1 + ++i) == '\0')
				return ((char *)s2 + counter);
		counter++;
	}
	return ((char *)0);
}
