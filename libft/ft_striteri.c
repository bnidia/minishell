/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:51:45 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:32:40 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;
	t_size			strlen;

	index = 0;
	if (s == (char *)0)
		return ;
	strlen = ft_strlen(s);
	while (index < strlen)
	{
		f(index, &s[index]);
		index++;
	}
}
