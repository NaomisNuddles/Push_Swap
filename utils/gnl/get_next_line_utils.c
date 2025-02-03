/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:34 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:33:10 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*line_pull(char *buff, size_t len)
{
	char	*str;

	if (!len)
		len = ft_strlen(buff);
	str = ft_calloc(1, len + 1);
	if (!str)
		return (NULL);
	ft_memmove(str, buff, len);
	ft_memmove(buff, &buff[len], ft_strlen(buff) - len);
	ft_memset(&buff[ft_strlen(buff) - len], 0, len);
	return (str);
}

size_t	line_check(char *buff)
{
	size_t	n;

	n = 0;
	if (!buff || !*buff)
		return (0);
	while (buff[n] && buff[n] != '\n')
		n++;
	if (buff[n] != '\n')
		return (0);
	return (n + 1);
}

char	*buff_save(char *buff, char *lag)
{
	char	*str;

	str = ft_calloc(1, ft_strlen(buff) + ft_strlen(lag) + 1);
	if (!str)
		return (free(buff), NULL);
	ft_memmove(str, buff, ft_strlen(buff));
	ft_memmove(&str[ft_strlen(buff)], lag, ft_strlen(lag));
	ft_memset(lag, 0, BUFFER_SIZE);
	return (free(buff), str);
}
