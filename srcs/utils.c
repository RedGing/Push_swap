/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:44:45 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 11:27:29 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_alloc **alloc)
{
	free_all(alloc);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' \
	|| c == '\v' || c == '\n' || c == '\f')
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}

void	free_all(t_alloc **alloc)
{
	t_alloc	*tmp;

	if (*alloc)
	{
		while (*alloc != NULL)
		{
			tmp = (*alloc)->next;
			if ((*alloc)->ptr)
				free((*alloc)->ptr);
			free(*alloc);
			*alloc = tmp;
		}
	}
}
