/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:27:37 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 18:56:39 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size	strlen;

	strlen = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + strlen);
	while ((char *)s + strlen >= s)
	{
		if (*((char *)s + strlen) == (char)c)
			return ((char *)s + strlen);
		strlen--;
	}
	return ((char *)0);
}
