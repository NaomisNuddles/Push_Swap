/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:35 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:50:39 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i >= n || !dst || !src)
		return (n + ft_strlen(src));
	while (i < n - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (i - j + ft_strlen(src));
}
