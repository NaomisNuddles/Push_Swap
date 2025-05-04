/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/04 12:22:03 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_both(t_stacks *data)
{
	if (data->do_a == SWAP)
	{
		if (data->op_a->sx == data->op_b->sx)
			data->do_b = SWAP;
	}
	else if (data->do_a == DUMB)
	{
		if (data->op_a->rx == data->op_b->rx)
			data->do_b = DUMB;
	}
	else if (data->do_a == LOOP)
	{
		if (data->op_a->rrx == data->op_b->rrx)
			data->do_b = LOOP;
	}
}

static void	get_a_ops(t_stacks *data)
{
	if (data->op_a->px == 8)
		data->do_a = PUSH;
	else if (data->op_a->sx == 8 || (data->op_a->sx == 4 && \
		data->op_a->sx >= data->op_a->rx && data->op_a->sx >= data->op_a->rrx \
		&& data->op_a->sx >= data->op_a->px) || (data->op_a->sx == 2 && \
		data->op_a->sx > data->op_a->rx && data->op_a->sx > data->op_a->rrx && \
		data->op_a->sx > data->op_a->px))
		data->do_a = SWAP;
	else if (data->op_a->rx == 8 || (data->op_a->rx == 4 && \
		data->op_a->rx >= data->op_a->rrx && data->op_a->rx >= data->op_a->px) \
		|| (data->op_a->rx == 2 && data->op_a->rx > data->op_a->rrx && \
		data->op_a->rx > data->op_a->px))
		data->do_a = DUMB;
	else if (data->op_a->rrx == 8 || (data->op_a->rrx == 4 && \
		data->op_a->rrx >= data->op_a->px) || (data->op_a->rrx == 2 && \
		data->op_a->rx > data->op_a->px))
		data->do_a = LOOP;
	else
		data->do_a = PUSH;
}

static void	get_b_ops(t_stacks *data)
{
	if (data->op_b->sx == 8 || (data->op_b->sx == 4 && \
		data->op_b->sx >= data->op_b->rx && data->op_b->sx >= data->op_b->rrx \
		&& data->op_b->sx >= data->op_b->px) || (data->op_b->sx == 2 && \
		data->op_b->sx > data->op_b->rx && data->op_b->sx > data->op_b->rrx && \
		data->op_b->sx > data->op_b->px))
		data->do_b = SWAP;
	else if (data->op_b->rx == 8 || (data->op_b->rx == 4 && \
		data->op_b->rx >= data->op_b->rrx && data->op_b->rx >= data->op_b->px) \
		|| (data->op_b->rx == 2 && data->op_b->rx > data->op_b->rrx && \
		data->op_b->rx > data->op_b->px))
		data->do_b = DUMB;
	else if (data->op_b->rrx == 8 || (data->op_b->rrx == 4 && \
		data->op_b->rrx >= data->op_b->px) || (data->op_b->rrx == 2 && \
		data->op_b->rx > data->op_b->px))
		data->do_b = LOOP;
	else
		data->do_b = PUSH;
}

void	get_ops(t_stacks *data)
{
	if (data->op_a->num > 0)
	{
		get_a_ops(data);
		get_both(data);
	}
	else
		get_b_ops(data);
}
