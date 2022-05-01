/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:39:36 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 16:29:19 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strmapi
** Applies the function ’f’ to each character of the string ’s’ to create
** a new string (with malloc(3)) resulting from successive applications of ’f’.
** Return Value
** The string created from the successive applications of ’f’. Returns
** NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (!s)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(new_str + i) = f(i, *(s + i));
	*(new_str + i) = '\0';
	return (new_str);
}
