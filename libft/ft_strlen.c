/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:31:58 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/06 20:31:58 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlen(const char *s)
{
	t_size	length;

	length = 0;
	if (s)
		while (*(s++))
			++length;
	return (length);
}
