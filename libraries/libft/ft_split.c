/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:38:55 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 12:50:30 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_split
** Allocates (with malloc(3)) and returns an array of strings obtained
** by splitting ’s’ using the character ’c’ as a delimiter. The array
** must be ended by a NULL pointer.
** Return Value
** The array of new strings resulting of the split. NULL if the
** allocation fails
*/

#include "libft.h"

static size_t	ft_count_word(char *str, char c);
static size_t	ft_count_letter(char *str, char c);
static char		*ft_word_to_str(char *str, char c);
static void		ft_words_to_arr(char **result, char *str, int c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	w_count;

	if (s)
	{
		w_count = ft_count_word((char *)s, c);
		result = (char **) malloc(sizeof(char *) * (w_count + 1));
		if (!result)
			return (NULL);
		result[w_count] = NULL;
		ft_words_to_arr(result, (char *)s, c);
		return (result);
	}
	return (NULL);
}

static size_t	ft_count_word(char *str, char c)
{
	size_t	w_count;

	w_count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		w_count++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (w_count);
}

static size_t	ft_count_letter(char *str, char c)
{
	size_t	l_count;

	l_count = 0;
	while (str[l_count] != c && str[l_count])
		l_count++;
	return (l_count);
}

static char	*ft_word_to_str(char *str, char c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	len = ft_count_letter(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static void	ft_words_to_arr(char **result, char *str, int c)
{
	size_t	w_index;

	w_index = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		result[w_index] = ft_word_to_str(str, c);
		if (!result[w_index] && result[0])
		{
			while (w_index != 0)
			{
				free(result[w_index]);
				result[w_index] = NULL;
				w_index--;
			}
			free(result);
			return ;
		}
		w_index++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
}
