/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:51:22 by nleandro          #+#    #+#             */
/*   Updated: 2025/02/01 21:55:07 by nleandro         ###   ########.fr       */
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
	}
	else if (!data)
		error_log("Er03");
	else
		error_log("Er02");
	return (free_stacks(data), 0);
}
