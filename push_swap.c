/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:22 by nleandro          #+#    #+#             */
/*   Updated: 2025/05/08 15:51:57 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	stack_sort(t_stacks *data)
{
	data->op_a->val = stk_sendfront_num(data->a);
	if (!data->op_a->val)
		return (error_log("Er01"), false);
	else if (data->op_a->val == -1)
		return (error_log("Er07"), false);
	while (!(!data->op_a->val && data->op_b->val == -1) || data->op_a->val < 0)
	{
		get_wemap(data);
		build_wemap(data);
		get_ops(data);
		if (!do_ops(data))
			return (error_log("Er08"), false);
		write_ops(data);
	}
	if (!stk_issort(data->a))
		return (error_log("Er09"), false);
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
