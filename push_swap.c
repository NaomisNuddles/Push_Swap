/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:22 by nleandro          #+#    #+#             */
/*   Updated: 2025/03/28 18:06:44 by nleandro         ###   ########.fr       */
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
			return (error_log("Er00"), free_stacks(data), 0);
		if (!args_pick(cnt, args, data->a))
			return (free_stacks(data), 0);
		if (!sorter_check(data))
			return (error_log("Er08"), free_stacks(data), 0);
	}
	else if (!data)
		error_log("Er03");
	else
		error_log("Er02");
	return (free_stacks(data), 0);
}
