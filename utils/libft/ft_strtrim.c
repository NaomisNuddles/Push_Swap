/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:04:18 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:38:18 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(const char *src, const char *prb)
{
	size_t	i;

	while (src && *src && ft_strchr(prb, *src))
		src++;
	i = ft_strlen(src);
	while (i && ft_strrchr(prb, *((char *)src + i - 1)))
		i--;
	return (ft_substr(src, 0, i));
}
