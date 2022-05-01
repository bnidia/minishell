/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 06:11:18 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lstc.h"

/* ft_lstc_new
** Allocates (with malloc(3)) and returns a new element in a circled
** doubly linked list.
** The variable ’content’ is initialized with the value of the parameter
** ’content’. The variable ’next’ is initialized to NULL
** Return Value
** The new element
*/

t_listc	*ft_lstc_new(int value)
{
	t_listc	*new;

	new = (t_listc *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->score_ra = 0;
	new->score_rra = 0;
	new->score_rb = 0;
	new->score_rrb = 0;
	new->prev = new;
	new->next = new;
	return (new);
}
