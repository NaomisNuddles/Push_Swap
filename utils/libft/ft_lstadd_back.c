/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:25:47 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:37:33 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*crt;

	if (lst)
	{
		crt = *lst;
		if (!*lst)
			*lst = new;
		else
		{
			while (crt->next)
				crt = crt->next;
			crt->next = new;
		}
	}
}
