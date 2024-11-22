/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:58 by minjkim2          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	small_sort_a(t_vars **vars, int count)
{
	if (count == 2)
	{
		if (!is_sorted(&(*vars)->stack_a, count))
			sa((*vars)->stack_a);
		return (1);
	}
	else if (count == 3)
	{
		three_sort(&(*vars)->stack_a, &(*vars)->alloc);
		return (1);
	}
	else if (count == 5)
	{
		five_count_sort(vars);
		return (1);
	}
	return (0);
}

static void	sort_a(t_vars **vars, t_cmd **cmd, int count)
{
	int	i;

	i = -1;
	(*cmd)->pivot_b = ((get_min(&(*vars)->stack_a, count) \
		+ get_max(&(*vars)->stack_a, count)) / 2);
	(*cmd)->pivot_s = ((get_min(&(*vars)->stack_a, count) \
		+ (*cmd)->pivot_b) / 2);
	while (++i < count)
	{
		if ((*vars)->stack_a->top->data > (*cmd)->pivot_b)
		{
			ra((*vars)->stack_a, &(*vars)->alloc);
			(*cmd)->count_ra++;
		}
		else
		{
			pb((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
			(*cmd)->count_pb++;
			if ((*vars)->stack_b->top->data > (*cmd)->pivot_s)
			{
				rb((*vars)->stack_b, &(*vars)->alloc);
				(*cmd)->count_rb++;
			}
		}
	}
}

void	rotate_back(t_vars **vars, t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->count_ra > cmd->count_rb)
	{
		while (++i < cmd->count_rb)
			rrr((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
		while (++i <= cmd->count_ra && cmd->count_rb == (*vars)->stack_b->size)
			rra((*vars)->stack_a, &(*vars)->alloc);
		while (i++ <= cmd->count_ra \
			&& cmd->count_origin < (*vars)->stack_a->size)
			rra((*vars)->stack_a, &(*vars)->alloc);
	}
	else
	{
		while (++i < cmd->count_ra)
			rrr((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
		while (++i <= cmd->count_rb && cmd->count_ra == (*vars)->stack_a->size)
			rrb((*vars)->stack_b, &(*vars)->alloc);
		while (i++ <= cmd->count_rb \
			&& cmd->count_origin < (*vars)->stack_b->size)
			rrb((*vars)->stack_b, &(*vars)->alloc);
	}
}

void	a_to_b(t_vars **vars, int count)
{
	t_cmd	*cmd;

	if (is_sorted(&(*vars)->stack_a, count))
		return ;
	if (small_sort_a(vars, count))
		return ;
	cmd = init_cmd(count, &(*vars)->alloc);
	sort_a(vars, &cmd, count);
	rotate_back(vars, cmd);
	a_to_b(vars, cmd->count_ra);
	b_to_a(vars, cmd->count_rb);
	b_to_a(vars, cmd->count_pb - cmd->count_rb);
}
