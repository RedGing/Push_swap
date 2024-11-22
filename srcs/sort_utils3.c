/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:52:10 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:33 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a, t_alloc **alloc)
{
	int	temp;

	if (stack_a->size == 0)
		return ;
	temp = stack_a->bottom->data;
	no_bottom(stack_a);
	on_top(stack_a, temp, alloc);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_b->size == 0)
		return ;
	temp = stack_b->bottom->data;
	no_bottom(stack_b);
	on_top(stack_b, temp, alloc);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_alloc **alloc)
{
	int	temp;

	if (stack_a->size != 0)
	{
		temp = stack_a->bottom->data;
		no_bottom(stack_a);
		on_top(stack_a, temp, alloc);
	}
	if (stack_b->size != 0)
	{
		temp = stack_b->bottom->data;
		no_bottom(stack_b);
		on_top(stack_b, temp, alloc);
	}
	ft_putstr_fd("rrr\n", 1);
}
