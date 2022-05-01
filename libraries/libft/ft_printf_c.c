/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/04/05 18:02:58 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_out(t_pf *z);

extern int	ft_c(t_pf *z, char c)
{
	if (z->f_minus == false && z->width > 1)
	{
		while (z->width-- > 1)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	z->s[z->s_i++] = c;
	if (ft_print_out(z) == -1)
		return (-1);
	if (z->f_minus && z->width > 1)
	{
		while (z->width-- > 1)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	return (0);
}
