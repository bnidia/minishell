/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:43:25 by bnidia            #+#    #+#             */
/*   Updated: 2021/10/25 19:44:10 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstdelone
** Takes as a parameter an element and frees the memory of the element’s
** content using the function ’del’ given as a parameter and free the
** element. The memory of ’next’ must not be freed
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del && lst)
		del(lst->content);
	free(lst);
}
