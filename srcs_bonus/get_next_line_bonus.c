/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <femorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:38:01 by femorell          #+#    #+#             */
/*   Updated: 2023/04/28 15:07:43 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#define BUFFER_SIZE 42

static char	*get_line(char *temp, char *buf, t_alloc **alloc)
{
	char	*newbuf;

	newbuf = ft_strjoin(temp, buf, alloc);
	return (newbuf);
}

static char	*get_first_line(int fd, char *temp, t_alloc *alloc)
{
	int		i;
	char	*buf;

	if (temp == 0)
		temp = ft_calloc(1, 1, alloc);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char), alloc);
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(temp, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (0);
		buf[i] = '\0';
		temp = get_line(temp, buf, &alloc);
	}
	return (temp);
}

static char	*get_return(char *temp, t_alloc *alloc)
{
	int		i;
	char	*str;

	i = 0;
	if (!temp[i])
		return (0);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	str = ft_calloc(i + 1, sizeof(char), alloc);
	i = 0;
	while (temp[i] != '\n' && temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_leftover(char *temp, t_alloc *alloc)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
		return (0);
	str = ft_calloc((ft_strlen(temp) - i + 1), sizeof(char), alloc);
	i++;
	while (temp[i])
	{
		str[y] = temp[i];
		y++;
		i++;
	}
	return (str);
}

char	*get_next_line(int fd, t_alloc *alloc)
{
	static char	*temp[4096];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp[fd] = get_first_line(fd, temp[fd], alloc);
	ret = get_return(temp[fd], alloc);
	temp[fd] = ft_leftover(temp[fd], alloc);
	return (ret);
}
