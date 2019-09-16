/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:53:40 by mwuckert          #+#    #+#             */
/*   Updated: 2019/02/11 18:38:37 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	nb;
	int sign;
	int i;

	i = 0;
	nb = 0;
	sign = 1;
	while ((*str >= '\a' && *str <= '\r') || *str == ' ' || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - '0';
		i++;
	}
	if (i < 20)
		return (nb * sign);
	else if (sign == -1)
		return (0);
	return (-1);
}
