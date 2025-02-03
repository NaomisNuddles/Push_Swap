/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:24:47 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:37:25 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*stp;

	res = 0;
	while (lst && f && del)
	{
		stp = f(lst->content);
		if (!stp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		new = ft_lstnew(stp);
		if (!new)
		{
			ft_lstclear(&res, del);
			del(stp);
			return (0);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
