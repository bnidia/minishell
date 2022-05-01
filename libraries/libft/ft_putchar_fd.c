/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:38:05 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 02:39:37 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putchar_fd
** Outputs the character 'c' to the given file descriptor
** 
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	err;

	err = write(fd, &c, 1);
	if (err == -1)
		return ;
}
