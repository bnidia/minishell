/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:03:46 by fdonna            #+#    #+#             */
/*   Updated: 2022/07/12 16:56:24 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "env.h"

# define MINIMAIN_EXIT 0
# define MINIMAIN_CONTINUE 1

int	minimain(t_env_list *envs);

#endif
