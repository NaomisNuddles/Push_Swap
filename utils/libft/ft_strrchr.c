/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:50:14 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:43:20 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *src, int c)
{
	while (src && (*src || (!*src && !(char)c)))
	{
		if (!*src || (ft_strchr(src, c) && !ft_strchr((src + 1), c)))
			return (ft_strchr(src, c));
		src++;
	}
	return (0);
}
