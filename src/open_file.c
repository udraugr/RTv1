/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:16:45 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/15 12:17:11 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			open_file(char *str)
{
	int			fd;
	char		a[1];

	fd = open(str, O_RDONLY);
	if (read(fd, a, 0) == -1)
	{
		fd = 0;
		perror("Open file");
	}
	return (fd);
}
