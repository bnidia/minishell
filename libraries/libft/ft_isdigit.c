/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:53:55 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:12:34 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isdigit
** Check for a digit (0 through 9)
** Return Value:
** 0 if the character tests false and 1 if the character tests true
*/

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}
