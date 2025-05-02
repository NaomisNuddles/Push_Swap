/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:22 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/02 20:02:07 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	stack_sort_unrev(t_stacks *data)
{
	while (!(!data->op_a->num && data->op_b->num == -1) || data->op_a->num < 0)
	{
		get_wemap(data);
		build_wemap(data);
		get_ops(data);
		if (!do_ops(data))
			return (error_log("Er09"), false);
		write_ops(data);
	}
	return (true);
}

static bool	stack_sort(t_stacks *data)
{
	data->op_a->num = stk_oop_num(data->a);
	if (!data->op_a->num)
		return (error_log("Er01"), false);
	else if (data->op_a->num == -1)
		return (error_log("Er07"), false);
	if (stk_issorted_rev(data->a))
	{
		while (data->op_a->num || data->op_a->num < 0)
		{
			data->do_a = LOOP;
			get_ops(data);
			if (!do_ops(data))
				return (error_log("Er09"), false);
			write_ops(data);
		}
	}
	else
	{
		if (!stack_sort_unrev(data))
			return (false);
	}
	if (!stk_issorted(data->a))
		return (error_log("Er11"), false);
	return (true);
}

int	main(int cnt, char **args)
{
	t_stacks	*data;

	data = set_stacks();
	if (data && cnt > 1)
	{
		if (!ft_strncmp(args[1], "error", 5))
			return (error_log("Er00"), free_stacks(data), 0);
		if (!args_pick(cnt, args, data->a))
			return (free_stacks(data), 0);
		stack_sort(data);
	}
	else if (!data)
		error_log("Er03");
	else
		error_log("Er02");
	return (free_stacks(data), 0);
}
