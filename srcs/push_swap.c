/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:31:10 by femorell          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:47 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_vars	*tmp;

	vars.alloc = NULL;
	vars.stack_a = init_stack(&vars.alloc);
	vars.stack_b = init_stack(&vars.alloc);
	parsing(av, &vars.stack_a, &vars.alloc);
	if (ac < 2 || is_sorted(&vars.stack_a, vars.stack_a->size))
	{
		free_all(&vars.alloc);
		return (0);
	}
	tmp = &vars;
	a_to_b(&tmp, vars.stack_a->size);
	free_all(&vars.alloc);
}
