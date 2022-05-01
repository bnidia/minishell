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

int		ft_print_out(t_pf *z);
void	ft_itoa_base(t_pf *z, t_ull nbr, int base, const char *base_);
int		for_zero_put_empty_string(t_pf *z, unsigned int nbr);
void	reset_insignificant_values(t_pf *z, int signlen);
int		output_of_initial_spaces(t_pf *z, int numlen, int signlen);
int		output_of_zeros(t_pf *z, int numlen, int signlen);
int		output_of_finite_spaces(t_pf *z, int numlen, int signlen);

int	ft_u(t_pf *z, unsigned int nbr)
{
	int	numlen;
	int	signlen;

	if (for_zero_put_empty_string(z, nbr) <= 0)
		return (z->return_value);
	signlen = 0;
	if (z->f_plus)
		signlen += 1;
	numlen = (int)ft_numlen((t_ull)ft_abs_d(nbr), 10);
	reset_insignificant_values(z, signlen);
	if (output_of_initial_spaces(z, numlen, signlen) == -1)
		return (-1);
	if (z->f_plus)
		z->s[z->s_i++] = '+';
	if (output_of_zeros(z, numlen, signlen) == -1)
		return (-1);
	if (z->f_space)
		z->s[z->s_i++] = ' ';
	ft_itoa_base(z, (t_ull)ft_abs_d(nbr), 10, "0123456789");
	if (output_of_finite_spaces(z, numlen, signlen) == -1)
		return (-1);
	return (0);
}
