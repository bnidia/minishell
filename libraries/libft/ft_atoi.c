/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:51:47 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 10:17:11 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

/* ft_atoi
** Convert a string to the integer
** Return Value
** 0 if value not in range (error). The converted value.
*/
int	ft_atoi(const char *num_ptr)
{
	ssize_t		num;
	int			sign;

	num = 0;
	sign = 1;
	while (*num_ptr == '\t' || *num_ptr == '\n' || *num_ptr == '\v' \
		|| *num_ptr == '\f' || *num_ptr == '\r' || *num_ptr == ' ')
		num_ptr++;
	if (*num_ptr == '-')
		sign = -1;
	if (*num_ptr == '-' || *num_ptr == '+')
		num_ptr++;
	while (*num_ptr >= '0' && *num_ptr <= '9')
		num = num * 10 + *num_ptr++ - '0';
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		return (0);
	return (num * sign);
}
