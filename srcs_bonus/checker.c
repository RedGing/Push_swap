/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:31:10 by femorell          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	input_cmd(t_vars *vars, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		sa(vars->stack_a);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		sb(vars->stack_b);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ss(vars->stack_a, vars->stack_b);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		pa(vars->stack_a, vars->stack_b, &vars->alloc);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		pb(vars->stack_a, vars->stack_b, &vars->alloc);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ra(vars->stack_a, &vars->alloc);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		rb(vars->stack_b, &vars->alloc);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		rr(vars->stack_a, vars->stack_b, &vars->alloc);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		rra(vars->stack_a, &vars->alloc);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		rrb(vars->stack_b, &vars->alloc);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		rrr(vars->stack_a, vars->stack_b, &vars->alloc);
	else
		print_error(&vars->alloc);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*str;

	vars.alloc = NULL;
	vars.stack_a = init_stack(&vars.alloc);
	vars.stack_b = init_stack(&vars.alloc);
	parsing(av, &vars.stack_a, &vars.alloc);
	if (ac < 2)
	{
		free_all(&vars.alloc);
		return (0);
	}
	while (1)
	{
		str = get_next_line(0, vars.alloc);
		if (!str)
			break ;
		input_cmd(&vars, str);
	}
	if (is_sorted(&vars.stack_a, vars.stack_a->size) && vars.stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_all(&vars.alloc);
}
