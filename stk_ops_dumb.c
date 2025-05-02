/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops_dumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/28 18:09:38 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stk_issorted(t_stk *stk)
{
	int	i;

	i = 0;
	while (i < stk->top)
	{
		if (stk->stk[i] < stk->stk[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_stk_swap(t_stk *stk)
{
	int	a;
	int	b;

	if (stk_isempty(stk) || stk->top < 1)
		return (false);
	a = stk_pop(stk);
	b = stk_pop(stk);
	stk_push(stk, a);
	stk_push(stk, b);
	return (true);
}

bool	ft_stk_push(t_stk *stk_src, t_stk *stk_dst)
{
	if (stk_isempty(stk_src) || stk_isfull(stk_dst))
		return (false);
	stk_push(stk_dst, stk_pop(stk_src));
	return (true);
}

bool	ft_stk_cycle(t_stk *stk)
{
	if (stk_isempty(stk) || stk->top < 1)
		return (false);
	stk_push(stk, stk_pop_zed(stk));
	return (true);
}

bool	ft_stk_illegal(t_stk *stk)
{
	int	val;
	int	i;

	if (stk_isempty(stk) || stk->top < 1)
		return (false);
	i = stk->top;
	val = stk->stk[stk->top];
	while (i-- >= 0)
		stk->stk[i + 1] = stk->stk[i];
	stk->stk[0] = val;
	return (true);
}
