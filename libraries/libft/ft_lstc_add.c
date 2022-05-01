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

#include "ft_lstc.h"

/* ft_lstc_add
** Adds the element ’new’ after the 'lst' in a circled doubly linked list
**
*/

void	ft_lstc_add(t_listc *lst, t_listc *new)
{
	new->prev = lst;
	new->next = lst->next;
	lst->next = new;
	new->next->prev = new;
}
