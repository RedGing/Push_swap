/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:49:57 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 13:26:22 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	get_array_size(char **av)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
			count += count_words(av[i], ' ');
		else
			count++;
		i++;
	}
	return (count);
}

static void	to_array(char **av, int **arr, t_alloc **alloc)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ', alloc);
			while (temp[j])
				(*arr)[k++] = ft_atoi(temp[j++]);
		}
		else
			(*arr)[k++] = ft_atoi(av[i]);
		i++;
	}
}

static void	array_to_stack(int *arr, t_stack **stack_a, \
				int size, t_alloc **alloc)
{
	while (size > 0)
	{
		on_top((*stack_a), arr[size - 1], alloc);
		size--;
	}
}

void	parsing(char **av, t_stack **stack_a, t_alloc **alloc)
{
	int	*arr;
	int	size;

	check_valid(av, alloc);
	check_range(av, alloc);
	size = get_array_size(av);
	arr = (int *)ft_malloc(sizeof(int) * size, alloc);
	to_array(av, &arr, alloc);
	check_overlap(arr, size, alloc);
	array_to_stack(arr, stack_a, size, alloc);
}
