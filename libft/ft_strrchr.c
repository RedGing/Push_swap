/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:55:30 by darian            #+#    #+#             */
/*   Updated: 2023/04/27 16:03:15 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;

	str = (char *)s + ft_strlen(s);
	while (*str != (unsigned char)c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
