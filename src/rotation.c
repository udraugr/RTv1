/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:19:51 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/15 09:44:09 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rotation_on_z(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;
	float		vector_cpy[3];

	ft_memcpy((void *)vector_cpy, (void *)vector, sizeof(float) * 3);
	x = 0;
	y = 1;
	z = 2;
	destination[x] = cos(angle) * vector_cpy[x] - sin(angle) * vector_cpy[y];
	destination[y] = sin(angle) * vector_cpy[x] + cos(angle) * vector_cpy[y];
	destination[z] = vector_cpy[z];
}

void			rotation_on_x(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;
	float		vector_cpy[3];

	ft_memcpy((void *)vector_cpy, (void *)vector, sizeof(float) * 3);
	x = 0;
	y = 1;
	z = 2;
	destination[x] = vector_cpy[x];
	destination[y] = cos(angle) * vector_cpy[y] - sin(angle) * vector_cpy[z];
	destination[z] = sin(angle) * vector_cpy[y] + cos(angle) * vector_cpy[z];
}

void			rotation_on_y(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;
	float		vector_cpy[3];

	ft_memcpy((void *)vector_cpy, (void *)vector, sizeof(float) * 3);
	x = 0;
	y = 1;
	z = 2;
	destination[x] = cos(angle) * vector_cpy[x] + sin(angle) * vector_cpy[z];
	destination[y] = vector_cpy[y];
	destination[z] = -sin(angle) * vector_cpy[x] + cos(angle) * vector_cpy[z];
}
