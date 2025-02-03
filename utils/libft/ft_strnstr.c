/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:48 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:58:38 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *src, const char *prb, size_t n)
{
	size_t	i;

	if (!*prb)
		return ((char *)src);
	while (src && prb && *src && n-- > 0)
	{
		i = 0;
		while (*(prb + i) && *(src + i) && *(src + i) == *(prb + i) && n +1 - i)
			i++;
		if (!*(prb + i))
			return (((char *)src));
		src++;
	}
	return (0);
}
