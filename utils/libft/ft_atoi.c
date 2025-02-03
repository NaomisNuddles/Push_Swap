/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:53 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:31:05 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *src)
{
	int	n;
	int	val;

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
