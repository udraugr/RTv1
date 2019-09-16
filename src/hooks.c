/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:38:02 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/15 09:47:34 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rotate_camera(int key, float *camera)
{
	if (key == 83)
		camera[0] += 2;
	if (key == 86)
		camera[0] -= 2;
	if (key == 84)
		camera[1] -= 2;
	if (key == 87)
		camera[1] += 2;
	if (key == 85)
		camera[2] -= 2;
	if (key == 88)
		camera[2] += 2;
}

static void	move_camera(int key, float *camera)
{
	if (key == 125)
		camera[1] -= 2;
	if (key == 126)
		camera[1] += 2;
	if (key == 124)
		camera[0] += 2;
	if (key == 123)
		camera[0] -= 2;
	if (key == 121)
		camera[2] -= 2;
	if (key == 116)
		camera[2] += 2;
}

void		hooks(int key, t_rt *rt)
{
	float *camera;

	camera = (float *)rt->obj->shape;
	if ((key >= 123 && key <= 126) || key == 116 || key == 121)
		move_camera(key, camera);
	if (key >= 83 && key <= 88)
		rotate_camera(key, &camera[3]);
	trace_ray(rt);
}
