/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort2.c                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finding_place(t_Nodea **s, t_Nodea **b, t_steps **steps, int min)
{
	int	action;
	int	res;
	int	buff;
	int	z;

	action = 0;
	buff = 0;
	z = count_list(s);
	ft_help_finding_place(s, b, &action, &buff);
	if ((*s)->rotate == -1)
		action = z - action;
	if (min == -1 || (action + (*b)->step) < min)
	{
		(*steps)->dest_a = (*s)->rotate;
		(*steps)->dest_b = (*b)->rotate;
		(*steps)->count_a = action;
		(*steps)->count_b = (*b)->step;
		res = action + (*b)->step;
	}
	else
		res = min;
	return (res);
}

int	ft_small_element(t_Nodea *a, int buff, int src)
{
	t_Nodea	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buff && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

int	ft_count_to_min(t_Nodea *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_minimum_insertion_steps(t_Nodea **stacks, t_Nodea **sb, \
t_steps **steps)
{
	int		min_action;
	t_Nodea	*first_a;
	t_Nodea	*first_b;

	min_action = -1;
	first_a = *stacks;
	first_b = *sb;
	while (*sb)
	{
		min_action = ft_finding_place(stacks, sb, steps, min_action);
		(*stacks) = first_a;
		*sb = (*sb)->next;
	}
	*sb = first_b;
}

void	ft_help_finding_place(t_Nodea **s, t_Nodea **b, int *action, int *buff)
{
	while (s)
	{
		*buff = (*s)->data;
		if ((*b)->data > (*s)->data)
		{
			*action += 1;
			if ((*b)->data < (*s)->next->data)
				break ;
			(*s) = (*s)->next;
		}
		else
			break ;
	}
	if (ft_small_element((*s), *buff, (*b)->data) == 1)
	{
		while ((*s))
		{
			if ((*s)->data < *buff && (*s)->data > (*b)->data)
				break ;
			*action += 1;
			(*s) = (*s)->next;
		}
	}
}
