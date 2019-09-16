/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:18:43 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/15 12:35:36 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_exit(t_rt *rt)
{
	if (rt->win_ptr)
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
	if (rt->img_ptr)
		mlx_destroy_image(rt->mlx_ptr, rt->img_ptr);
	if (rt->obj)
		dell_all_obj(&rt->obj);
	if (rt->light)
		dell_all_obj(&rt->light);
	exit(0);
	return (0);
}
