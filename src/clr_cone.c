/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:52:10 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/05 16:37:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Solution of пересечения прямой and cone
** сводится к solution of quadratic equation
** with коэффицентами
** a = < D ; D > - < D ; V > * < D ; V > * ( k * k + 1 )
** b = 2 * ( < D ; O - C > - ( k * k + 1 ) * < D ; V > * < O - C ; V >
** c = < O - C ; O - C > - ( k * k + 1 ) * < O - C ; V > * < O - C ; V >
** where:
** C - cone's vertex
** V - cone's vector axis
** k - tangent half angle
** O - view point
** D - vector of view
*/

int					clr_cone(t_obj *cam, t_obj *current_obj, t_ray *ray,
															float roots[2])
{
	t_cone			*cone;
	float			coefficient_quadratic_equation[3];
	float			o_c[3];
	float			tmp;

	cone = current_obj->shape;
	subtraction_point((float *)cam->shape, cone->vertex, o_c);
	tmp = dot_product(ray->d, cone->axis);
	coefficient_quadratic_equation[0] = dot_product(ray->d, ray->d) -
					(tmp * tmp) * (cone->angle * cone->angle + 1);
	tmp = dot_product(o_c, cone->axis) *
						dot_product(ray->d, cone->axis);
	coefficient_quadratic_equation[1] = 2 * (dot_product(ray->d, o_c) -
							tmp * (cone->angle * cone->angle + 1));
	tmp = dot_product(o_c, cone->axis);
	coefficient_quadratic_equation[2] =
		dot_product(o_c, o_c) -
			((tmp * tmp) * (cone->angle * cone->angle + 1));
	if (roots_quadratic_equation(coefficient_quadratic_equation[0],
								coefficient_quadratic_equation[1],
								coefficient_quadratic_equation[2],
								roots) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
