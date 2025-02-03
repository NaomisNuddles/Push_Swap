/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:26 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:36:59 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;

	i = n - 1;
	while (src && n <= ((size_t)1 << 63) - 1 && n-- > 0)
	{
		if (*((unsigned char *)src + i - n) == (unsigned char)c)
			return (((void *)src + i - n));
	}
	return (0);
}
