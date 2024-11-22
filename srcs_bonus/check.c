/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:28:34 by femorell          #+#    #+#             */
/*   Updated: 2023/05/04 16:58:04 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_valid(char **av, t_alloc **alloc)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			while (is_space(av[i][j]))
				j++;
			if (!av[i][j])
				break ;
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
				print_error(alloc);
			while (ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] && !is_space(av[i][j]))
				print_error(alloc);
		}
		i++;
	}
}

static void	range_util(char *str, t_alloc **alloc)
{
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		print_error(alloc);
	while (is_space(*str) && *str)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) >= 11)
		print_error(alloc);
}

void	check_range(char **av, t_alloc **alloc)
{
	char	**temp;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ', alloc);
			while (temp[j])
			{
				range_util(temp[j], alloc);
				j++;
			}
		}
		else
			range_util(av[i], alloc);
		i++;
	}
}

void	check_overlap(int *arr, int size, t_alloc **alloc)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				print_error(alloc);
			j++;
		}
		i++;
	}
}
