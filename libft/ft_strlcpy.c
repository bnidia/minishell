/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:22:51 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/14 20:21:26 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcpy(char *dest, const char *src, t_size n)
{
	char	*dst_cpy;
	char	*src_cpy;
	t_size	counter;

	counter = 0;
	dst_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (n == 0)
		return (ft_strlen(src));
	while (*(src_cpy + counter) != '\0' && counter < n - 1)
	{
		*(dst_cpy + counter) = *(src_cpy + counter);
		counter++;
	}
	*(dst_cpy + counter) = '\0';
	return (ft_strlen(src));
}
