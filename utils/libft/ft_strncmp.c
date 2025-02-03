/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:03 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:56:50 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *src1, const char *src2, size_t n)
{
	while (src1 && src2 && n-- > 0 && (*src1 || *src2))
	{
		if (src1++ && src2++ && (unsigned char)*(src1 - 1) != \
		(unsigned char)*(src2 - 1))
			return ((unsigned char)*(src1 - 1) - (unsigned char)*(src2 - 1));
	}
	return (0);
}
