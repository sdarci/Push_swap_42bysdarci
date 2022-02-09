/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                        :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_Nodea **new)
{
	t_Nodea	*stack;

	stack = (*new);
	while (stack != NULL)
	{
		if (stack->next == NULL)
			return (0);
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_3_element(t_Nodea **stacks, int argc)
{
	int	max;

	max = ft_max(*stacks);
	if (argc == 2)
	{
		if ((*stacks)->data > (*stacks)->next->data)
			ft_sa(stacks, 1);
		return ;
	}
	else if (argc < 6 && argc > 2)
	{
		if ((*stacks)->data > (*stacks)->next->data)
			ft_sa(stacks, 1);
		if ((*stacks)->data == max)
			ft_ra(&(*stacks)->next, 1);
		if ((*stacks)->next->data == max)
		{
			ft_rra(&(*stacks), 1);
		}
	}
	if ((*stacks)->data > (*stacks)->next->data)
		ft_sa(stacks, 1);
}

void	ft_sort_5_element(t_Nodea **stacks, t_Nodea **stackb, int argc)
{
	int	max;
	int	min;

	min = ft_min(*stacks);
	max = ft_max(*stacks);
	cikle(stacks, stackb, min, max);
	ft_sort_3_element(stacks, argc - 2);
	ft_pa(stacks, stackb, 1);
	ft_pa(stacks, stackb, 1);
	if (ft_is_sorted(stacks) == 0)
		return ;
	if ((*stacks)->data == max)
		ft_ra(stacks, 1);
	else
	{
		ft_sa(stacks, 1);
		ft_ra(stacks, 1);
	}
}

void	cikle(t_Nodea **stacks, t_Nodea **stackb, int min, int max)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if ((*stacks)->data == min || (*stacks)->data == max)
		{
			ft_pb(stacks, stackb, 1);
			if (count == 0)
			{
				free((*stackb)->next);
				(*stackb)->next = NULL;
			}
			count++;
		}
		else
			ft_ra(stacks, 1);
	}
}
