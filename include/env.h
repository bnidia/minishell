/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:44:23 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 16:45:48 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"

typedef struct s_env_list
{
	t_list *envs;
	int		size;
}	t_env_list;

/**
 * @brief Initialize and get system environment variables list.
 *
 * @return malloc'ed t_env_list*. don't forget to call env_list_free(t_env_list *env_list) when list not needed anymore.
 */
t_env_list *env_list(void);

/**
 * @brief
 *
 * @param env_list A pointer to memory allocated by t_env_list *env_list(void);
 */
void		env_list_free(t_env_list *env_list);

/**
 * @brief Search env variable by name in envs list.
 *
 * @param env_list_ptr A pointer to memory allocated by t_env_list *env_list(void);
 * @param req A search request. ex: "PATH"
 * @return char** A pair of values [req, value]. Need to be freed.
 */
char **env_value(t_env_list *env_list_ptr, const char *req);

/**
 * @brief
 *
 * @param env_value A pointer to memory allocated by char **env_value(t_env_list *env_list_ptr, const char *req);
 */
void env_value_free(char **env_value);

#endif
