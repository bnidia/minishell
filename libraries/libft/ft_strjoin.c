/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:39:23 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 02:45:22 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strjoin
** Allocates (with malloc) and returns a new string, which is the result
** of the concatenation of 's1' and 's2'
** Return Value
** The new string. NULL if the allocation fails
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ostr;
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2 + 1;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (len <= 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	ostr = str + len_s1;
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(ostr, s2, len_s2);
	str[len - 1] = '\0';
	return (str);
}
