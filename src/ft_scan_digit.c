/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:44:50 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/28 22:10:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_scan_digit(char **str)
{
	float	res;
	char	*dest;

	res = ft_atof(*str);
	dest = *str;
	while (*dest && !ft_isdigit(*dest))
		dest++;
	while (*dest && ft_isdigit(*dest))
		dest++;
	if (*dest == '.')
	{
		dest++;
		while (*dest && ft_isdigit(*dest))
			dest++;
	}
	while (*dest && !ft_isdigit(*dest) && *dest != '-')
		dest++;
	*str = dest;
	return (res);
}
