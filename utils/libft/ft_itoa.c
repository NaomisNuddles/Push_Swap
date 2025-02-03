/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:25:55 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:37:32 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int val)
{
	size_t	i;
	int		n;
	char	*str;

	i = 0;
	n = val;
	while (n && i++ < 11)
		n /= 10;
	if (val == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (val <= 0)
		i++;
	str = ft_calloc(1, i + 1);
	if (!str)
		return (0);
	ft_memset(str, 48, 1);
	if (val < 0)
		val *= -1;
	while (val && i-- > 0)
	{
		ft_memset(str, 45, 1);
		*(str + i) = val % 10 + 48;
		val /= 10;
	}
	return (str);
}
