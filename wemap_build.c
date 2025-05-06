/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wemap_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/06 16:14:51 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	weight_val(int num, int n_num)
{
	if (num > n_num && !n_num)
		return (8);
	else if (num > n_num)
		return (4);
	else if (num == n_num)
		return (2);
	return (0);
}

static int	get_push_cost(t_stacks *data, char stk)
{
	int	weight;

	if (stk == 97)
		data->do_a = PUSH;
	else
		data->do_b = PUSH;
	do_ops(data);
	if (stk == 97)
		weight = weight_val(data->op_a->num, stk_sendback_num(data->a)) - \
		weight_val(data->op_b->num, stk_sendback_num(data->b));
	else
		weight = weight_val(data->op_a->num, stk_sendback_num(data->a)) + \
		weight_val(data->op_b->num, stk_sendback_num(data->b));
	data->do_a = NOOP;
	data->do_b = NOOP;
	if (stk == 97)
		data->do_b = PUSH;
	else
		data->do_a = PUSH;
	do_ops(data);
	data->do_a = NOOP;
	data->do_b = NOOP;
	return (weight);
}

static int	get_cost(t_stacks *data, t_rules type, t_rules rev, char stk)
{
	int	weight;

	if (stk == 97)
	{
		data->do_a = type;
		do_ops(data);
		weight = weight_val(data->op_a->num, stk_sendback_num(data->a));
		data->do_a = rev;
		do_ops(data);
		data->do_a = NOOP;
	}
	else
	{
		data->do_b = type;
		do_ops(data);
		weight = weight_val(data->op_b->num, stk_sendback_num(data->b));
		data->do_b = rev;
		do_ops(data);
		data->do_b = NOOP;
	}
	return (weight);
}

void	build_wemap(t_stacks *data)
{
	if (data->op_a->sx != -1)
		data->op_a->sx = get_cost(data, SWAP, SWAP, 97);
	if (data->op_a->rx != -1)
		data->op_a->rx = get_cost(data, DUMB, LOOP, 97);
	if (data->op_a->rrx != -1)
		data->op_a->rrx = get_cost(data, LOOP, DUMB, 97);
	if (data->op_a->px != -1)
		data->op_a->px = get_push_cost(data, 97);
	if (data->op_b->sx != -1)
		data->op_b->sx = get_cost(data, SWAP, SWAP, 98);
	if (data->op_b->rx != -1)
		data->op_b->rx = get_cost(data, DUMB, LOOP, 98);
	if (data->op_b->rrx != -1)
		data->op_b->rrx = get_cost(data, LOOP, DUMB, 98);
	if (data->op_b->px != -1)
		data->op_b->px = get_push_cost(data, 98);
}
