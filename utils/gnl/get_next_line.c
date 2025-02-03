/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:40 by nleandro          #+#    #+#             */
/*   Updataed: 2024/12/31 23:39:17 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	data;
	char			*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	data.size = read(fd, data.lag, BUFFER_SIZE);
	res = NULL;
	while (data.size > 0 || (!data.size && data.buff[fd] && *data.buff[fd]))
	{
		if (data.size)
			data.buff[fd] = buff_save(data.buff[fd], data.lag);
		if (!data.buff[fd] && data.size)
			return (NULL);
		if (line_check(data.buff[fd]) || !data.size)
		{
			res = line_pull(data.buff[fd], line_check(data.buff[fd]));
			if (!res)
				break ;
			return (res);
		}
		data.size = read(fd, data.lag, BUFFER_SIZE);
	}
	free(data.buff[fd]);
	data.buff[fd] = NULL;
	return (NULL);
}
