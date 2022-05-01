/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:43:37 by bnidia            #+#    #+#             */
/*   Updated: 2021/11/03 10:20:04 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstlast
** Returns the last element of the list
** Return Value
** Return value Last element of the list
** Pointer lst_temp is here to not corrupt pointer lst
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_temp;

	lst_temp = lst;
	if (lst_temp)
	{
		while (lst_temp->next)
			lst_temp = lst_temp->next;
	}
	return (lst_temp);
}
