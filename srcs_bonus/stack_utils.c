/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:45:46 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 13:26:15 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	on_top(t_stack *stack, int data, t_alloc **alloc)
{
	t_node	*new_node;

	new_node = init_node(data, alloc);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

void	on_bottom(t_stack *stack, int data, t_alloc **alloc)
{
	t_node	*new_node;

	new_node = init_node(data, alloc);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	no_top(t_stack *stack)
{
	if (stack->top == NULL)
		return ;
	else
	{
		if (stack->top->next)
		{
			stack->top = stack->top->next;
			stack->top->prev = NULL;
		}
		else
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
	}
	stack->size--;
}

void	no_bottom(t_stack *stack)
{
	if (stack->top == NULL)
		return ;
	else
	{
		if (stack->bottom->prev)
		{
			stack->bottom = stack->bottom->prev;
			stack->bottom->next = NULL;
		}
		else
		{
			stack->bottom = NULL;
			stack->top = NULL;
		}
	}
	stack->size--;
}
