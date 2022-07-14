/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:57:54 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/14 14:54:46 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(t_size nmemb, t_size size)
{
	void	*ptr;

	if (size % 2 != 0 && size != 1)
		while (size % 2 != 0)
			size++;
	ptr = (void *)malloc(nmemb * size);
	if (ptr == (void *)0)
		return ((void *)0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
