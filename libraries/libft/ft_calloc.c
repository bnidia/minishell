/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 03:10:45 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 10:40:00 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_calloc
** Allocates enough space for count objects that are size bytes of
** memory each, and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero
** Return Value
** A pointer to the allocated memory, or NULL if the request fails
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	mem_size;

	mem_size = nmemb * size;
	pointer = malloc(mem_size);
	if (!(pointer))
		return (NULL);
	ft_memset(pointer, '\0', mem_size);
	return (pointer);
}
