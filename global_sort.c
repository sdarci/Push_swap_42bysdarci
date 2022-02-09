/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_med(char **array, int argc)
{
	int	*array_sort;
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	array_sort = (int *)malloc((argc) * sizeof(int));
	while (i < argc)
	{
		x = ft_atoi(array[i]);
		array_sort[j] = x;
		i++;
		j++;
	}
	return (array_sort);
}

void	ft_global_sort(t_Nodea **stacks, t_Nodea **stackb, int med)
{
	int	rotations;

	rotations = 0;
	while (count_list(stacks) > 2)
	{
		if ((*stacks)->data != ft_min(*stacks) && (*stacks)->data \
		!= ft_max(*stacks))
		{
			ft_pb(stacks, stackb, 1);
			if (rotations++ == 0)
			{
				free((*stackb)->next);
				(*stackb)->next = NULL;
			}
		}
		if ((*stackb)->data > med)
			ft_rb(stackb, 1);
		if ((*stacks)->data == ft_min(*stacks) || (*stacks)->data \
		== ft_max(*stacks))
			ft_ra(stacks, 1);
	}
	if ((*stacks)->data < (*stacks)->next->data)
		ft_sa(stacks, 1);
	ft_pa(stacks, stackb, 1);
	ft_start_sort(stacks, stackb);
}

void	ft_start_sort(t_Nodea **stacks, t_Nodea **sb)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		return ;
	while ((*sb) != NULL)
	{
		ft_forsort(stacks, sb, &step);
	}
	(*stacks)->counta = count_list(stacks);
	if ((ft_count_to_min((*stacks), ft_min((*stacks))) > (*stacks)->counta / 2))
	{
		while ((*stacks)->data != ft_min(*stacks))
			ft_rra(stacks, 1);
	}
	else
		while ((*stacks)->data != ft_min(*stacks))
			ft_ra(stacks, 1);
	free(step);
}

void	ft_markup(t_Nodea **b)
{
	int		i;
	int		iter;
	t_Nodea	*buff;

	i = -1;
	iter = count_list(b) / 2;
	buff = *b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count_list(b) % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}
