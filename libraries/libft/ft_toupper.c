/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 07:04:55 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:23:28 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_toupper
** If the character passed as an argument is a lowercase, convert to upper
** Return Value
** If c is a lowercase letter, returns its uppercase equivalent.
** Otherwise, it returns c.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
		return (c & '_');
	return (c);
}
