/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:01:07 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/30 18:12:49 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_format(t_data *data)
{
	data->format->type = NONE;
	data->format->flags = EMPTY;
	data->format->format = false;
	data->format->pos = false;
	data->format->neg = false;
	data->format->space = false;
	data->format->zero = false;
	data->format->quote = false;
	data->format->hash = false;
	data->format->precision = -1;
	data->format->width = 0;
	data->format->base = NULL;
	data->format->arg->extra = NULL;
	data->format->arg->at_s = NULL;
	data->format->arg->prc = NULL;
	data->format->arg->str = NULL;
}

t_data	*set_data(const char *str)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->format = malloc(sizeof(t_format));
	if (!data->format)
	{
		free(data);
		return (NULL);
	}
	data->format->arg = malloc(sizeof(t_arg));
	if (!data->format->arg)
	{
		free(data->format);
		free(data);
		return (NULL);
	}
	data->len = 0;
	data->index = 0;
	data->str = str;
	null_format(data);
	return (data);
}

void	reset_data(t_data *data)
{
	if (data->format->width)
		free(data->format->arg->extra);
	if (data->format->precision > 0)
		free(data->format->arg->prc);
	if (data->format->type != NONE)
		free(data->format->arg->str);
	null_format(data);
}

void	free_data(t_data *data)
{
	free(data->format->arg);
	free(data->format);
	free(data);
}
