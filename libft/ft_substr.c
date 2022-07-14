/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:10:31 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:25:24 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	t_size	counter;
	char	*str;

	counter = 0;
	if (s == (char *)0)
		return ((char *)0);
	if (len > ft_strlen(s) - (t_size)start)
		len = ft_strlen(s) - (t_size)start;
	if ((t_size)start >= (t_size)ft_strlen(s))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, 1);
	if (!str)
		return ((char *)0);
	while (s[counter] != '\0' && counter < len)
	{
		str[counter] = s[counter + (t_size)start];
		counter++;
	}
	return (str);
}
