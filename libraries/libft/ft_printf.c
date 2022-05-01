/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:23:08 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/04 19:53:34 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_width_precision(t_pf *z);
static int	process_type_field(va_list ap, t_pf *z);
static void	reset_width_precision(t_pf *z);
int			ft_print_out(t_pf *z);
extern int	ft_c(t_pf *z, char c);
extern int	ft_d(t_pf *z, int nbr);
extern int	ft_p(t_pf *z, unsigned long long nbr);
extern int	ft_s(t_pf *z, const char *str);
extern int	ft_u(t_pf *z, unsigned int nbr);
extern int	ft_x(t_pf *z, unsigned int nbr, char base_charset);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_pf	z;

	if (str == NULL)
		return (-1);
	va_start(ap, str);
	z = (t_pf){};
	z.str = str;
	while (z.str[z.str_i])
	{
		if (z.str[z.str_i] == '%')
		{
			process_width_precision(&z);
			if (process_type_field(ap, &z) == -1)
				return (-1);
			reset_width_precision(&z);
			continue ;
		}
		z.s[z.s_i++] = z.str[z.str_i++];
		if (ft_print_out(&z) == -1)
			return (-1);
	}
	va_end(ap);
	z.s_printed += (int)write(1, z.s, z.s_i);
	return (z.s_printed);
}

static void	process_width_precision(t_pf *z)
{
	while (z->str[++z->str_i] == '0' || z->str[z->str_i] == '-' \
		|| z->str[z->str_i] == ' ' || z->str[z->str_i] == '+' \
		|| z->str[z->str_i] == '#')
	{
		if (z->str[z->str_i] == '0')
			z->f_zero = true;
		else if (z->str[z->str_i] == '-')
			z->f_minus = true;
		else if (z->str[z->str_i] == ' ')
			z->f_space = true;
		else if (z->str[z->str_i] == '+')
			z->f_plus = true;
		else if (z->str[z->str_i] == '#')
			z->f_hash = true;
	}
	z->precision = -1;
	if (ft_isdigit(z->str[z->str_i]))
		z->width = ft_atoi(&z->str[z->str_i]);
	while (ft_isdigit(z->str[z->str_i]))
		z->str_i++;
	if (z->str[z->str_i] == '.')
		z->precision = ft_atoi(&z->str[++z->str_i]);
	while (ft_isdigit(z->str[z->str_i]))
		z->str_i++;
}

static int	process_type_field(va_list ap, t_pf *z)
{
	int	err;

	err = 0;
	if (z->str[z->str_i] == 'c')
		err = ft_c(z, va_arg(ap, int));
	if (z->str[z->str_i] == 's')
		err = ft_s(z, va_arg(ap, char *));
	if (z->str[z->str_i] == 'p')
		err = ft_p(z, va_arg(ap, t_ull));
	if (z->str[z->str_i] == 'd' || z->str[z->str_i] == 'i')
		err = ft_d(z, va_arg(ap, int));
	if (z->str[z->str_i] == 'u')
		err = ft_u(z, va_arg(ap, unsigned int));
	if (z->str[z->str_i] == 'x')
		err = ft_x(z, va_arg(ap, unsigned int), 'x');
	if (z->str[z->str_i] == 'X')
		err = ft_x(z, va_arg(ap, unsigned int), 'X');
	if (z->str[z->str_i++] == '%')
		z->s[z->s_i++] = '%';
	return (err);
}

static void	reset_width_precision(t_pf *z)
{
	z->f_zero = false;
	z->f_minus = false;
	z->f_space = false;
	z->f_plus = false;
	z->f_hash = false;
	z->width = 0;
	z->precision = -1;
}

/* 24 bytes is enough because ull 0xffffffffffffffff - 18 chars */
int	ft_print_out(t_pf *z)
{
	int	i;

	i = 0;
	if (z->s_i + 24 > BUF_SIZE)
	{
		i = (int) write(1, z->s, z->s_i);
		z->s_printed += z->s_i;
		z->s_i = 0;
	}
	return (i);
}
