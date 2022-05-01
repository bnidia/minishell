/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:15:00 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTC_H
# define FT_LSTC_H

typedef struct s_listc
{
	int				value;
	int				score_ra;
	int				score_rra;
	int				score_rb;
	int				score_rrb;
	struct s_listc	*prev;
	struct s_listc	*next;
}				t_listc;

t_listc		*ft_lstc_new(int value);
void		ft_lstc_add(t_listc *lst, t_listc *new);
int			ft_lstc_size(t_listc *lst);
void		ft_lstc_pop(t_listc *lst);
void		ft_lstc_del_one(t_listc **lst);
void		ft_lstc_clear(t_listc **lst);

#endif //FT_LSTC_H