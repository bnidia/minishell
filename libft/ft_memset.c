/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:17:08 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/10 18:33:47 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, t_size n)
{
	t_size	current_byte;

	current_byte = 0;
	while (current_byte < n)
		*((unsigned char *)(s) + current_byte++) = (unsigned char)c;
	return (s);
}
