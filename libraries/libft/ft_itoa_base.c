/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/04/05 17:57:37 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_base(t_pf *z, t_ull nbr, int base, const char *base_)
{
	int	numlen;
	int	i;

	if (nbr == 0)
	{
		z->s[z->s_i++] = '0';
		return ;
	}
	numlen = (int)ft_numlen(nbr, base) - 1;
	i = 0;
	while (i <= numlen)
	{
		z->s[z->s_i + numlen - i] = base_[nbr % base];
		nbr /= base;
		i++;
	}
	z->s_i += numlen + 1;
}
