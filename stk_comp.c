/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:29:53 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/06 16:42:58 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stk_issort(t_stk *stk)
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

int	stk_sendback_num(t_stk *stk)
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

int	stk_sendfront_num(t_stk *stk)
{
	int	max;
	int	n_max;
	int	at_sep;

	at_sep = stk->top;
	max = stk_max(stk);
	while (at_sep >= 0)
	{
		n_max = stk_next_max(stk, max);
		if (stk_poke(stk, max) < stk_poke(stk, n_max))
			break ;
		max = n_max;
		at_sep--;
	}
	if (at_sep == -1)
		return (0);
	return (stk->top - at_sep);
}
