/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/06 16:05:18 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lock_both(t_stacks *data)
{
	if (data->do_a == SWAP)
	{
		data->op_a->sx = -1;
		data->op_b->sx = -1;
	}
	else if (data->do_a == DUMB)
	{
		data->op_a->rrx = -1;
		data->op_b->rrx = -1;
	}
	else if (data->do_a == LOOP)
	{
		data->op_a->rx = -1;
		data->op_b->rx = -1;
	}
}

static void	lock_reverse(t_stacks *data)
{
	if (data->do_a == data->do_b && data->do_a != NOOP)
		lock_both(data);
	else if (data->do_a != NOOP)
	{
		if (data->do_a == SWAP)
			data->op_a->sx = -1;
		else if (data->do_a == DUMB)
			data->op_a->rrx = -1;
		else if (data->do_a == LOOP)
			data->op_a->rx = -1;
		else
			data->op_b->px = -1;
	}
	else if (data->do_b != NOOP)
	{
		if (data->do_b == SWAP)
			data->op_b->sx = -1;
		else if (data->do_b == DUMB)
			data->op_b->rrx = -1;
		else if (data->do_b == LOOP)
			data->op_b->rx = -1;
		else
			data->op_a->px = -1;
	}
}

static void	lock_ops(t_stacks *data, t_lock path)
{
	if (path == ALL_A)
	{
		data->op_a->sx = -1;
		data->op_a->rx = -1;
		data->op_a->rrx = -1;
		data->op_a->px = -1;
	}
	else if (path == ALL_B)
	{
		data->op_b->sx = -1;
		data->op_b->rx = -1;
		data->op_b->rrx = -1;
		data->op_b->px = -1;
	}
	else if (path == SEMI_B)
	{
		data->op_b->sx = -1;
		data->op_b->rx = -1;
		data->op_b->rrx = -1;
	}
}

void	clean_wemap(t_stacks *data)
{
	data->op_a->num = stk_sendback_num(data->a);
	data->op_a->sx = 0;
	data->op_a->rx = 0;
	data->op_a->rrx = 0;
	data->op_a->px = 0;
	data->op_b->num = stk_sendback_num(data->b);
	data->op_b->sx = 0;
	data->op_b->rx = 0;
	data->op_b->rrx = 0;
	data->op_b->px = 0;
}

void	get_wemap(t_stacks *data)
{
	clean_wemap(data);
	if (data->op_a->num == 0 && data->op_b->num == 0)
		data->do_b = PUSH;
	else if (data->op_a->num == 0 && data->op_b->num > 0)
		lock_ops(data, ALL_A);
	else if (data->op_a->num > 0 && data->op_b->num == -1)
		lock_ops(data, ALL_B);
	else if (data->op_a->num > 0 && data->op_b->num == 0)
		lock_ops(data, SEMI_B);
	else if (data->op_a->num > 0 && data->op_b->num > 0)
		clean_wemap(data);
	else
		return ;
	if (data->b->top <= 1)
		lock_ops(data, SEMI_B);
	lock_reverse(data);
	data->do_a = NOOP;
	data->do_b = NOOP;
}
