/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_aux_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:00:03 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/01 16:31:00 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*set_stacks(void)
{
	t_stacks	*data;
	
	data = malloc(sizeof(t_stacks));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stk));
	if (!data->a)
		return (free(data), NULL);
	data->b = malloc(sizeof(t_stk));
	if (!data->b)
		return (free(data->a), free(data), NULL);
	data->a->top = -1;
	data->b->top = -1;
	data->do_a = false;
	data->do_b = false;
	return (data);
}

void	free_stacks(t_stacks *data)
{
	if (data)
	{
		free(data->a);
		free(data->b);
		free(data);
	}
	else
		ft_printf("Er03\n");
}
