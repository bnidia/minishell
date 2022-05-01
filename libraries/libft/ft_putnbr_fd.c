/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:38:16 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:41:46 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putnbr_fd
** Outputs the integer 'n' to the given file descriptor
** 
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		ft_putchar_fd(c, fd);
	}
	if (n < 10)
	{
		c = n % 10 + '0';
		ft_putchar_fd(c, fd);
	}
}
