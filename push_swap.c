/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:22 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/04 17:25:13 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int cnt, char **args)
{
	t_stacks	*data;

	data = set_stacks();
	if (data && cnt > 1)
	{
		if (!ft_strncmp(args[1], "error", 5))
		{
			ft_printf("Errors:\n%s", ERRORS);
			return (free_stacks(data), 0);
		}
		if (!args_pick(cnt, args, data->a))
			return (free_stacks(data), 0);
		data->oop = stk_ordered(data->a);
		if (!data->oop)
			return (error_log("Er01"), free_stacks(data), 0);
		else if (data->oop == 1)
			ft_printf("oof: %i\n\n", stk_ordered(data->a));
		else
			ft_printf("foo: %i\n\n", stk_ordered(data->a));
	}
	else if (!data)
		error_log("Er03");
	else
		error_log("Er02");
	return (free_stacks(data), 0);
}
