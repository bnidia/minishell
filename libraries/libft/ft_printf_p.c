/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:07:41 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/11 21:29:18 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#if defined(__linux__) || defined(linux) || defined(__linux)
# define PREFIX "(nil)"
#else
# define PREFIX "0x0"
#endif

extern void	ft_itoa_base(t_pf *z, t_ull nbr, int base, const char *base_);
int			ft_print_out(t_pf *z);
int			output_of_finite_spaces(t_pf *z, int numlen, int signlen);
int			output_of_initial_spaces(t_pf *z, int numlen, int signlen);
int			ft_s(t_pf *z, const char *str, bool print);

int	ft_p(t_pf *z, unsigned long long nbr)
{
	int	numlen;

	numlen = (int)ft_numlen(nbr, 16) + 2;
	if (nbr == 0)
	{
		if (ft_s(z, PREFIX, 0) == -1)
			return (-1);
		return (0);
	}
	if (output_of_initial_spaces(z, numlen, 0) == -1)
		return (-1);
	z->s[z->s_i++] = '0';
	z->s[z->s_i++] = 'x';
	ft_itoa_base(z, nbr, 16, "0123456789abcdef");
	if (output_of_finite_spaces(z, numlen, 0) == -1)
		return (-1);
	return (0);
}
