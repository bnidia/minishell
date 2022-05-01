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
# define LINUX 1
#else
# define LINUX 0
#endif

int			ft_print_out(t_pf *z);
int			output_of_finite_spaces(t_pf *z, int numlen, int signlen);
int			output_of_initial_spaces(t_pf *z, int numlen, int signlen);
static void	null_exception(t_pf *z);

int	ft_s(t_pf *z, const char *str)
{
	int	i;
	int	strlen;

	i = 0;
	if (str == NULL)
	{
		null_exception(z);
		return (0);
	}
	strlen = (int)ft_strlen(str);
	output_of_initial_spaces(z, strlen, 0);
	if (z->precision > strlen || z->precision == -1)
		z->precision = strlen;
	while (str[i] && i < z->precision)
	{
		z->s[z->s_i++] = str[i++];
		if (ft_print_out(z) == -1)
			return (-1);
	}
	output_of_finite_spaces(z, z->precision, 0);
	return (0);
}

static void	null_exception(t_pf *z)
{
	if ((z->precision > 5 || z->precision == -1) && LINUX)
		ft_s(z, "(null)");
	else if (z->precision != 0 && !LINUX)
		ft_s(z, "(null)");
	else
		ft_s(z, "");
}
