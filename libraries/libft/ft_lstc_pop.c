/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:14:14 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstc.h"

/* ft_lstc_pop
** Detaches an element from stack
*/
void	ft_lstc_pop(t_listc *lst)
{
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	lst->next = lst;
	lst->prev = lst;
}
