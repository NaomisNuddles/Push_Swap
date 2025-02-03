/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/03 15:30:54 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	arg_pop(char *arg, t_stk *stk)
{
	int	i;
	int	num;

	i = 0;
	num = atoi_unlim(arg);
	while (i <= stk->top)
	{
		if (num == stk->stk[i])
			return (error_log("Er05"), false);
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
