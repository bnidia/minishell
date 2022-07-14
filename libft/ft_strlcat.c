/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:24:26 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 12:21:27 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcat(char *dest, const char *src, t_size n)
{
	char	*dst_cpy;
	char	*src_cpy;
	t_size	counter;
	t_size	begin;

	dst_cpy = (char *)dest;
	src_cpy = (char *)src;
	counter = 0;
	while (*(dst_cpy + counter) != '\0' && counter < n)
		counter++;
	begin = counter;
	while (*(src_cpy + counter - begin) != '\0' && counter + 1 < n)
	{
		*(dst_cpy + counter) = *(src_cpy - begin + counter);
		counter++;
	}
	if (begin < n)
		*(dst_cpy + counter) = '\0';
	return (begin + ft_strlen(src));
}
