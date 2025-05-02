/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_aux_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:51:10 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/31 18:30:55 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_ordered(t_stk *stk)
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



bool	sorter_check(t_stacks *data)
{
	data->at_wrg = stk_ordered(data->a);
	if (!data->at_wrg)
		return (error_log("Er01"), true);
	else if (data->at_wrg == -1)
		return (error_log("Er07"), true);
	
	ft_printf("at_wrg: %i\n\n", stk_ordered(data->a));
	if (!stk_issorted(data->a))
		return (error_log("Er11"), true);
	return (false);
}
