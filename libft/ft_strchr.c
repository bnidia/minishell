/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:38:21 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 18:55:19 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s++)
		if (*((char *)s - 1) == (char)c)
			return ((char *)s - 1);
	if ((char)c == '\0')
		return ((char *)s - 1);
	return ((char *)0);
}
