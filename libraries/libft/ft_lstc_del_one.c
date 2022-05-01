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

#include <stdlib.h>
#include "ft_lstc.h"

/* ft_lstc_del_one
** Takes as a parameter an element and frees the memory of the element’s
** content using the function ’del’ given as a parameter and free the
** element. The memory of ’next’ must not be freed
*/
void	ft_lstc_del_one(t_listc **lst)
{
	if (*lst != (*lst)->prev)
		ft_lstc_pop(*lst);
	free(*lst);
	*lst = NULL;
}
