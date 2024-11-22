/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:50:50 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:32 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(t_alloc **alloc)
{
	t_stack	*stack;

	stack = (t_stack *)ft_malloc(sizeof(t_stack), alloc);
	if (!stack)
		print_error(alloc);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_cmd	*init_cmd(int count, t_alloc **alloc)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_malloc(sizeof(t_cmd), alloc);
	if (!cmd)
		print_error(alloc);
	cmd->count_pa = 0;
	cmd->count_pb = 0;
	cmd->count_ra = 0;
	cmd->count_rb = 0;
	cmd->pivot_b = 0;
	cmd->pivot_s = 0;
	cmd->count_origin = count;
	return (cmd);
}

t_node	*init_node(int data, t_alloc **alloc)
{
	t_node	*node;

	node = (t_node *)ft_malloc(sizeof(t_node), alloc);
	if (!node)
		print_error(alloc);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
