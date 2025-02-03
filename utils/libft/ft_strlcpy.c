/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:20 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:50:41 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src || !dst || !n)
		return (ft_strlen(src));
	while (i < n - 1 && src[i] && ++i)
		dst[i - 1] = src[i - 1];
	dst[i] = 0;
	return (ft_strlen(src));
}
