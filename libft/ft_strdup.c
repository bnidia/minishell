/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:03:05 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 13:25:31 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	t_size	strlen;
	t_size	counter;
	char	*dup;

	counter = 0;
	strlen = ft_strlen(s);
	dup = ft_calloc(strlen + 1, 1);
	if (dup == NULL)
		return (NULL);
	while (*s != '\0')
		*(dup + counter++) = *s++;
	return (dup);
}
