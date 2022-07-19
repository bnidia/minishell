/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:33:15 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/19 16:52:55 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "libft.h"

# define EXECED_YES	1
# define EXECED_NO	0

typedef enum e_token_type_
{
	TOKEN_TYPE_BEGIN,
	TOKEN_TYPE_END,
	TOKEN_TYPE_EXEC,
	TOKEN_TYPE_ARG,
	TOKEN_TYPE_QUOTE,
	TOKEN_TYPE_QUOTE_DOUBLE,
	TOKEN_TYPE_LESS,
	TOKEN_TYPE_LESS_DOUBLE,
	TOKEN_TYPE_MORE,
	TOKEN_TYPE_MORE_DOUBLE,
	TOKEN_TYPE_PIPE,
	TOKEN_TYPE_NEWLINE,
	TOKEN_TYPE_INPUT,
	TOKEN_TYPE_OUTPUT,
}	e_token_type;

typedef struct s_token
{
	e_token_type	type;
	char			*str;
}	t_token;

typedef struct s_token_list
{
	t_list	*tokens;
	int		size;
}	t_token_list;

// #[todo] init cmdline
// #[initial state] cmdline { str: a, begin: a, end: strlen(a), size: strlen(a) }
typedef struct s_cmdline
{
	char	*str;
	char	*begin;
	char	*end;
	int		size;
	int		execed;
}	t_cmdline;

t_token_list	*lex_tokenize(t_cmdline cmdline);
void			token_list_free(t_token_list *token_list);

# endif
