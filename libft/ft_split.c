/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:23:50 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/17 10:50:52 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_size	ft_getnstr(char const *s, char c)
{
	t_size	nstr;

	nstr = 0;
	if (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c)
			nstr++;
		while (*s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			while (*s == c)
				s++;
			if (*s != '\0')
				nstr++;
		}
	}
	return (nstr);
}

static void	ft_release_previous(char **strs, t_size n)
{
	while (n != 0)
	{
		free(strs[n - 1]);
		n--;
	}
	free(strs);
}

static char	*ft_create_new_string(char const *s, char c, t_size *current)
{
	t_size	begin;
	char	*str;

	begin = *current;
	while (s[*current] != c && s[*current] != '\0')
		(*current)++;
	str = ft_substr(s, (unsigned int)begin, (t_size)(*current - begin));
	while (s[*current] == c)
		(*current)++;
	return (str);
}

static char	**ft_strsmove(char const *s, char **strs, char c)
{
	t_size	current;
	t_size	n;

	if (c != '\0')
	{
		n = 0;
		current = 0;
		while (s[current] == c)
			current++;
		while (s[current] != '\0' && n < ft_getnstr(s, c))
		{
			strs[n++] = ft_create_new_string(s, c, &current);
			if (strs[n - 1] == (char *)0)
			{
				ft_release_previous(strs, n);
				return ((char **)0);
			}
		}
	}
	else if (*s != '\0')
		strs[0] = ft_strdup(s);
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	t_size	nstr;
	char	**strs;

	if (s == (char const *)0)
		return ((char **)0);
	if (c == '\0' && *s != '\0')
		nstr = 1;
	else
		nstr = ft_getnstr(s, c);
	strs = (char **)ft_calloc(nstr + 1, sizeof(char *));
	if (strs == (char **)0)
		return ((char **)0);
	strs[nstr] = (char *)0;
	return (ft_strsmove(s, strs, c));
}
