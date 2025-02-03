/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:34 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:54:07 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	while (src1 && src2 && n <= ((size_t)1 << 63) - 1 && n-- > 0)
	{
		if (*(unsigned char *)src1++ != *(unsigned char *)src2++)
			return (*(unsigned char *)--src1 - *(unsigned char *)--src2);
	}
	return (0);
}
