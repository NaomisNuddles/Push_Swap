/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:56 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:46:16 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = ft_calloc(1, ft_strlen(src) + 1);
	if (!dst)
		return (0);
	ft_memmove(dst, src, ft_strlen(src) + 1);
	return (dst);
}
