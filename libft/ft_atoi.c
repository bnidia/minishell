/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:25:15 by fdonna            #+#    #+#             */
/*   Updated: 2021/12/27 09:45:51 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_digit_len(char const *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

static int	ft_check_max_long(char const *str)
{
	const char	max_long[] = {"9223372036854775807"};
	t_size		max_long_len;
	t_size		str_len;
	t_size		i;

	str_len = ft_digit_len(str);
	max_long_len = ft_strlen(max_long);
	if (str_len != 0)
		while (*(str + str_len - 1) < '0' || *(str + str_len - 1) > '9')
			str_len--;
	if (str_len > max_long_len)
		return (FALSE);
	if (str_len < max_long_len)
		return (TRUE);
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > *(max_long + i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_check_min_long(char const *str)
{
	char const	min_long[] = {"-9223372036854775807"};
	t_size		min_long_len;
	t_size		str_len;
	t_size		i;

	str_len = ft_digit_len(str);
	min_long_len = ft_strlen(min_long);
	if (str_len != 0)
		while (*(str + str_len - 1) < '0' || *(str + str_len - 1) > '9')
			str_len--;
	if (str_len > min_long_len)
		return (FALSE);
	if (str_len < min_long_len)
		return (TRUE);
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > *(min_long + i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_check_prefix(const char **nptr, int *sign)
{
	*sign = 1;
	while (**nptr == ' ' || **nptr == '\t' || **nptr == '\n'\
		|| **nptr == '\f' || **nptr == '\r' || **nptr == '\v')
		(*nptr)++;
	if (*(*nptr + 1) < '0' || *(*nptr + 1) > '9')
		return (1);
	if (**nptr == '-')
	{
		*sign = -1;
		if (!ft_check_min_long(*nptr))
			return (0);
	}
	else
		if (!ft_check_max_long(*nptr))
			return (-1);
	if (**nptr == '-' || **nptr == '+')
		(*nptr)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	prefix_result;

	result = 0;
	prefix_result = ft_check_prefix(&nptr, &sign);
	if (prefix_result != 1)
		return (prefix_result);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += (int)*nptr - '0';
		nptr++;
	}
	return (result * sign);
}
