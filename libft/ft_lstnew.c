/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:55:39 by dasereno          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:57 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, t_alloc *alloc)
{
	t_list	*li;

	li = ft_malloc(sizeof(*li), &alloc);
	if (!li)
		return (NULL);
	li->content = content;
	li->next = NULL;
	return (li);
}
