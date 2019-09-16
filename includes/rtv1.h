/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:06:18 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/15 12:46:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "mlx.h"

# include "shapes.h"

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define W 1300
# define H 1300
# define BUFF_SIZE 111
# define BG_CLR 0

# define SUCCESS 0
# define FAIL 1

typedef struct			s_obj
{
	char				type;
	void				*shape;
	int					clr;

	struct s_obj		*next;
}						t_obj;

typedef struct			s_rt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_data;
	t_obj				*obj;
	t_obj				*light;
	int					i;
}						t_rt;

typedef struct			s_ray
{
	float				d[3];
	float				t;
	float				p[3];
	int					clr;
	float				normal[3];
	t_obj				*obj;
	float				min_t;
}						t_ray;

typedef struct			s_pthread_ray
{
	int					y;
	t_rt				*rt;
}						t_pthread_ray;

int						ft_exit(t_rt *rt);
int						valid_data(t_rt *rt);
int						open_file(char *str);
int						pars_scene(char *str, t_rt *rt);
int						set_cone(t_obj **obj, char *gnl);
int						set_plane(t_obj **obj, char *gnl);
int						set_light(t_obj **obj, char *gnl);
int						set_sphere(t_obj **obj, char *gnl);
int						set_cylinder(t_obj **obj, char *gnl);
int						get_next_line(const int fd, char **line);
int						check_shadow(t_rt *rt, t_ray *ray, t_light *light);
int						clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray,
															float roots[2]);
int						clr_cone(t_obj *cam, t_obj *current_obj, t_ray *ray,
															float roots[2]);
int						clr_plane(t_obj *cam, t_obj *current_obj, t_ray *ray,
															float roots[2]);
int						clr_cylinder(t_obj *cam, t_obj *current_obj,
												t_ray *ray, float roots[2]);
int						roots_quadratic_equation(float a, float b, float c,
												float roots[2]);

float					ft_atof(const char *str);
float					ft_scan_digit(char **str);
float					len_vector(float vector[3]);
float					diffuse_reflection(t_rt *rt, t_ray *ray);
float					dot_product(float first_point[3],
									float second_point[3]);

t_obj					*new_obj(t_obj **obj);

void					trace_ray(t_rt *rt);
void					hooks(int key, t_rt *rt);
void					dell_all_obj(t_obj **obj);
void					normal_intersection_dot(t_ray *ray, t_obj *cam);
void					nearest_object(t_ray *ray, float root,
												t_obj *obj, t_obj *cam);
void					nearest_objects(t_ray *ray, float roots[2],
												t_obj *obj, t_obj *cam);
void					multiplication_point(float first_point[3], float k,
											float destination[3]);
void					addition_point(float first_point[3],
									float second_point[3],
									float destination[3]);
void					subtraction_point(float first_point[3],
										float second_point[3],
										float destination[3]);
void					rotation_on_z(float vector[3], float angle,
										float destination[3]);
void					rotation_on_x(float vector[3], float angle,
										float destination[3]);
void					rotation_on_y(float vector[3], float angle,
										float destination[3]);

#endif
