/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:01:53 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 19:39:45 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"

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
	(void) cmdline;
	return ((t_token *)0);
}

static t_token *lex_pipe(t_cmdline *cmdline)
{
	(void) cmdline;
	return ((t_token *)0);
}

static t_token *lex_less(t_cmdline *cmdline)
{
	(void) cmdline;
	return ((t_token *)0);
}

static t_token *lex_more(t_cmdline *cmdline)
{
	(void) cmdline;
	return ((t_token *)0);
}

// #[desc] handle current line
// #[todo] assign EXECED_NO to cmdline-execed when cmdline->begin is { '|',  }
// #[todo] lex_quote() -> return valid quote token or null if quoute is unclosed,
// lex_pipe(), lex_more(), lex_less()
static t_token *lex_current_line(t_cmdline *cmdline)
{
	lex_skip_whitespaces(cmdline);
	if (cmdline->execed == EXECED_NO) // then we handle new execution command like [ls] -la ..
	{
		if (*cmdline->begin == '\'' || *cmdline->begin == '\"') // we can't exec "ls" -la
			return ((t_token *)0);
		cmdline->execed = EXECED_YES;
		return (token_new((char *)0, TOKEN_TYPE_EXEC));
	}
	if (*cmdline->begin == '\'' || *cmdline->begin == '\"')
		return (lex_quote(cmdline));
	else if (*cmdline->begin == '|')
		return (lex_pipe(cmdline));
	else if (*cmdline->begin == '>')
		return (lex_more(cmdline));
	else if (*cmdline->begin == '<')
		return (lex_less(cmdline));
	return (token_new((char *)0, TOKEN_TYPE_ARG));
}

// #[desc] handle end or newline
static t_token *lex_next_token(t_cmdline *cmdline)
{
	lex_skip_whitespaces(cmdline);
	if (cmdline->begin == cmdline->end)
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
			while (current->type != TOKEN_TYPE_END)
			{
				current = lex_next_token(&cmdline);
				if (current == (t_token *)0)
				{
					token_list_free(token_list_ptr);
					return ((t_token_list *)0);
				}
			}
			return (token_list_ptr);
		}
	}
	return ((t_token_list *)0);
}
