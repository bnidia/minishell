/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:13:17 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/04 19:55:52 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft.h"
# define BUF_SIZE 1024

typedef struct s_pf
{
	const char	*str;
	int			str_i;
	char		s[BUF_SIZE];
	int			s_i;
	int			s_printed;
	int			width;
	int			precision;
	int			f_minus;
	int			f_plus;
	int			f_hash;
	int			f_space;
	int			f_zero;
	int			return_value;
}				t_pf;

typedef unsigned long long	t_ull;

#endif
