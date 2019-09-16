/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:31:51 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/15 11:51:46 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			valid_geometry(int type, void *shape)
{
	t_sphere	*sphere;
	t_cone		*cone;
	t_cylinder	*cylinder;

	if (type == SPHERE)
	{
		sphere = (t_sphere *)shape;
		if (sphere->radius <= 0)
			return (0);
	}
	if (type == CONE)
	{
		cone = (t_cone *)shape;
		if (cone->angle <= 0)
			return (0);
	}
	if (type == CYLINDER)
	{
		cylinder = (t_cylinder *)shape;
		if (cylinder->radius <= 0)
			return (0);
	}
	return (1);
}

static int			valid_shape(t_obj *shape)
{
	while (shape != 0)
	{
		if (shape->clr < 30 && shape->type != CAMERA)
			return (0);
		if (shape->type == SPHERE || shape->type == CONE ||
											shape->type == CYLINDER)
			if (!valid_geometry(shape->type, shape->shape))
				return (0);
		shape = shape->next;
	}
	return (1);
}

static int			valid_light(t_obj *light)
{
	t_light	*cur_light;

	if (light == 0)
		return (0);
	while (light != 0)
	{
		cur_light = (t_light *)light->shape;
		if (cur_light->intensive < 0.1 || cur_light->intensive > 0.9)
			return (0);
		if (cur_light->type == 2)
		{
			if (cur_light->vector[0] == 0 && cur_light->vector[1] == 0 &&
				cur_light->vector[2] == 0)
				return (0);
			else
				multiplication_point(cur_light->vector, 1.0 /
					len_vector(cur_light->vector), cur_light->vector);
		}
		light = light->next;
	}
	return (1);
}

int					valid_data(t_rt *rt)
{
	if (rt->obj == 0 || rt->obj->next == 0)
		return (0);
	if (!valid_shape(rt->obj->next))
		return (0);
	if (!valid_light(rt->light))
		return (0);
	return (1);
}
