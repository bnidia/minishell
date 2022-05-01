/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:48:47 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:23:00 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isprint
** Checks for any printable character including space
** Return Value
** 0 if the character tests false and 1 if the character tests true
*/

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
