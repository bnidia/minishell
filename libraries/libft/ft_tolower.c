/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 07:05:04 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:24:02 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_tolower
** If the character passed as an argument is an uppercase, convert to lower
** Return Value
** If c is a uppercase letter, returns its lowercase equivalent.
** Otherwise, it returns c.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
		return (c | ' ');
	return (c);
}
