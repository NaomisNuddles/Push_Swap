/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:42:46 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 19:44:59 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (src && dst && src < dst && n <= ((size_t)1 << 63) - 1 && n-- > 0)
		*((char *)dst + n) = *((char *)src + n);
	while (src && dst && src > dst && n <= ((size_t)1 << 63) - 1 && n-- > 0)
		*((char *)dst + i - n) = *((char *)src + i - n);
	return (dst);
}
