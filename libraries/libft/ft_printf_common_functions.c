/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/04/09 10:17:11 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_out(t_pf *z);

void	reset_insignificant_values(t_pf *z, int signlen)
{
	if (z->f_zero && z->width > 0 && z->precision <= 0)
	{
		z->f_zero = false;
		z->precision = z->width - signlen;
		z->width = 0;
	}
	if (z->width <= z->precision)
		z->width = 0;
}

int	output_of_initial_spaces(t_pf *z, int numlen, int signlen)
{
	int	spaces;

	spaces = 0;
	if (z->width > numlen || z->precision < numlen)
		spaces = z->width - numlen - signlen;
	if (z->width > z->precision && z->precision > numlen)
		spaces = z->width - z->precision - signlen;
	while (spaces > 0 && !z->f_minus)
	{
		z->s[z->s_i++] = ' ';
		if (ft_print_out(z) == -1)
			return (-1);
		spaces--;
	}
	return (0);
}

int	output_of_zeros(t_pf *z, int numlen, int signlen)
{
	int	zero;

	zero = 0;
	if (z->precision > numlen)
		zero = z->precision - numlen;
	else if (z->f_zero && z->width > numlen)
		zero = z->width - numlen - signlen;
	if (z->f_zero && z->precision < numlen \
							&& z->width > z->precision && z->precision > 0)
		zero = 0;
	while (zero--)
	{
		z->s[z->s_i++] = '0';
		if (ft_print_out(z) == -1)
			return (-1);
	}
	return (0);
}

int	output_of_finite_spaces(t_pf *z, int numlen, int signlen)
{
	int	spaces;

	spaces = z->width - numlen - signlen;
	if (z->width >= z->precision && z->precision > numlen)
		spaces = z->width - z->precision - signlen;
	if (z->width < z->precision)
		spaces = 0;
	while (z->f_minus && spaces > 0)
	{
		z->s[z->s_i++] = ' ';
		if (ft_print_out(z) == -1)
			return (-1);
		spaces--;
	}
	return (0);
}

int	for_zero_put_empty_string(t_pf *z, unsigned int nbr)
{
	if (z->precision == 0 && nbr == 0)
	{
		while (z->width-- > 0)
		{
			z->s[z->s_i++] = ' ';
			z->return_value = ft_print_out(z);
			if (z->return_value == -1)
				return (-1);
		}
		z->return_value = 0;
		return (0);
	}
	z->return_value = 1;
	return (1);
}
