/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:13:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/11 20:38:24 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** t = (-1 * < O - C ; V >) / < D ; V >
** where:
** C - dot on plane
** V - normal of plane
** O - point of view
** D - vector of view
**
** if (< D ; V > == 0)
**		roots not exist (plane parallel of vector of view)
*/

int				clr_plane(t_obj *cam, t_obj *current_obj, t_ray *ray,
															float roots[2])
{
	float		root;
	float		delitel;
	float		o_c[3];
	t_plane		*plane;

	plane = (t_plane *)current_obj->shape;
	delitel = dot_product(ray->d, plane->normal);
	subtraction_point((float *)cam->shape, plane->dot, o_c);
	if (fabs(delitel) < 0.0001 || (
		(dot_product(ray->d, plane->normal) < 0.0 &&
			dot_product(o_c, plane->normal) < 0.0) ||
		(dot_product(ray->d, plane->normal) > 0.0 &&
			dot_product(o_c, plane->normal) > 0.0)))
		return (FAIL);
	root = -1.0 * dot_product(o_c, plane->normal);
	root /= delitel;
	roots[0] = root;
	roots[1] = root;
	return (SUCCESS);
}
