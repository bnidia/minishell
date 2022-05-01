/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:02:16 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 02:56:34 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_memset
** Fill with "len" bytes of "c" the memory of "dest".
** Пример: ("123456", '!', 2) получим "!!3456"
** Return Value
** A pointer to the memory area dest
*/

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*d;

	d = (char *)dest;
	while (len--)
		*d++ = c;
	return (dest);
}
