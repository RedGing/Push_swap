/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:32 by minjkim2          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:41 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insertion_sort(int *list, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
		i++;
	}
}

int	get_mid(t_stack **stack, int size, t_alloc **alloc)
{
	t_node		*node;
	int			*arr;
	int			mid;
	int			i;

	i = 0;
	node = (*stack)->top;
	arr = (int *)ft_malloc(sizeof(int) * size, alloc);
	if (!arr)
		print_error(alloc);
	while (node && i < size)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
	insertion_sort(arr, size);
	mid = arr[size / 2];
	return (mid);
}
