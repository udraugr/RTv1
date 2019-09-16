/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:46:52 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/27 19:48:52 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float				len_vector(float vector[3])
{
	float			ans;

	ans = vector[0] * vector[0];
	ans += vector[1] * vector[1];
	ans += vector[2] * vector[2];
	ans = sqrt(ans);
	return (ans);
}
