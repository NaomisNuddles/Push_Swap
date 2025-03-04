/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:29:53 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/04 17:14:04 by nleandro         ###   ########.fr       */
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

int	stk_min(t_stk *stk)
{
	int	i;
	int	j;

	i = stk->top;
	j = i - 1;
	while (j >= 0)
	{
		if (stk->stk[i] > stk->stk[j])
			i = j;
		j--;
	}
	return (stk->stk[i]);
}

int	stk_next_min(t_stk *stk, int p_min)
{
	int	i;
	int	j;

	i = stk->top;
	j = i - 1;
	while (j >= 0)
	{
		if ((stk->stk[i] > stk->stk[j] && stk->stk[j] > p_min) \
		|| stk->stk[i] <= p_min)
			i = j;
		j--;
	}
	return (stk->stk[i]);
}

int	stk_max(t_stk *stk)
{
	int	i;
	int	j;

	i = stk->top;
	j = i - 1;
	while (j >= 0)
	{
		if (stk->stk[i] < stk->stk[j])
			i = j;
		j--;
	}
	return (stk->stk[i]);
}

int	stk_next_max(t_stk *stk, int p_max)
{
	int	i;
	int	j;

	i = stk->top;
	j = i - 1;
	while (j >= 0)
	{
		if ((stk->stk[i] < stk->stk[j] && stk->stk[j] < p_max) \
		|| stk->stk[i] >= p_max)
			i = j;
		j--;
	}
	return (stk->stk[i]);
}
