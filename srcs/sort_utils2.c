/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:30:44 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:34 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a, t_alloc **alloc)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	temp = stack_a->top->data;
	no_top(stack_a);
	on_bottom(stack_a, temp, alloc);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	temp = stack_b->top->data;
	no_top(stack_b);
	on_bottom(stack_b, temp, alloc);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_a->size != 0)
	{
		temp = stack_a->top->data;
		no_top(stack_a);
		on_bottom(stack_a, temp, alloc);
	}
	if (stack_b->size != 0)
	{
		temp = stack_b->top->data;
		no_top(stack_b);
		on_bottom(stack_b, temp, alloc);
	}
	ft_putstr_fd("rr\n", 1);
}
