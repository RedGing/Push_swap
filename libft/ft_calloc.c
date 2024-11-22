/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:18 by dasereno          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:43 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size, t_alloc *alloc)
{
	char	*new;

	new = ft_malloc(size * count, &alloc);
	if (!new)
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}
