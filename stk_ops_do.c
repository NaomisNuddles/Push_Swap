/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/04 12:41:22 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_both(t_stacks *data)
{
	if (data->do_a == data->do_b && data->do_a == SWAP)
	{
		ft_stk_swap(data->a);
		ft_stk_swap(data->b);
	}
	else if (data->do_a == data->do_b && data->do_a == DUMB)
	{
		ft_stk_illegal(data->a);
		ft_stk_illegal(data->b);
	}
	else if (data->do_a == data->do_b && data->do_a == LOOP)
	{
		ft_stk_cycle(data->a);
		ft_stk_cycle(data->b);
	}
}

static void	do_one_a(t_stacks *data)
{
	if (data->do_a == SWAP)
		ft_stk_swap(data->a);
	else if (data->do_a == DUMB)
		ft_stk_illegal(data->a);
	else if (data->do_a == LOOP)
		ft_stk_cycle(data->a);
	else if (data->do_a == PUSH)
		ft_stk_push(data->a, data->b);
}

static void	do_one_b(t_stacks *data)
{
	if (data->do_b == SWAP)
		ft_stk_swap(data->b);
	else if (data->do_b == DUMB)
		ft_stk_illegal(data->b);
	else if (data->do_b == LOOP)
		ft_stk_cycle(data->b);
	else if (data->do_b == PUSH)
		ft_stk_push(data->b, data->a);
}

bool	do_ops(t_stacks *data)
{
	if (data->do_a == data->do_b && data->do_a != NOOP)
		do_both(data);
	else if (data->do_b == NOOP)
		do_one_a(data);
	else if (data->do_a == NOOP)
		do_one_b(data);
	else
		return (false);
	return (true);
}

void	write_ops(t_stacks *data)
{
	if (data->do_a == data->do_b && data->do_a == SWAP)
		ft_printf("ss\n");
	else if (data->do_a == data->do_b && data->do_a == DUMB)
		ft_printf("rrr\n");
	else if (data->do_a == data->do_b && data->do_a == LOOP)
		ft_printf("rrr\n");
	else if (data->do_a == SWAP)
		ft_printf("sa\n");
	else if (data->do_a == DUMB)
		ft_printf("ra\n");
	else if (data->do_a == LOOP)
		ft_printf("rra\n");
	else if (data->do_a == PUSH)
		ft_printf("pb\n");
	else if (data->do_b == SWAP)
		ft_printf("sb\n");
	else if (data->do_b == DUMB)
		ft_printf("rb\n");
	else if (data->do_b == LOOP)
		ft_printf("rrb\n");
	else if (data->do_b == PUSH)
		ft_printf("pa\n");
	clean_wemap(data);
}
