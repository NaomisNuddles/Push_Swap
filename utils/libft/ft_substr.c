/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:17 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 21:10:46 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *src, unsigned int frt, size_t n)
{
	char	*str;

	if (!src)
		return (0);
	if (!n || frt >= ft_strlen(src))
		return (ft_calloc(1, 1));
	else if (n > ft_strlen(src) - frt)
		n = ft_strlen(src) - frt;
	str = ft_calloc(1, n + 1);
	if (str)
		ft_memmove(str, &src[frt], n);
	return (str);
}
