/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:03 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:46:05 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *src1, const char *src2)
{
	char	*str;

	if (!src1 && !src2)
		return (0);
	str = ft_calloc(1, (ft_strlen(src1) + ft_strlen(src2) + 1));
	if (!str)
		return (0);
	ft_memmove(str, src1, ft_strlen(src1));
	ft_memmove(&str[ft_strlen(src1)], src2, ft_strlen(src2));
	return (str);
}
