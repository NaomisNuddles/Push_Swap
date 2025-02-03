/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:32:26 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 12:42:59 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (src && (*src || (!*src && !(char)c)))
	{
		if (*src++ == (char)c)
			return (((char *)src - 1));
	}
	return (0);
}
