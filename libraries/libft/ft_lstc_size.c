/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:12:49 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lstc.h"

/* ft_lstc_size
** Counts the number of elements in a circled doubly linked list
** Return Value
** Length of the list
*/
int	ft_lstc_size(t_listc *lst)
{
	int		i;
	t_listc	*start;

	if (lst == NULL)
		return (0);
	i = 1;
	start = lst;
	while (lst != start->prev)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
