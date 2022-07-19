/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:52:49 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/19 18:24:20 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	print_tokens(void *data)
{
	t_token	*token_ptr;

	token_ptr = (t_token *)data;
	printf("token { type: %2d, str: %s }\n", token_ptr->type, token_ptr->str);
}

int minimain(t_env_list *envs)
{
	char			*line;
	t_token_list	*token_list;
	t_cmdline		cmdline;

	(void) envs;
	line = readline("#> ");
	if (line == (char *)0)
		return (MINIMAIN_EXIT);

	cmdline = (t_cmdline) {
		.str	= line,
		.begin	= line,
		.end	= line + ft_strlen(line),
		.size	= ft_strlen(line),
		.execed	= EXECED_NO
	};

	token_list = lex_tokenize(cmdline);
	ft_lstiter(token_list->tokens, print_tokens);
	token_list_free(token_list);
	return (MINIMAIN_CONTINUE);
}
