/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:44:15 by dtreutel          #+#    #+#             */
/*   Updated: 2019/07/30 16:47:20 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_add_line(int fd, char **get_line)
{
	char *buff;
	char *save;

	if (!(buff = ft_strnew(BUFF_SIZE)))
	{
		free(get_line[fd]);
		get_line[fd] = 0;
		return (0);
	}
	save = get_line[fd];
	while (!ft_strchr(save, '\n') && read(fd, buff, BUFF_SIZE))
	{
		if (!(get_line[fd] = ft_strjoin(save, buff)))
		{
			free(get_line[fd]);
			get_line[fd] = 0;
			free(buff);
			return (0);
		}
		free(save);
		save = get_line[fd];
		ft_bzero(buff, BUFF_SIZE);
	}
	free(buff);
	return (1);
}

int		get_new_line(int fd, char **get_line)
{
	if (!(get_line[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (read(fd, get_line[fd], BUFF_SIZE) <= 0)
	{
		free(get_line[fd]);
		get_line[fd] = 0;
		return (read(fd, get_line[fd], BUFF_SIZE));
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *get_line[10240];
	char		*save;

	if (!line || fd < 0 || fd > 10240)
		return (-1);
	if (!get_line[fd])
		if (get_new_line(fd, get_line) <= 0)
			return (get_new_line(fd, get_line));
	if (!ft_strchr(get_line[fd], '\n'))
		if (!(get_add_line(fd, get_line)))
			return (-1);
	*line = get_line[fd];
	if ((save = ft_strchr(*line, '\n')))
	{
		*save++ = '\0';
		if (!*save)
			get_line[fd] = 0;
		else
			get_line[fd] = ft_strdup(save);
	}
	else
		get_line[fd] = 0;
	return (1);
}
