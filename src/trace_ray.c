/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:44:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/14 12:48:21 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		object_patrol(t_rt *rt, t_ray *ray)
{
	t_obj	*cam;
	t_obj	*obj;
	float	roots[2];
	int		result;

	cam = rt->obj;
	obj = cam;
	while (obj->next)
	{
		obj = obj->next;
		ft_bzero((void *)roots, sizeof(float) * 2);
		if (obj->type == SPHERE)
			result = clr_sphere(cam, obj, ray, roots);
		else if (obj->type == PLANE)
			result = clr_plane(cam, obj, ray, roots);
		else if (obj->type == CYLINDER)
			result = clr_cylinder(cam, obj, ray, roots);
		else if (obj->type == CONE)
			result = clr_cone(cam, obj, ray, roots);
		if (result == SUCCESS)
			nearest_objects(ray, roots, obj, cam);
	}
}

static int		colr_mod(int clr, float i)
{
	int	rgb[3];

	if (i > 1.0)
		i = 1.0;
	rgb[0] = (clr / 256) / 256 * i;
	rgb[1] = (clr / 256) % 256 * i;
	rgb[2] = clr % 256 * i;
	return (((rgb[0] * 256) + rgb[1]) * 256 + rgb[2]);
}

void			zaryazhay(t_ray *ray, t_rt *rt, int x, int y)
{
	float	*angle;

	angle = (float *)(rt->obj->shape);
	angle += 3;
	ray->clr = BG_CLR;
	ray->d[0] = (float)(x - W / 2.0) * 1.0 / W;
	ray->d[1] = (float)(H / 2.0 - y) * 1.0 / H;
	ray->d[2] = 1.0;
	rotation_on_x(ray->d, angle[0] * M_PI / 180.0, ray->d);
	rotation_on_y(ray->d, angle[1] * M_PI / 180.0, ray->d);
	rotation_on_z(ray->d, angle[2] * M_PI / 180.0, ray->d);
	ray->min_t = 1.0 / (1.0 / len_vector(ray->d));
	multiplication_point(ray->d, 1.0 / len_vector(ray->d), ray->d);
	ray->t = 2147483647.0;
	ray->obj = 0;
}

static void		rays_threads(t_pthread_ray *rays)
{
	t_ray			ray;
	t_rt			*rt;
	int				x;
	int				maxy;
	float			i;

	rt = rays->rt;
	maxy = rays->y + H / 5 + 1;
	while (++rays->y < maxy)
	{
		x = -1;
		while (++x < W)
		{
			zaryazhay(&ray, rt, x, rays->y);
			object_patrol(rt, &ray);
			if (ray.obj)
			{
				i = diffuse_reflection(rt, &ray);
				ray.clr = colr_mod(ray.clr, i);
			}
			rt->img_data[rays->y * W + x] = ray.clr;
		}
	}
}

void			trace_ray(t_rt *rt)
{
	int				i;
	pthread_t		threads[5];
	t_pthread_ray	rays[5];

	i = -1;
	while (++i < 5)
	{
		rays[i].rt = rt;
		rays[i].y = H / 5 * i - 1;
		pthread_create(&threads[i], 0, (void *)rays_threads, (void *)&rays[i]);
	}
	i = -1;
	while (++i < 5)
		pthread_join(threads[i], 0);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}
