/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/18 16:26:21 by nleandro         ###   ########.fr       */
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

bool	arg_isvalid(char *arg)
{
	size_t	i;

	i = 0;
	if (arg[i] && (arg[i] == 45 || arg[i] == 43) && arg[i + 1] != 48)
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (i != ft_strlen(arg))
		return (error_log("Er04"), false);
	if (!arg || !arg[0])
		return (error_log("Er07"), false);
	return (true);
}

bool	arg_pop(char *arg, t_stk *stk)
{
	int		i;
	int		num;
	long	num_c;

	i = 0;
	num = ft_atoi(arg);
	num_c = ft_atol(arg);
	if ((long)num != num_c)
	return (error_log("Er05"), false);
	while (i <= stk->top)
	{
		if (num == stk->stk[i])
			return (error_log("Er06"), false);
		i++;
	}
	stk_push(stk, num);
	return (true);
}

bool	args_pick(int cnt, char **args, t_stk *stk)
{
	size_t	i;
	char	**mtx;

	while (--cnt && args[cnt])
	{
		if (arg_issplit(args[cnt]))
		{
			mtx = ft_split(args[cnt], 32);
			i = ft_mtxlen(mtx);
			while (i-- && mtx[i])
			{
				if (!arg_isvalid(mtx[i]) || !arg_pop(mtx[i], stk))
					return (ft_mtx_free(mtx), false);
			}
			ft_mtx_free(mtx);
		}
		else if (!arg_isvalid(args[cnt]) || !arg_pop(args[cnt], stk))
			return (false);
	}
	return (true);
}
