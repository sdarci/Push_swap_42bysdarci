/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                        :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_Nodea **a, int i)
{
	int		buff;
	t_Nodea	*stack;

	stack = (*a);
	if (stack == NULL)
		return ;
	buff = stack->data;
	stack->data = stack->next->data;
	stack->next->data = buff;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_Nodea *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_Nodea *s, int i)
{
	ft_sa(&s->next, 0);
	ft_sb(s->next, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	ft_pa(t_Nodea **s, t_Nodea **stackb, int i)
{
	t_Nodea	*buff;

	if ((*s) == NULL || !(*stackb))
		return ;
	push_front(s, (*stackb)->data);
	ft_rra(s, 0);
	buff = (*stackb)->next;
	free(*stackb);
	*stackb = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_Nodea **s, t_Nodea **sb, int i)
{
	t_Nodea	*buff;

	if (s == NULL)
		return ;
	buff = (*s);
	(*s) = (*s)->next;
	buff->next = (*sb);
	(*sb) = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}
