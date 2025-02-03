/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:41 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/31 10:31:55 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags_check(char c, t_data *data)
{
	if (c == '+')
		data->format->pos = true;
	else if (c == '-')
		data->format->neg = true;
	else if (c == ' ')
		data->format->space = true;
	else if (c == '0')
		data->format->zero = true;
	else if (c == '\'')
		data->format->quote = true;
	else if (c == '#')
		data->format->hash = true;
	else
		data->format->flags = FILLED;
	if (data->format->pos == true)
		data->format->space = false;
	if (data->format->neg == true)
		data->format->zero = false;
}

void	type_check(char c, t_data *data)
{
	if (c == 'd' || c == 'i')
		data->format->type = INT;
	else if (c == 'c')
		data->format->type = CHAR;
	else if (c == 's')
		data->format->type = STR;
	else if (c == 'p')
		data->format->type = PTR;
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'b')
		data->format->type = UNS;
	else if (c == '%')
		data->format->type = CEN;
	else
		data->format->type = NONE;
	if (c == 'o')
		data->format->base = OCTA;
	else if (c == 'p' || c == 'x')
		data->format->base = HEXMI;
	else if (c == 'X')
		data->format->base = HEXMA;
	else if (c == 'i' || c == 'd' || c == 'u')
		data->format->base = DECA;
	else if (c == 'b')
		data->format->base = BIN;
}
