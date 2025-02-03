/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_aux_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/03 16:51:08 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stk_isempty(t_stk *stk)
{
	if (stk->top == -1)
		return (true);
	return (false);
}

bool	stk_isfull(t_stk *stk)
{
	if (stk->top == MAX_STACK_SIZE - 1)
		return (true);
	return (false);
}

void	stk_push(t_stk *stk, int val)
{
	if (!stk_isfull(stk))
		stk->stk[++stk->top] = val;
}

int	stk_pop(t_stk *stk)
{
	int	val;

	if (!stk_isempty(stk))
		return (0);
	val = stk->stk[stk->top--];
	return (val);
}

int	stk_pop_zed(t_stk *stk)
{
	int	val;
	int	i;

	if (!stk_isempty(stk))
		return (0);
	i = 0;
	val = stk->stk[0];
	while (i++ < stk->top)
		stk->stk[i - 1] = stk->stk[i];
	stk->top--;
	return (val);
}
