/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:43:47 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:45:48 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstmap
** Iterates the list ’lst’ and applies the function ’f’ to the content of
** each element. Creates a new list resulting of the successive
** applications of the function ’f’. The ’del’ function is used to delete
** the content of an element if needed
** Return Value
** The new list. NULL if the allocation fails
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_elem = NULL;
	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&new_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&new_elem, new_list);
		lst = lst->next;
	}
	return (new_elem);
}
