/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_for_push_swap.c                           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	num;
	int	cnt;

	sign = 1;
	cnt = 0;
	num = 0;
	while ((str[cnt] == ' ') || (str[cnt] == '\t') || (str[cnt] == '\n') \
		|| (str[cnt] == '\v') || (str[cnt] == '\f') || (str[cnt] == '\r'))
		cnt++;
	if (str[cnt] == '-')
		sign = -1;
	if ((str[cnt] == '-') || (str[cnt] == '+'))
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = (num * 10) + ((int)str[cnt] - '0');
		cnt++;
	}
	return (num * sign);
}

void	ft_free_stack(t_Nodea *stacks)
{
	t_Nodea	*buff;

	while (stacks)
	{
		buff = stacks;
		stacks = stacks->next;
		free(buff);
	}
}

void	ft_execution(t_Nodea **stacks, t_Nodea **sb, \
t_steps **steps)
{
	while ((*steps)->count_a > 0)
	{
		if ((*steps)->dest_a == 1)
			ft_ra(stacks, 1);
		else
			ft_rra(stacks, 1);
		(*steps)->count_a--;
	}
	while ((*steps)->count_b > 0)
	{
		if ((*steps)->dest_b == 1)
			ft_rb(sb, 1);
		else
			ft_rrb(sb, 1);
		(*steps)->count_b--;
	}
	ft_pa(stacks, sb, 1);
}
