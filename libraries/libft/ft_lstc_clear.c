/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:13:47 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_lstc.h"

/* ft_lstс_clear
** Deletes and frees the given element and every successor of that element,
** using the function ’del’ and free(3). Finally, the pointer to the list
** must be set to NULL
*/
void	ft_lstc_clear(t_listc **lst)
{
	t_listc	*next_elem;

	while (*lst)
	{
		if (*lst == (*lst)->next)
		{
			ft_lstc_del_one(lst);
			return ;
		}
		next_elem = (*lst)->next;
		ft_lstc_del_one(lst);
		*lst = next_elem;
	}
	*lst = NULL;
}
