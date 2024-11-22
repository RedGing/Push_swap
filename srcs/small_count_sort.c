/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_count_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:48:28 by femorell          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **stack, int count)
{
	t_node	*temp;

	if (count == 0 || count == 1)
		return (1);
	temp = (*stack)->top;
	while (--count > 0)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	is_b_sorted(t_vars **vars, int count)
{
	t_node	*node;
	int		i;

	i = count;
	node = (*vars)->stack_b->top;
	while (--count > 0)
	{
		if (node->data > node->next->data)
			node = node->next;
		else
			return (0);
	}
	while (i-- > 0)
		pa((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
	return (1);
}

void	five_count_sort(t_vars **vars)
{
	t_cmd		*cmd;
	int			pivot;

	cmd = init_cmd(5, &(*vars)->alloc);
	pivot = get_mid(&(*vars)->stack_a, 5, &(*vars)->alloc);
	while (1)
	{
		if ((*vars)->stack_a->top->data < pivot)
		{
			pb((*vars)->stack_a, (*vars)->stack_b, &(*vars)->alloc);
			cmd->count_pb++;
		}
		else
		{
			ra((*vars)->stack_a, &(*vars)->alloc);
			cmd->count_ra++;
		}
		if (cmd->count_pb == 2)
			break ;
	}
	while (cmd->count_ra-- && (*vars)->stack_a->size != 3)
		rra((*vars)->stack_a, &(*vars)->alloc);
	three_sort(&(*vars)->stack_a, &(*vars)->alloc);
	two_sort_b(vars);
}
