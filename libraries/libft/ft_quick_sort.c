/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/03/15 11:01:30 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

static void	compare(int *s_arr, int *left, int *right, int middle);

/* ft_quick_sort - sorting array of int
** s_arr - array to sort, first - first element from to sort (set to 0)
** last - last element (calculate len of array and put here)
*/
void	ft_quick_sort(int *s_arr, int first, int last)
{
	int	left;
	int	right;
	int	middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = s_arr[(left + right) / 2];
		compare(s_arr, &left, &right, middle);
		while (left <= right)
			compare(s_arr, &left, &right, middle);
		ft_quick_sort(s_arr, first, right);
		ft_quick_sort(s_arr, left, last);
	}
}

static void	compare(int *s_arr, int *left, int *right, int middle)
{
	int	temp;

	while (s_arr[*left] < middle)
		(*left)++;
	while (s_arr[*right] > middle)
		(*right)--;
	if (*left <= *right)
	{
		temp = s_arr[(*left)];
		s_arr[(*left)] = s_arr[(*right)];
		s_arr[(*right)] = temp;
		(*left)++;
		(*right)--;
	}
}
