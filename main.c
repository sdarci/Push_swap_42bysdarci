/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sstart(t_Nodea **stacka, int flag, char **argv)
{
	int		*test;
	t_Nodea	*stackb;

	stackb = (t_Nodea *)malloc(sizeof(t_Nodea));
	if (!stackb)
		return ;
	stackb->next = NULL;
	stackb->data = 0;
	if (flag - 1 > 5)
	{
		test = find_med(argv + 1, flag - 1);
		test = ft_quick_sort(test, flag - 1);
		ft_global_sort(stacka, &stackb, test[flag / 2 + 1]);
		free(test);
	}
	else
		ft_sort_5_element(stacka, &stackb, flag);
	ft_free_stack(stackb);
}

int	ft_max(t_Nodea *s)
{
	int	max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

int	ft_min(t_Nodea *s)
{
	int	min;

	min = s->data;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}

void	push_front(t_Nodea **lst, int arg)
{
	t_Nodea	*tmp;
	t_Nodea	*p;

	p = (t_Nodea *)malloc(sizeof(t_Nodea));
	p->next = NULL;
	tmp = (*lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	p->data = arg;
	p->next = NULL;
	tmp->next = p;
}

int	main(int argc, char **argv)
{
	int		i;
	t_Nodea	*stacka;

	i = 1;
	if (argc - 1 < 2)
		return (0);
	stacka = (t_Nodea *)malloc(sizeof(t_Nodea));
	if (!stacka)
		return (0);
	stacka->data = ft_atoi(argv[i]);
	stacka->next = NULL;
	while (i++ < argc - 1)
		push_front(&stacka, ft_atoi(argv[i]));
	if (ft_is_sorted(&stacka))
	{
		if (argc - 1 > 5)
			sstart(&stacka, argc - 1, argv);
		if (argc - 1 > 3 && argc - 1 < 6)
			sstart(&stacka, argc - 1, argv);
		if (argc - 1 > 1 && argc - 1 < 4)
			ft_sort_3_element(&stacka, argc - 1);
	}
	ft_free_stack(stacka);
}
