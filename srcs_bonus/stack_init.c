/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:50:50 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 13:26:17 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
