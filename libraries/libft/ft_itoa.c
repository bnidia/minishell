/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:57:19 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/26 17:54:52 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_itoa
** Allocates (with malloc(3)) and returns a string representing the integer
** received as an argument. Negative numbers must be handled.
** Return Value
** The string representing the integer. NULL if the allocation fails.
** Comment
** max int 2,147,483,647 - 10b + '-' + '/0' = 12b
** real    0m33.436s user    0m33.435s sys     0m0.001s
*/

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*str_r;
	char	*result;

	str = (char *)malloc(16);
	if (!str)
		return (NULL);
	result = str;
	str_r = str;
	*str++ = "9876543210123456789"[9 + n % 10];
	while (n / 10)
	{
		n /= 10;
		*str++ = "9876543210123456789"[9 + n % 10];
	}
	if (n < 0)
		*str++ = '-';
	*str-- = '\0';
	while (str_r < str)
	{
		n = *str;
		*str-- = *str_r;
		*str_r++ = n;
	}
	return (result);
}
