/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:37:00 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/01 09:15:59 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		*new_obj(t_obj **obj)
{
	t_obj	*new;
	t_obj	*save;

	if (!(new = ft_memalloc(sizeof(*new))))
		perror("new_obj");
	if (!obj[0])
		obj[0] = new;
	else
	{
		save = obj[0];
		while (save->next)
			save = save->next;
		save->next = new;
	}
	return (new);
}
