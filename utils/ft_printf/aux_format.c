/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:45:41 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:32:05 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	find_format(t_data *data)
{
	if (data->str[data->index] != '%' || (data->str[data->index] == '%' && \
		data->str[data->index + 1] == '%'))
	{
		ft_putchar_fd(data->str[data->index], 1);
		data->len++;
		if (data->str[data->index] == '%')
			data->index++;
	}
	else if (data->str[data->index] == '%')
	{
		data->format->format = true;
		while (data->format->flags == EMPTY && ++data->index)
			flags_check(data->str[data->index], data);
		if (ft_isdigit(data->str[data->index]))
			data->format->width = ft_atoi(&data->str[data->index]);
		while (ft_isdigit(data->str[data->index]))
			data->index++;
		if (data->str[data->index] == '.' && ++data->index)
			data->format->precision = ft_atoi(&data->str[data->index]);
		while (ft_isdigit(data->str[data->index]))
			data->index++;
		type_check(data->str[data->index], data);
	}
}

void	construct_format(t_data	*data)
{
	type_build(data);
	if (data->format->type == CHAR || data->format->type == STR)
		data->format->precision = -1;
	else if ((size_t)data->format->precision < \
	ft_strlen(data->format->arg->str))
		data->format->precision = -1;
	else if (data->format->precision > 0)
		precision_build(data);
	if ((size_t)data->format->width < ft_strlen(data->format->arg->str) + \
	ft_strlen(data->format->arg->at_s) + ft_strlen(data->format->arg->prc))
		data->format->width = 0;
	else if (data->format->width > 0)
		width_build(data);
}

void	print_format(t_data *data)
{
	data->len += (int)(ft_strlen(data->format->arg->at_s) + \
	ft_strlen(data->format->arg->str) + ft_strlen(data->format->arg->extra) + \
	ft_strlen(data->format->arg->prc));
	if (data->format->zero == false && data->format->neg == false)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->at_s, 1);
	if (data->format->zero == true)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->prc, 1);
	if (data->format->type == CHAR && !data->format->arg->str[0] && ++data->len)
		write(1, "\0", 1);
	else
		ft_putstr_fd(data->format->arg->str, 1);
	if (data->format->neg == true)
		ft_putstr_fd(data->format->arg->extra, 1);
}
