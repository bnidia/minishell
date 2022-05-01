/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:43:31 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 10:19:17 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstiter
** Iterates the list ’lst’ and applies the function ’f’ to the content
** of each element
** Pointer *lst not moved and not corrupted
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_temp;

	lst_temp = lst;
	while (lst_temp)
	{
		f(lst_temp->content);
		lst_temp = lst_temp->next;
	}
}
