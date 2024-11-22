/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:59:54 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:14 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}
