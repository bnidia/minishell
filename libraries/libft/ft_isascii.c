/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:41:27 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 11:33:37 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isascii
** Checks for an ASCII character, which is any character between 0 
** and octal 0177 inclusive
** Return Value
** 0 if the character tests false and 1 if the character tests true
*/

int	ft_isascii(int c)
{
	if ((unsigned int)c <= 127)
		return (1);
	return (0);
}
