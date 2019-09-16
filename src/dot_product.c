/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:41:33 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/31 16:28:56 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float				dot_product(float first_point[3], float second_point[3])
{
	float			ans;

	ans = first_point[0] * second_point[0];
	ans += first_point[1] * second_point[1];
	ans += first_point[2] * second_point[2];
	return (ans);
}
