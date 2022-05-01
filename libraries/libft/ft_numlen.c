/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:06:57 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:24:44 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_numlen
** Calculates the length of the string pointed to by s, excluding
** the terminating null byte ('\0')
** Return Value
** Number of characters in the string pointed to by s
*/

#include "libft.h"

size_t	ft_numlen(unsigned long long num, int base)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}
