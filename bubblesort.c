/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_quick_sort(int *array, int argc)
{
	int	q;
	int	i;
	int	j;

	i = 0;
	j = argc - 1;
	while (i < argc - 1)
	{
		i++;
		while (j > i)
		{
			j--;
			if (array[j - 1] > array[j])
			{
				q = array[j - 1];
				array[j - 1] = array[j];
				array[j] = q;
			}
		}
	}
	return (array);
}

void	ft_forsort(t_Nodea **stacka, t_Nodea **sb, t_steps **step)
{
	(*step)->count_a = -1;
	(*step)->count_b = -1;
	(*sb)->countb = count_list(sb);
	(*step)->dest_a = 0;
	(*step)->dest_b = 0;
	ft_markup(stacka);
	ft_markup(sb);
	ft_minimum_insertion_steps(stacka, sb, step);
	ft_execution(stacka, sb, step);
}

int	count_list(t_Nodea **lst)
{
	int		count;
	t_Nodea	*p;

	count = 0;
	p = *lst;
	if ((*lst) == NULL)
		return (0);
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return (count);
}
