/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:43:56 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 16:01:26 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

t_env_list	*env_list(void)
{
	t_env_list	*list;
	extern char	**environ;
	int			i;

	list = ft_calloc(1, sizeof(t_env_list));
	if (list == (t_env_list*)0)
		return (list);
	i = 0;
	if (environ != (char **)0)
	{
		while (environ[i] != (char *)0)
		{
			ft_lstadd_back(&list->envs, ft_lstnew((void *)environ[i]));
			i++;
		}
		list->size = i;
		return (list);
	}
	return ((t_env_list*)0);
}

static void env_list_clear_routine(void *data)
{
	(void) data;
	return ;
}

void		env_list_free(t_env_list *env_list)
{
	ft_lstclear(&env_list->envs, env_list_clear_routine);
	if (env_list)
		free(env_list);
}
