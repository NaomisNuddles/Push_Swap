/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/03 15:41:26 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_log(char	*err)
{
	ft_printf(">	%s\n", err);
	if (ft_strncmp("Er01", err, 4))
		write(2, "error", 5);
}

int	atoi_unlim(const char *src)
{
	int	n;
	int	val;

	n = 1;
	val = 0;
	if (!src)
		return (0);
	while ((*src >= 9 && *src <= 13) || *src == 32)
		src++;
	if (*src == 45)
		n = -1;
	while (*src == 45 || *src == 43)
		src++;
	while(*src == 48)
		src++;
	while (*src >= 48 && *src <= 57)
		val = val * 10 + (-48 + *src++);
	return (val * n);
}
