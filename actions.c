/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avtions.c                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_Nodea **a, int i)
{
	t_Nodea	*first_list;
	t_Nodea	*rotate_list;
	t_Nodea	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_Nodea **b, int i)
{
	t_Nodea	*first_list;
	t_Nodea	*rotate_list;
	t_Nodea	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_Nodea *s, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	ft_ra(&s->next, 0);
	ft_rb(&s->next, 0);
}

void	ft_rra(t_Nodea **a, int i)
{
	t_Nodea		*first_list;
	t_Nodea		*rotate_list;
	t_Nodea		*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_Nodea **b, int i)
{
	t_Nodea		*first_list;
	t_Nodea		*rotate_list;
	t_Nodea		*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	if (i == 1)
		write(1, "rrb\n", 4);
}
