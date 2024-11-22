/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:26:45 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:11 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < dstsize)
		len = len + 1;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
		dst[len] = src[len - i];
		len = len + 1;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
