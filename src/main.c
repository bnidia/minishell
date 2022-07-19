/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:17:11 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/19 16:47:17 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

void env_lst_print_routine(void *data)
{
	char *env_variable;

	env_variable = (char *)data;
	printf("env: %s\n", env_variable);
}

// #[todo] initialize cmdline
int	main(void)
{
	t_env_list	*env_lst_ptr;

	env_lst_ptr = env_list();

	// if (env_lst_ptr != (t_env_list*)0)
	// {
	// 	printf("------------------- All ENV: -------------------\n");
	// 	ft_lstiter(env_lst_ptr->envs, env_lst_print_routine);

	// 	printf("------------------- Search ENV: -------------------\n");

	// 	char **path = env_value(env_lst_ptr, "PATH");
	// 	printf("Searching $(%s) := %s\n", path[0], path[1]);

	// 	env_value_free(path);
	// 	env_list_free(env_lst_ptr);
	// }

	if (env_lst_ptr != (t_env_list *)0)
	{
		while (minimain(env_lst_ptr) != MINIMAIN_EXIT)
			;
		env_list_free(env_lst_ptr);
	}

	return (0);
}
