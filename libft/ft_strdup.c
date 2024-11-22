/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:05:04 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:07 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s, t_alloc *alloc)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_malloc(sizeof(char) * (ft_strlen(s) + 1), &alloc);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
