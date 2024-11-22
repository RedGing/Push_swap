/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:45:05 by minjkim2          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_sort_b(t_vars **vars)
{
	pa((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
	pa((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
	if ((*vars)->stack_a->top->data > (*vars)->stack_a->top->next->data)
		sa((*vars)->stack_a);
}

static int	small_sort_b(t_vars **vars, int count)
{
	if (count == 0)
		return (1);
	if (count == 1)
	{
		pa((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
		return (1);
	}
	else if (count == 2)
	{
		two_sort_b(vars);
		return (1);
	}
	if (is_b_sorted(vars, count))
		return (1);
	return (0);
}

static void	sort_b(t_vars **vars, t_cmd **cmd, int count)
{
	int	i;

	i = -1;
	(*cmd)->pivot_b = ((get_min(&(*vars)->stack_b, count) \
		+ get_max(&(*vars)->stack_b, count)) / 2);
	(*cmd)->pivot_s = ((get_min(&(*vars)->stack_b, count) \
		+ (*cmd)->pivot_b) / 2);
	while (++i < count)
	{
		if ((*vars)->stack_b->top->data <= (*cmd)->pivot_s)
		{
			rb((*vars)->stack_b, &(*vars)->alloc);
			(*cmd)->count_rb++;
		}
		else
		{
			pa((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
			(*cmd)->count_pa++;
			if ((*vars)->stack_a->top->data <= (*cmd)->pivot_b)
			{
				ra((*vars)->stack_a, &(*vars)->alloc);
				(*cmd)->count_ra++;
			}
		}
	}
}

void	b_to_a(t_vars **vars, int count)
{
	t_cmd	*cmd;

	if (small_sort_b(vars, count))
		return ;
	cmd = init_cmd(count, &(*vars)->alloc);
	sort_b(vars, &cmd, count);
	a_to_b(vars, cmd->count_pa - cmd->count_ra);
	rotate_back(vars, cmd);
	a_to_b(vars, cmd->count_ra);
	b_to_a(vars, cmd->count_rb);
}
