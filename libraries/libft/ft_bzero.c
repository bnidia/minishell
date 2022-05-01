/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 06:06:38 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:47:56 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_bzero
** Erases the data in the "len" bytes of the memory starting at the
** location pointed by "b" writing zeroes
** 
*/

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, '\0', len);
}
