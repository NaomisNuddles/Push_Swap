/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:23:08 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/13 18:23:08 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *src)
{
	long	n;
	long	val;

	n = 1;
	val = 0;
	if (!src)
		return (0);
	while ((*src >= 9 && *src <= 13) || *src == 32)
		src++;
	if (*src == 45 || *src == 43)
		n = 44 - *src++;
	while (*src >= 48 && *src <= 57)
		val = val * 10 + (-48 + *src++);
	return (val * n);
}
