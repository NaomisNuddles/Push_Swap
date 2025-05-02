/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/02 20:07:02 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_a_ops(t_stacks *data)
{
	if ((data->op_a->sx > data->op_a->rx && data->op_a->sx > data->op_a->rrx \
		&& data->op_a->sx > data->op_a->px) || data->op_a->sx == 8)
	{
		data->do_a = SWAP;
		if (data->op_a->sx == data->op_b->sx)
			data->do_b = SWAP;
	}
	else if ((data->op_a->rx > data->op_a->sx && data->op_a->rx > \
		data->op_a->rrx && data->op_a->rx > data->op_a->px) || \
		data->op_a->rx == 8)
	{
		data->do_a = DUMB;
		if (data->op_a->rx == data->op_b->rx)
			data->do_b = DUMB;
	}
	else if ((data->op_a->rrx > data->op_a->sx && data->op_a->rrx > \
		data->op_a->rx && data->op_a->rrx > data->op_a->px) || \
		data->op_a->rrx == 8)
	{
		data->do_a = LOOP;
		if (data->op_a->rrx == data->op_b->rrx)
			data->do_b = LOOP;
	}
	else
		data->do_a = PUSH;
}

void	get_ops(t_stacks *data)
{
	if (data->op_a->num > 0)
		get_a_ops(data);
	else
	{
		if ((data->op_b->sx > data->op_b->rx && data->op_b->sx > \
			data->op_b->rrx && data->op_b->sx > data->op_b->px) || \
			data->op_b->sx == 8)
			data->do_b = SWAP;
		else if ((data->op_b->rx > data->op_b->sx && data->op_b->rx > \
			data->op_b->rrx && data->op_b->rx > data->op_b->px) || \
			data->op_b->rx == 8)
			data->do_b = DUMB;
		else if ((data->op_b->rrx > data->op_b->sx && data->op_b->rrx > \
			data->op_b->rx && data->op_b->rrx > data->op_b->px) || \
			data->op_b->rrx == 8)
			data->do_b = LOOP;
		else
			data->do_b = PUSH;
	}
	
}
