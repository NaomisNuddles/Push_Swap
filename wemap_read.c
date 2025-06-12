/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/08 16:37:49 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_both(t_stacks *data)
{
	if (data->do_a == SWAP && data->op_a->sx <= data->op_b->sx)
		data->do_b = SWAP;
	else if (data->do_a == DUMB && data->op_a->rx <= data->op_b->rx)
		data->do_b = DUMB;
	else if (data->do_a == LOOP && data->op_a->rrx <= data->op_b->rrx)
		data->do_b = LOOP;
	else if (data->do_b == SWAP && data->op_b->sx <= data->op_a->sx)
		data->do_a = SWAP;
	else if (data->do_b == DUMB && data->op_b->rx <= data->op_a->rx)
		data->do_a = DUMB;
	else if (data->do_b == LOOP && data->op_b->rrx <= data->op_a->rrx)
		data->do_a = LOOP;
}

static void	get_a_ops(t_stacks *data)
{
	if (data->op_a->rrx > data->op_a->sx && data->op_a->rrx > data->op_a->rx \
		&& data->op_a->rrx > data->op_a->px && data->op_a->rrx > data->op_b->px)
		data->do_a = LOOP;
	else if (data->op_a->rx > data->op_a->rrx && \
		data->op_a->rx > data->op_a->px && data->op_a->rx > data->op_b->px)
		data->do_a = DUMB;
	else if (data->op_a->sx > data->op_a->px && \
		data->op_a->sx >= data->op_b->px)
		data->do_a = SWAP;
	else if (data->op_b->px > data->op_a->px)
		data->do_b = PUSH;
	else
		data->do_a = PUSH;
}

static void	get_b_ops(t_stacks *data)
{
	if (data->op_b->rrx > data->op_b->sx && data->op_b->rrx > data->op_b->rx \
		&& data->op_b->rrx > data->op_b->px)
		data->do_b = LOOP;
	else if (data->op_b->rx > data->op_b->rrx && \
		data->op_b->rx > data->op_b->px)
		data->do_b = DUMB;
	else if (data->op_b->sx > data->op_b->px)
		data->do_b = SWAP;
	else
		data->do_b = PUSH;
}

void	get_ops(t_stacks *data)
{
	if (data->op_a->sx == 16)
		data->do_a = SWAP;
	else if (data->op_a->rx == 16)
		data->do_a = DUMB;
	else if (data->op_a->rrx == 16)
		data->do_a = LOOP;
	else if (data->op_b->sx == 16)
		data->do_b = SWAP;
	else if (data->op_b->rx == 16)
		data->do_b = DUMB;
	else if (data->op_b->rrx == 16)
		data->do_b = LOOP;
	else if (data->op_b->px == 32)
		data->do_b = PUSH;
	else
	{
		if (data->op_a->val > 0)
			get_a_ops(data);
		else
			get_b_ops(data);
	}
	get_both(data);
}
