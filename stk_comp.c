/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:29:53 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/03 09:32:55 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_poke(t_stk *stk, int num)
{
	int	i;

	i = stk->top;
	while (i >= 0)
	{
		if (stk->stk[i] == num)
			break ;
		i--;
	}
	return (i);
}

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

bool	stk_issorted_rev(t_stk *stk)
{
	int	i;

	i = 0;
	while (i < stk->top)
	{
		if (stk->stk[i] > stk->stk[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	stk_oop_num(t_stk *stk)
{
	int	min;
	int	n_min;
	int	at_sep;

	at_sep = 1;
	min = stk_min(stk);
	while (at_sep <= stk->top)
	{
		n_min = stk_next_min(stk, min);
		if (stk_poke(stk, min) < stk_poke(stk, n_min))
			break ;
		min = n_min;
		at_sep++;
	}
	if (at_sep == stk->top + 1)
		return (0);
	return (stk->top + 1 - at_sep);
}
