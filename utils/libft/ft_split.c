/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:22:06 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 21:44:29 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_split(const char *src, char c)
{
	size_t	i;
	size_t	l;
	char	**res;

	i = 0;
	l = ft_strlen(src);
	while (src && *src)
	{
		if (*src && *src++ != c && (*src == c || !*src))
			i++;
	}
	res = ft_calloc(8, i + 1);
	while (res && src && i-- && src--)
	{
		while (((*src != c && *(src - 1) != c) || *src == c) \
		&& ft_strlen(src) < l)
			src--;
		*(res + i) = ft_substr(src, 0, ft_strchr(src, c) - src);
		if (*(res + i))
			continue ;
		while (++i && *(res + i))
			free(*(res + i));
		return (free(res), NULL);
	}
	return (res);
}
