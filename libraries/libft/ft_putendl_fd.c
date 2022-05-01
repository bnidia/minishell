/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:38:11 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/26 19:28:14 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putendl_fd
** Outputs the string 's' to the given file descritor, 
** followed by a newline
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
