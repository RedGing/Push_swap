/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:36:53 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:13 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char),
	t_alloc *alloc)
{
	int		i;
	char	*new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new = ft_malloc(sizeof(char) * (ft_strlen(s) + 1), &alloc);
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
