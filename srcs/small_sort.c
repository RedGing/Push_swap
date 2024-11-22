/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:52 by minjkim2          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:37 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_stack **stack, int size)
{
	t_node	*temp;
	int		max;

	temp = (*stack)->top;
	max = temp->data;
	while (--size > 0)
	{
		if (max < temp->next->data)
			max = temp->next->data;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_stack **stack, int size)
{
	t_node	*temp;
	int		min;

	temp = (*stack)->top;
	min = temp->data;
	while (--size > 0)
	{
		if (min > temp->next->data)
			min = temp->next->data;
		temp = temp->next;
	}
	return (min);
}

void	three_count_sort(t_stack **stack, t_alloc **alloc)
{
	if ((*stack)->top->data < (*stack)->top->next->data)
	{
		if ((*stack)->top->next->data < (*stack)->top->next->next->data)
			return ;
		ra((*stack), alloc);
		sa((*stack));
		rra((*stack), alloc);
	}
	else if ((*stack)->top->data > (*stack)->top->next->next->data)
	{
		sa((*stack));
		ra((*stack), alloc);
		sa((*stack));
		rra((*stack), alloc);
	}
	if ((*stack)->top->data > (*stack)->top->next->data)
		sa((*stack));
}

void	three_sort(t_stack **stack, t_alloc **alloc)
{
	if ((*stack)->size == 3)
	{
		if (!is_sorted(stack, (*stack)->size))
		{
			if ((*stack)->top->next->data > (*stack)->top->data && \
				(*stack)->top->next->data > (*stack)->bottom->data)
				rra((*stack), alloc);
			else if ((*stack)->top->data > (*stack)->top->next->data && \
					(*stack)->top->data > (*stack)->bottom->data)
				ra((*stack), alloc);
			if ((*stack)->top->data > (*stack)->top->next->data)
				sa((*stack));
		}
	}
	else
		three_count_sort(stack, alloc);
}
