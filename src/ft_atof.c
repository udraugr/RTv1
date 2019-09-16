/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:44:11 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/14 12:14:31 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static float	get_hvost(const char *str)
{
	float	float_hvost;
	int		i;

	i = 0;
	float_hvost = (float)ft_atoi(str);
	while (ft_isdigit(*str++))
		i++;
	while (i-- > 1)
		float_hvost /= 10;
	return (float_hvost);
}

float			ft_atof(const char *str)
{
	float	res;
	float	float_hvost;
	int		i;

	i = 0;
	float_hvost = 0;
	res = (float)ft_atoi(str);
	while (*str == '\t' || *str == ' ' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while (ft_isdigit(*str))
		str++;
	if (*str++ == '.' && ft_isdigit(*str))
		float_hvost = get_hvost(str);
	if (res < 0)
		res -= float_hvost / 10;
	else
		res += float_hvost / 10;
	if ((res > 0 && res < 0.9) && i != 0)
		return (res * -1);
	return (res);
}
