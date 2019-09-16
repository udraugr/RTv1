/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:23:43 by mwuckert          #+#    #+#             */
/*   Updated: 2019/02/11 18:38:37 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)(ft_memalloc(sizeof(*str) * size + 1))))
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}
