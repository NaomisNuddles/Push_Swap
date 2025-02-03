/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_aux_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/03 15:30:47 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	arg_issplit(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] && arg[i] != 32)
		i++;
	if (arg[i] == 32)
		return (true);
	return (false);
}

bool	arg_isneg(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] && arg[i] == 45)
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (i != ft_strlen(arg))
		return (false);
	return (true);
}

bool	arg_ispos(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] && arg[i] == 43)
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (i != ft_strlen(arg))
		return (false);
	return (true);
}

bool	arg_isvalid(char *arg)
{
	if (!arg_ispos(arg) && !arg_isneg(arg))
		return (error_log("Er04"), false);
	else if (arg_ispos(arg) || arg_isneg(arg))
		return(true);
	return (error_log("Er04"), false);
}
