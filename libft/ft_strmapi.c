/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:39:07 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:30:55 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_size			strlen;
	unsigned int	index;
	char			*str;

	index = 0;
	if (s == (char const *)0)
		return ((char *)0);
	strlen = ft_strlen(s);
	str = ft_calloc(strlen + 1, 1);
	if (str == (char *)0)
		return ((char *)0);
	while (index < strlen)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	return (str);
}
