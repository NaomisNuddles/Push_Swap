/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/25 10:27:31 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

typedef struct s_buffer
{
	char			*buff[MAX_FD];
	char			lag[BUFFER_SIZE + 1];
	ssize_t			size;
}	t_buffer;

//get_next_line_utils.c
char			*line_pull(char *buff, size_t len);
size_t			line_check(char *buff);
char			*buff_save(char *buff, char *lag);

//get_next_line.c
char			*get_next_line(int fd);

#endif //GET_NEXT_LINE_H