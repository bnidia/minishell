/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:01:53 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/19 18:12:24 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

char	*ft_strcopy(const char *src)
{
	int		len;
	char	*copy;
	int		i;

	i = 0;
	len = ft_strlen(src);
	copy = ft_calloc(1, (t_size)len + 1);
	if (copy == (char *)0)
		return ((char *)0);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

// #[allocation]
static t_token *token_new(char *str, e_token_type type)
{
	t_token	*token_ptr;

	token_ptr = ft_calloc(1, sizeof(t_token));
	if (token_ptr != (t_token *)0)
		*token_ptr = (t_token) { .str = str, .type = type };
	return (token_ptr);
}

static void	lex_skip_whitespaces(t_cmdline *cmdline)
{
	while (*cmdline->begin == ' ' || *cmdline->begin == '\t')
		cmdline->begin++;
}

static t_token *lex_quote(t_cmdline *cmdline)
{
	char	value[512];
	int		i;

	i = 0;
	ft_memset((void *)value, '\0', 512);
	if (*cmdline->begin == '\'')
	{
		cmdline->begin++;
		while (*cmdline->begin != '\'')
		{
			if (*cmdline->begin == '\0')
				return ((t_token *)0);
			value[i++] = *cmdline->begin;
			cmdline->begin++;
		}
		cmdline->begin++;
		lex_skip_whitespaces(cmdline);
		return (token_new(ft_strcopy(value), TOKEN_TYPE_QUOTE));
	}
	if (*cmdline->begin == '\"')
	{
		cmdline->begin++;
		while (*cmdline->begin != '\"')
		{
			if (*cmdline->begin == '\0')
				return ((t_token *)0);
			value[i++] = *cmdline->begin;
			cmdline->begin++;
		}
		cmdline->begin++;
		lex_skip_whitespaces(cmdline);
		return (token_new(ft_strcopy(value), TOKEN_TYPE_QUOTE_DOUBLE));
	}
	return ((t_token *)0);
}

static t_token *lex_pipe(t_cmdline *cmdline)
{
	cmdline->execed = EXECED_NO;
	cmdline->begin++;
	lex_skip_whitespaces(cmdline);
	return (token_new((char *)0, TOKEN_TYPE_PIPE));
}

static t_token *lex_less(t_cmdline *cmdline)
{
	int		double_less;
	char	input[255];
	int		i;

	i = 0;
	double_less = 0;
	ft_memset((void *)input, '\0', 255);
	if (*cmdline->begin == '<')
	{
		cmdline->begin++;
		if (*cmdline->begin == '<')
		{
			double_less = 1;
			cmdline->begin++;
		}
		lex_skip_whitespaces(cmdline);
		while (*cmdline->begin != ' ' && *cmdline->begin != '\t')
		{
			input[i++] = *cmdline->begin;
			cmdline->begin++;
		}
		lex_skip_whitespaces(cmdline);
		if (double_less)
			return (token_new(ft_strcopy(input), TOKEN_TYPE_LESS_DOUBLE));
		else
			return (token_new(ft_strcopy(input), TOKEN_TYPE_LESS));
	}
	return ((t_token *)0);
}

static t_token *lex_more(t_cmdline *cmdline)
{
	int		double_more;
	char	output[255];
	int		i;

	i = 0;
	double_more = 0;
	ft_memset((void *)output, '\0', 255);
	if (*cmdline->begin == '>')
	{
		cmdline->begin++;
		if (*cmdline->begin == '>')
		{
			double_more = 1;
			cmdline->begin++;
		}
		lex_skip_whitespaces(cmdline);
		while (*cmdline->begin != ' ' && *cmdline->begin != '\t' && *cmdline->begin != '\0')
		{
			output[i++] = *cmdline->begin;
			cmdline->begin++;
		}
		lex_skip_whitespaces(cmdline);
		if (double_more)
			return (token_new(ft_strcopy(output), TOKEN_TYPE_MORE_DOUBLE));
		else
			return (token_new(ft_strcopy(output), TOKEN_TYPE_MORE));
	}
	return ((t_token *)0);
}

// #[desc] handle current line
// #[todo] assign EXECED_NO to cmdline-execed when cmdline->begin is { '|',  }
// #[todo] lex_quote() -> return valid quote token or null if quoute is unclosed,
// lex_pipe(), lex_more(), lex_less()
static t_token *lex_current_line(t_cmdline *cmdline)
{
	char	value[512];
	int		i;

	i = 0;
	ft_memset((void *)value, '\0', 512);
	lex_skip_whitespaces(cmdline);
	if (cmdline->execed == EXECED_NO) // then we handle new execution command like [ls] -la ..
	{
		if (*cmdline->begin == '\'' || *cmdline->begin == '\"') // we can't exec "ls" -la
			return ((t_token *)0);
		cmdline->execed = EXECED_YES;
		while (*cmdline->begin != ' ' && *cmdline->begin != '\t' && *cmdline->begin != '\0')
		{
			value[i++] = *cmdline->begin;
			cmdline->begin++;
		}
		return (token_new(ft_strcopy(value), TOKEN_TYPE_EXEC)); // return exec str
	}
	if (*cmdline->begin == '\'' || *cmdline->begin == '\"')
		return (lex_quote(cmdline));
	else if (*cmdline->begin == '|')
		return (lex_pipe(cmdline));
	else if (*cmdline->begin == '>')
		return (lex_more(cmdline));
	else if (*cmdline->begin == '<')
		return (lex_less(cmdline));
	while (*cmdline->begin != ' ' && *cmdline->begin != '\t' && *cmdline->begin != '\0')
	{
		value[i++] = *cmdline->begin;
		cmdline->begin++;
	}
	return (token_new(ft_strcopy(value), TOKEN_TYPE_ARG)); // return arg str
}

// #[desc] handle end or newline
static t_token *lex_next_token(t_cmdline *cmdline)
{
	lex_skip_whitespaces(cmdline);
	if (*cmdline->begin == '\0')
		return (token_new((char *)0, TOKEN_TYPE_END));
	if (*cmdline->begin == '\\' && \
	(*(cmdline->begin + 1) == ' ' || *(cmdline->begin + 1) == '\t'))
	{
		cmdline->begin += 2;
		return (token_new((char *)0, TOKEN_TYPE_NEWLINE));
	}
	if (*cmdline->begin == '\\')
		return ((t_token *)0);
	return (lex_current_line(cmdline));
}

t_token_list *lex_tokenize(t_cmdline cmdline)
{
	t_token_list	*token_list_ptr;
	t_token			*current;

	token_list_ptr = ft_calloc(1, sizeof(t_token_list));
	if (token_list_ptr != (t_token_list *)0)
	{
		current = token_new((char *)0, TOKEN_TYPE_BEGIN);
		if (current != (t_token *)0)
		{
			ft_lstadd_back(&token_list_ptr->tokens, ft_lstnew((void *)current));
			while (current->type != TOKEN_TYPE_END)
			{
				current = lex_next_token(&cmdline);
				if (current == (t_token *)0)
				{
					token_list_free(token_list_ptr);
					return ((t_token_list *)0);
				}
				else
					ft_lstadd_back(&token_list_ptr->tokens, ft_lstnew((void *)current));
			}
			return (token_list_ptr);
		}
	}
	return ((t_token_list *)0);
}
