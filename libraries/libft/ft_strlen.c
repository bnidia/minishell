/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:06:57 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:24:44 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strlen
** Calculates the length of the string pointed to by s, excluding
** the terminating null byte ('\0')
** Return Value
** Number of characters in the string pointed to by s
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
