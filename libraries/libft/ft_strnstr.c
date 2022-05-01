/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:07:25 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/26 19:24:47 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strnstr
** Locate substring, where not more than 'len' characters are searched.
** Finds the first occurrence of the substring 'little' in the string
** 'big'. The terminating null bytes ('\0') are not compared.
** Return Value
** A pointer to the first character of the first occurrence of little
** is returned. NULL if the substring is not found. If 'little' is an
** empty string, 'big' is returned
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(little))
		return ((char *)big);
	while (*(big + ++i) && i < len)
	{
		j = 0;
		if (*(big + i) == *(little + 0))
		{
			k = i;
			found = 1;
			while (*(big + k) && *(little + j) && j < len && k < len)
				if (*(big + k++) != *(little + j++))
					found = 0;
			if (found && !*(little + j))
				return ((char *)big + i);
		}
	}
	return (NULL);
}
