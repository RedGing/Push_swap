/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:21:56 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:02:59 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_tmp;

	i = 0;
	s_tmp = (unsigned char *)s;
	while (i < n)
	{
		if (s_tmp[i] == (unsigned char)c)
			return (s_tmp + i);
		i++;
	}
	return (NULL);
}
