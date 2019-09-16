/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_with_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:29:41 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 20:46:19 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			multiplication_point(float first_point[3], float k,
											float destination[3])
{
	destination[0] = first_point[0] * k;
	destination[1] = first_point[1] * k;
	destination[2] = first_point[2] * k;
}

void			addition_point(float first_point[3], float second_point[3],
									float destination[3])
{
	destination[0] = first_point[0] + second_point[0];
	destination[1] = first_point[1] + second_point[1];
	destination[2] = first_point[2] + second_point[2];
}

void			subtraction_point(float first_point[3], float second_point[3],
									float destination[3])
{
	destination[0] = first_point[0] - second_point[0];
	destination[1] = first_point[1] - second_point[1];
	destination[2] = first_point[2] - second_point[2];
}
