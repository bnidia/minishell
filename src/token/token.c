/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:54:33 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 18:17:31 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

// #[malloc'ed data]
static void token_list_clear_routine(void *data)
{
	t_token	*token_ptr;

	token_ptr = (t_token *)data;
	if (token_ptr != (t_token *)0)
		free(token_ptr);
}

void	token_list_free(t_token_list *token_list)
{
	if (token_list != (t_token_list *)0)
	{
		ft_lstdelone(token_list->tokens, token_list_clear_routine);
		free(token_list);
	}
}

