/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environmetn_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:02:48 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 16:48:15 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

void env_value_free(char **env_value)
{
	int	i;

	i = 0;
	if (env_value != (char **)0)
	{
		while (env_value[i])
			free(env_value[i++]);
		free(env_value);
	}
}

char **env_value(t_env_list *env_list_ptr, const char *req)
{
	t_list	*raw_list;
	char	**res;

	raw_list = env_list_ptr->envs;
	while (raw_list != (t_list *)0)
	{
		res = ft_split((char *)raw_list->content, '=');
		if (res != (char **)0 && !ft_strcmp(*res, req))
			return (res);
		else if (res != (char **)0)
			env_value_free(res);
		raw_list = raw_list->next;
	}
	return ((char **)0);
}
