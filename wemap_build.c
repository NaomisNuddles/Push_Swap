/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/08 16:39:03 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	weight_val(int val, int n_val, int pen, int n_pen)
{
	if ((val > n_val && !n_val) || (!n_pen))
		return (16);
	else if (val > n_val && pen < n_pen && pen != 0)
		return (8);
	else if ((val > n_val && pen == n_pen) || (val > n_val && pen < n_pen))
		return (4);
	else if ((val == n_val && pen < n_pen) || (val > n_val && pen > n_pen))
		return (2);
	else if (val == n_val && pen == n_pen)
		return (1);
	return (0);
}

static int	get_a_weight(t_stacks *data, t_rules type, t_rules rev)
{
	int	weight;

	data->do_a = type;
	do_ops(data);
	data->do_a = rev;
	if (type != PUSH)
		weight = weight_val(data->op_a->val, stk_sendfront_num(data->a), \
		data->op_a->pen, stk_sendback_rev_num(data->a));
	else
	{
		weight = weight_val(data->op_a->val, stk_sendfront_num(data->a), \
		data->op_a->pen, stk_sendback_rev_num(data->a));
		data->do_a = NOOP;
		data->do_b = rev;
	}
	do_ops(data);
	data->do_a = NOOP;
	data->do_b = NOOP;
	return (weight);
}

static int	get_b_weight(t_stacks *data, t_rules type, t_rules rev)
{
	int	weight;

	data->do_b = type;
	do_ops(data);
	data->do_b = rev;
	if (type != PUSH)
		weight = weight_val(data->op_b->val, stk_sendfront_num(data->b), \
		data->op_b->pen, stk_sendback_rev_num(data->b));
	else
	{
		weight = weight_val(data->op_b->val, stk_sendfront_num(data->b), \
		data->op_b->pen, stk_sendback_rev_num(data->b));
		data->do_b = NOOP;
		data->do_a = rev;
	}
	do_ops(data);
	data->do_a = NOOP;
	data->do_b = NOOP;
	return (weight);
}

void	build_wemap(t_stacks *data)
{
	if (data->op_a->sx != -1)
		data->op_a->sx = get_a_weight(data, SWAP, SWAP);
	if (data->op_a->rx != -1)
		data->op_a->rx = get_a_weight(data, DUMB, LOOP);
	if (data->op_a->rrx != -1)
		data->op_a->rrx = get_a_weight(data, LOOP, DUMB);
	if (data->op_a->px != -1)
		data->op_a->px = get_a_weight(data, PUSH, PUSH);
	if (data->op_b->sx != -1)
		data->op_b->sx = get_b_weight(data, SWAP, SWAP);
	if (data->op_b->rx != -1)
		data->op_b->rx = get_b_weight(data, DUMB, LOOP);
	if (data->op_b->rrx != -1)
		data->op_b->rrx = get_b_weight(data, LOOP, DUMB);
	if (data->op_b->px != -1 && data->op_b->px != 32)
		data->op_b->px = get_b_weight(data, PUSH, PUSH);
}
