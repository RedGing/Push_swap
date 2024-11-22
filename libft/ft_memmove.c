/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:49:54 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:02 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_tmp;
	char	*dest_tmp;
	size_t	i;

	src_tmp = (char *)src;
	dest_tmp = (char *)dest;
	i = 0;
	if (dest_tmp > src_tmp)
	{
		while (n-- > 0)
			dest_tmp[n] = src_tmp[n];
	}
	else
	{
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}
