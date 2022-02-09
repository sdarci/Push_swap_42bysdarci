/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <sdarci@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:40 by sdarci            #+#    #+#             */
/*   Updated: 2022/08/02 17:36:39 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_atoi(char *str);
typedef struct _Node
{
	int				data;
	struct _Node	*next;
	struct _Node	*prev;
	int				rotate;
	int				step;
	int				countb;
	int				counta;
}	t_Nodea;

typedef struct s_list
{
	int				count_a;
	int				count_b;
	int				dest_a;
	int				dest_b;
}	t_steps;
void	ft_forsort(t_Nodea **stacka, t_Nodea **sb, t_steps **step);
int		ft_toupperft_atoi(char *str);
int		ft_max(t_Nodea *s);
void	print_reversed(t_Nodea *node);
void	listprint(t_Nodea *lst);
void	ft_ra(t_Nodea **a, int i);
void	ft_rb(t_Nodea **b, int i);
void	ft_rra(t_Nodea **a, int i);
void	ft_rrb(t_Nodea **b, int i);
void	ft_rr(t_Nodea *s, int i);
int		ft_is_sorted(t_Nodea **new);
void	ft_sa(t_Nodea **a, int i);
void	ft_sort_3_element(t_Nodea **stacks, int argc);
int		ft_min(t_Nodea *s);
void	ft_sort_5_element(t_Nodea **stacks, t_Nodea **stackb, int argc);
void	ft_pa(t_Nodea **s, t_Nodea **stackb, int i);
void	ft_pb(t_Nodea **s, t_Nodea **sb, int i);
int		ft_len_stack(t_Nodea *stackb);
void	push_front(t_Nodea **lst, int arg);
void	ft_global_sort(t_Nodea **stacks, t_Nodea **stackb, int med);
int		*find_med(char **array, int argc);
int		*ft_quick_sort(int *array, int argc);
void	ft_free_stack(t_Nodea *stacks);
void	ft_start_sort(t_Nodea **stacks, t_Nodea **sb);
void	ft_markup(t_Nodea **b);
void	ft_help_finding_place(t_Nodea **s, t_Nodea **b, int *action, int *buff);
void	ft_minimum_insertion_steps(t_Nodea **stacks, t_Nodea **sb, \
t_steps **steps);
void	ft_execution(t_Nodea **stacks, t_Nodea **sb, \
t_steps **steps);
int		ft_count_to_min(t_Nodea *a, int min);
int		ft_finding_place(t_Nodea **s, t_Nodea **b, \
t_steps **steps, int min);
int		ft_count_list(t_Nodea **lst);
void	cikle(t_Nodea **stacks, t_Nodea **stackb, int min, int max);
int		count_list(t_Nodea **lst);
int		ft_count_to_min(t_Nodea *a, int min);
#endif
//sa - поменять местами первые 2 элемента в верхней части стека а.
//sb - поменять местами первые 2 элемента в верхней части стека б.
//ss - sa и sb одновременно.
//pb - первый элемент стека а и поместить в верзнюю часть стека б.
//pa - первый элемент верхней части стека б поместить в вернхюю часть стека а.
//ra - сдвинуть вверх все элементы стека на 1.  первый становится последним
//rb - тот же ra только с б.
//rr - rb и ra одновременно. 
//rra - сдвинуть все элементы стека а  на 1 вниз. первый становится последним.
//rrb - тоже что и rrb. только стек б 
//rrr - rra и rrb одновременно.
