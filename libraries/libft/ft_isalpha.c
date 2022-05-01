/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:53:05 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:12:47 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isalpha 
** Check for a alpabetic character, it is equivalent to (ft_isupper(c)
** or ft_islower(c))
** Return Value: 
** 0 if the character tests false and 1 if the character tests true
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
