/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:38:37 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:46:55 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putstr_fd
** Outputs the string 's' to the given file descriptor
** 
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	ssize_t	err;

	len = ft_strlen(s);
	err = write(fd, s, len);
	if (err == -1)
		err = 0;
}
