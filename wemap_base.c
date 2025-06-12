/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/08 15:55:13 by nleandro         ###   ########.fr       */
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
	data->op_a->val = stk_sendfront_num(data->a);
	data->op_a->pen = stk_sendback_rev_num(data->a);
	data->op_a->sx = 0;
	data->op_a->rx = 0;
	data->op_a->rrx = 0;
	data->op_a->px = 0;
	data->op_b->val = stk_sendfront_num(data->b);
	data->op_b->pen = stk_sendback_rev_num(data->b);
	data->op_b->sx = 0;
	data->op_b->rx = 0;
	data->op_b->rrx = 0;
	data->op_b->px = 0;
}

void	get_wemap(t_stacks *data)
{
	clean_wemap(data);
	lock_reverse(data);
	data->do_a = NOOP;
	data->do_b = NOOP;
	if (data->b->top <= 1)
		lock_ops(data, SEMI_B);
	if (data->op_a->val == 0 && data->op_b->val == 0)
	{
		lock_ops(data, ALL_A);
		lock_ops(data, ALL_B);
		data->op_b->px = 32;
	}
	else if (data->op_a->val == 0 && data->op_b->val > 0)
		lock_ops(data, ALL_A);
	else if (data->op_a->val > 0 && data->op_b->val == -1)
		lock_ops(data, ALL_B);
	else if (data->op_a->val > 0 && data->op_b->val == 0)
		lock_ops(data, SEMI_B);
	else if (data->op_a->val > 0 && data->op_b->val > 0)
		clean_wemap(data);
}
