/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 03:19:21 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:36:36 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strdup
** Duplicate string s. Memory for the new string is obtained with malloc,
** and can be freed with free
** Return Value
** A pointer to the duplicated string. NULL if insufficient memory
** was available
*/

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;

	cpy = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!(cpy))
		return (NULL);
	i = -1;
	while (str[++i])
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}
