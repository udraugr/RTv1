/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:31:10 by mwuckert          #+#    #+#             */
/*   Updated: 2019/02/11 18:38:37 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *save;

	while (lst && f)
	{
		if (!(new = f(lst)))
			return (0);
		save = new;
		while ((*lst).next)
		{
			lst = (*lst).next;
			if (!((*new).next = f(lst)))
			{
				ft_lstdel(&new, &ft_lstdelcontent);
				return (0);
			}
			new = (*new).next;
		}
		lst = (*lst).next;
	}
	return (save);
}
