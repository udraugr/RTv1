/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dell_all_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:59:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/29 20:14:38 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	dell_all_obj(t_obj **obj)
{
	t_obj	*save;

	if (obj && *obj)
	{
		while ((*obj)->next)
		{
			save = (*obj)->next;
			if (obj[0]->shape != 0)
				ft_memdel((void **)&obj[0]->shape);
			ft_memdel(((void **)&obj[0]));
			obj[0] = save;
		}
		ft_memdel(((void **)&obj[0]));
	}
}
