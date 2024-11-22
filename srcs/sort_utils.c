/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:04:30 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:35 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size == 1 || stack_a->size == 0)
		return ;
	temp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size == 1 || stack_b->size == 0)
		return ;
	temp = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if ((stack_a->size == 1 || stack_a->size == 0)
		&& (stack_b->size == 1 || stack_b->size == 0))
		return ;
	if (!(stack_a->size == 1 || stack_a->size == 0))
	{
		temp = stack_a->top->data;
		stack_a->top->data = stack_a->top->next->data;
		stack_a->top->next->data = temp;
	}
	if (!(stack_b->size == 1 || stack_b->size == 0))
	{
		temp = stack_b->top->data;
		stack_b->top->data = stack_b->top->next->data;
		stack_b->top->next->data = temp;
	}
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	temp = stack_b->top->data;
	no_top(stack_b);
	on_top(stack_a, temp, alloc);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	temp = stack_a->top->data;
	no_top(stack_a);
	on_top(stack_b, temp, alloc);
	ft_putstr_fd("pb\n", 1);
}
