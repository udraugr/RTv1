/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:10:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/15 11:26:06 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		fill_new_cam_and_new_ray(t_obj *cam, t_ray *ray_p_light,
									t_ray *ray, t_light *light)
{
	cam->shape = (void *)ray->p;
	cam->type = ray->obj->type;
	if (light->type == 1)
	{
		subtraction_point(light->center, ray->p, ray_p_light->d);
		ray_p_light->t = len_vector(ray_p_light->d);
		multiplication_point(ray_p_light->d,
						1.0 / ray_p_light->t, ray_p_light->d);
	}
	else if (light->type == 2)
	{
		multiplication_point(light->vector, -1.0, ray_p_light->d);
		multiplication_point(ray_p_light->d,
						1.0 / len_vector(ray_p_light->d), ray_p_light->d);
	}
}

static int		check_roots(t_light *light, float roots[2], t_ray ray_p_light)
{
	if (roots[0] > 0.00001 &&
			((light->type == 1 && roots[0] < ray_p_light.t) ||
			(light->type == 2)))
		return (FAIL);
	if (roots[1] > 0.00001 &&
			((light->type == 1 && roots[1] < ray_p_light.t) ||
			(light->type == 2)))
		return (FAIL);
	return (SUCCESS);
}

int				calc_intersetion(t_obj *cam, t_obj *current_obj,
									t_ray *ray_p_light, float roots[2])
{
	int			result;

	result = FAIL;
	if (current_obj->type == SPHERE)
		result = clr_sphere(cam, current_obj, ray_p_light, roots);
	else if (current_obj->type == PLANE)
		result = clr_plane(cam, current_obj, ray_p_light, roots);
	else if (current_obj->type == CYLINDER)
		result = clr_cylinder(cam, current_obj, ray_p_light, roots);
	else if (current_obj->type == CONE)
		result = clr_cone(cam, current_obj, ray_p_light, roots);
	return (result);
}

int				check_shadow(t_rt *rt, t_ray *ray, t_light *light)
{
	t_obj		cam;
	t_ray		ray_p_light;
	t_obj		*current_obj;
	float		roots[2];

	current_obj = rt->obj;
	ft_bzero((void *)&cam, sizeof(t_obj));
	ft_bzero((void *)&ray_p_light, sizeof(t_ray));
	fill_new_cam_and_new_ray(&cam, &ray_p_light, ray, light);
	while (current_obj->next)
	{
		current_obj = current_obj->next;
		if (current_obj != ray->obj)
		{
			if (calc_intersetion(&cam, current_obj,
								&ray_p_light, roots) == SUCCESS &&
					check_roots(light, roots, ray_p_light) == FAIL)
				return (FAIL);
		}
	}
	return (SUCCESS);
}
