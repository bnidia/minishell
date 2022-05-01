/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 07:07:25 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 01:41:50 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memchr
** Scans the initial len bytes of b for the first instance of c
** Return Value
** A pointer to the matching byte or NULL if the character does
** not occur in the given memory area
*/

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len--)
		if (*str++ == (char)c)
			return (str - 1);
	return (NULL);
}
