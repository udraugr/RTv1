/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_intersection_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:11:45 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/11 20:37:39 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**- N = (< D ; V > ) < 0 ? -V : V - нормаль - вектор перпендикулярныйповерхности
**- поверхности на котоорую попал луч от точки зрения
**- (< D ; V >) - скалярное произведение луча падающего на плоскость D (ray->d)
**- и нормали плоскости заданной в сцене V (plane->normal)
**- Если скалярное произведение больше нуля, то заданная в сцене нормаль
**- направлена от зрителя и ее нужно развернуть (умножить на -1.0)
*/

static void	normal_plane(t_ray *ray)
{
	float	dot_prod;
	t_plane	*plane;

	plane = ray->obj->shape;
	dot_prod = dot_product(ray->d, plane->normal);
	if (dot_prod < 0.0)
		multiplication_point(plane->normal, 1.0, ray->normal);
	else
		multiplication_point(plane->normal, -1.0, ray->normal);
}

/*
**- N = norm(P - C) : нормаль - вектор перпендикулярный поверхности на котоорую
**- попал луч от точки зрения (Для дяди Серёжи N = (P - C)/ len_vector(C_P))
**- P (ray->p) - точкa пересечения луча с поверхностью сферы
**- С (center_sphere) - координаты центра сферы
**- P = O + D * t : параметрическое уравнение прямой, где Р точка на прямой,
**- 	О(cam->shape) - коордиаты точки зрения
**		D(ray->d) - вектор взгляда
**- 	t(ray->t) - переменная
*/

static void	normal_sphere(t_ray *ray)
{
	float		*center_sphere;
	t_sphere	*sphere;
	float		d_t[3];
	float		c_p[3];

	sphere = (t_sphere *)ray->obj->shape;
	center_sphere = sphere->center;
	multiplication_point(ray->d, ray->t, d_t);
	subtraction_point(ray->p, sphere->center, c_p);
	multiplication_point(c_p, 1.0 / len_vector(c_p), ray->normal);
}

/*
**- N = norm(P - C + V * m) : нормаль - вектор перпендикулярный поверхности
**- на котоорую попал луч от точки зрения
**- P (p[3]) - точкa пересечения луча с поверхностью цилиндра
**- С (cylinder->start) - координаты основания цилиндра
**- P = O + D * t : параметрическое уравнение прямой, где Р точка на прямой,
**- 	О(cam->shape) - коордиаты точки зрения
**		D(ray->d) - вектор взгляда
**-		t(ray->t) - переменная
**- V (cylinder->axis) - вектор оси цилиндра
**- m (m)- переменная(растояние от точки С до точки A)
**-
**-		. N->				*C
**-			.   	/	    /   	}
**-				.  /	   /V->	   }m
**- О*------------*P	  		  }
**-				 /		 *A		}
**-				/		/
**-			   /	   / - ось цилиндра
**-			  / - поверхность на которую падает луч
**-
**- m = sqrt(pow(CP) - pow(AP)) т.к. нормаль перпендикулярна оси
**-	цилиндра находим длинну ктатета AC по теореме пифагора
**-	CP - длинна вектора из точки С в точку Р
**-	AP - кратчайшее растояние от оси к точке пересечения луча с
**-		плоскостью цилиндра является радиусом цилиндра (cylinder->radius)
**-
**-
*/

static void	normal_cylinder(t_ray *ray, t_obj *cam)
{
	float		c_p[3];
	t_cylinder	*cylinder;
	float		m;
	float		camera[3];
	float		o_c[3];

	cylinder = ray->obj->shape;
	subtraction_point(ray->p, cylinder->start, c_p);
	multiplication_point((float *)cam->shape, 1.0, camera);
	subtraction_point(camera, cylinder->start, o_c);
	m = dot_product(ray->d, cylinder->axis) * ray->t +
							dot_product(o_c, cylinder->axis);
	multiplication_point(cylinder->axis, -m, ray->normal);
	addition_point(c_p, ray->normal, ray->normal);
	multiplication_point(ray->normal, 1.0 / len_vector(ray->normal),
						ray->normal);
}

static void	normal_cone(t_ray *ray, t_obj *cam)
{
	float		c_p[3];
	t_cone		*cone;
	float		m;
	float		camera[3];
	float		o_c[3];

	cone = ray->obj->shape;
	subtraction_point(ray->p, cone->vertex, c_p);
	multiplication_point((float *)cam->shape, 1.0, camera);
	subtraction_point(camera, cone->vertex, o_c);
	m = dot_product(ray->d, cone->axis) * ray->t +
							dot_product(o_c, cone->axis);
	multiplication_point(cone->axis, -m * (1 + cone->angle * cone->angle),
		ray->normal);
	addition_point(c_p, ray->normal, ray->normal);
	multiplication_point(ray->normal, 1.0 / len_vector(ray->normal),
						ray->normal);
}

void		normal_intersection_dot(t_ray *ray, t_obj *cam)
{
	if (ray->obj->type == PLANE)
		normal_plane(ray);
	else if (ray->obj->type == SPHERE)
		normal_sphere(ray);
	else if (ray->obj->type == CYLINDER)
		normal_cylinder(ray, cam);
	else if (ray->obj->type == CONE)
		normal_cone(ray, cam);
}
