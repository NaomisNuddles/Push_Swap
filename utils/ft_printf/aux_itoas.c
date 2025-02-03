/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_itoas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:19:52 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:32:09 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*uns_itoa_base(unsigned int val, char *base)
{
	char			*str;
	size_t			i;
	unsigned int	n;

	i = 0;
	n = val;
	while (n && ++i)
		n /= ft_strlen(base);
	if (val == 0)
		i = 1;
	str = ft_calloc(1, i + 1);
	while (str && i--)
	{
		str[i] = base[val % ft_strlen(base)];
		val /= ft_strlen(base);
	}
	return (str);
}

char	*unsl_itoa_base(unsigned long val, char *base)
{
	char				*str;
	size_t				i;
	unsigned long		n;

	i = 0;
	n = val;
	while (n && ++i)
		n /= ft_strlen(base);
	str = ft_calloc(1, i + 1);
	while (str && i--)
	{
		str[i] = base[val % ft_strlen(base)];
		val /= ft_strlen(base);
	}
	return (str);
}
