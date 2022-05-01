/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:12:39 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/29 01:44:36 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isalnum
** Check for an alphanumeric character; it is equivalent 
** to (ft_isalpha or ft_isdigit)
** Return Value
** 0 if the character tests false and 1 if the character tests true
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
