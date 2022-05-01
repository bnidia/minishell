/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:39:08 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:40:36 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_striteri
** Applies the function f to each character of the string passed as
** argument, and passing its index as first argument. Each character
** is passed by address to f to be modified if necessary
** 
** 
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	if (s && f)
		while (*(s + ++i))
			f(i, s + i);
}
