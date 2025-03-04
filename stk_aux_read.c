/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_aux_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:51:10 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/04 17:22:10 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_ordered(t_stk *stk)
{
	int	min;
	int	n_min;
	int	ord;

	ord = 1;
	min = stk_min(stk);
	while (ord <= stk->top)
	{
		n_min = stk_next_min(stk, min);
		if (stk_poke(stk, min) < stk_poke(stk, n_min))
			break ;
		min = n_min;
		ord++;
	}
	if (ord == stk->top + 1)
		return (0);
	return (stk->top + 1 - ord);
}
